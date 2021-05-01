# **OpenEmu Notes**

## Building .dylib

### arcade (MAME)

#### release build with make:

```sh
$ make macosx_x64_clang OSD="headless" verbose=1 TARGETOS="macosx" CONFIG="release" TARGET=mame SUBTARGET=arcade MACOSX_DEPLOYMENT_TARGET=10.14 -j8
```

#### release build with ccache and distcc

The summary of steps are **generate CMake** → **generate Ninja** → **build** as
ccache and distcc did not work with the GNU make output.

**NOTE:** Needs official build of genie to generate working CMake project

1. Generate a CMake project using official build of genie (for correct CMake output)

    ```sh
    make cmake GENIE=~/projects/c/genie/bin/darwin/genie OSD="headless" PRECOMPILE=0 verbose=1 TARGETOS="macosx" CONFIG="release" TARGET=mame SUBTARGET=arcade MACOSX_DEPLOYMENT_TARGET=10.14 NOWERROR=1 NO_USE_MIDI=1 DONT_USE_NETWORK=1 NO_USE_PORTAUDIO=1
    ```

2. Generate a ninja project from the CMake output, using ccache as the compiler launcher

    ```sh
    cmake -B build/output -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER_LAUNCHER=ccache
    ```

3. Finally, build the ninja project using `distcc`

    ```sh
    CCACHE_PREFIX=distcc ninja -C build/output mamearcade_headless -j`distcc -j`
    ```

### mess (consoles)

### dummy (ColecoVision) (with ccache):

```sh
make macosx_x64_clang CC='/usr/local/bin/ccache clang' CXX='/usr/local/bin/ccache clang++' OSD="headless" PRECOMPILE=0 OPTIMIZE=0 verbose=1 TARGETOS="macosx" CONFIG="headless-dbg" TARGET=mame SUBTARGET=dummy MACOSX_DEPLOYMENT_TARGET=10.14 -j6
```

`OPTIMIZE=0` ensures -O0


## Generating CMake for CLion:

**NOTE:** Needs official build of genie to generate working CMake project

```sh
make cmake GENIE=~/projects/c/genie/bin/darwin/genie OSD="headless" PRECOMPILE=0 verbose=1 TARGETOS="macosx" CONFIG="Release" TARGET=mame SUBTARGET=tiny MACOSX_DEPLOYMENT_TARGET=10.14 NOWERROR=1 NO_USE_MIDI=1 DONT_USE_NETWORK=1 NO_USE_PORTAUDIO=1 OPTIMIZE=0
```

--------

# **MAME** #

[![Join the chat at https://gitter.im/mamedev/mame](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/mamedev/mame?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

Build status:

| OS/Compiler   | Status        |
| ------------- |:-------------:|
| Linux/GCC and Clang | ![CI (Linux)](https://github.com/mamedev/mame/workflows/CI%20(Linux)/badge.svg) [![Build Status](https://travis-ci.org/mamedev/mame.svg?branch=master)](https://travis-ci.org/mamedev/mame) |
| Windows/GCC and MSVC | ![CI (Windows)](https://github.com/mamedev/mame/workflows/CI%20(Windows)/badge.svg) |
| macOS/Clang | ![CI (macOS)](https://github.com/mamedev/mame/workflows/CI%20(macOS)/badge.svg) |

Static analysis status for entire build (except for third-party parts of project):

[![Coverity Scan Status](https://scan.coverity.com/projects/5727/badge.svg?flat=1)](https://scan.coverity.com/projects/mame-emulator)

What is MAME?
=============

MAME is a multi-purpose emulation framework.

MAME's purpose is to preserve decades of software history. As electronic technology continues to rush forward, MAME prevents this important "vintage" software from being lost and forgotten. This is achieved by documenting the hardware and how it functions. The source code to MAME serves as this documentation. The fact that the software is usable serves primarily to validate the accuracy of the documentation (how else can you prove that you have recreated the hardware faithfully?). Over time, MAME (originally stood for Multiple Arcade Machine Emulator) absorbed the sister-project MESS (Multi Emulator Super System), so MAME now documents a wide variety of (mostly vintage) computers, video game consoles and calculators, in addition to the arcade video games that were its initial focus.

How to compile?
===============

If you're on a *NIX or OSX system, it could be as easy as typing

```
make
```

for a MAME build,

```
make SUBTARGET=arcade
```

for an arcade-only build, or

```
make SUBTARGET=mess
```

for MESS build.

See the [Compiling MAME](http://docs.mamedev.org/initialsetup/compilingmame.html) page on our documentation site for more information, including prerequisites for Mac OS X and popular Linux distributions.

For recent versions of OSX you need to install [Xcode](https://developer.apple.com/xcode/) including command-line tools and [SDL 2.0](https://www.libsdl.org/download-2.0.php).

For Windows users, we provide a ready-made [build environment](http://mamedev.org/tools/) based on MinGW-w64.

Visual Studio builds are also possible, but you still need [build environment](http://mamedev.org/tools/) based on MinGW-w64.
In order to generate solution and project files just run:

```
make vs2019
```
or use this command to build it directly using msbuild

```
make vs2019 MSBUILD=1
```


Where can I find out more?
=============

* [Official MAME Development Team Site](http://mamedev.org/) (includes binary downloads, wiki, forums, and more)
* [Official MESS Wiki](http://mess.redump.net/)
* [MAME Testers](http://mametesters.org/) (official bug tracker for MAME and MESS)


Contributing
=============

## Coding standard

MAME source code should be viewed and edited with your editor set to use four spaces per tab. Tabs are used for initial indentation of lines, with one tab used per indentation level. Spaces are used for other alignment within a line.

Some parts of the code follow [Allman style](https://en.wikipedia.org/wiki/Indent_style#Allman_style); some parts of the code follow [K&R style](https://en.wikipedia.org/wiki/Indent_style#K.26R_style) -- mostly depending on who wrote the original version. **Above all else, be consistent with what you modify, and keep whitespace changes to a minimum when modifying existing source.** For new code, the majority tends to prefer Allman style, so if you don't care much, use that.

All contributors need to either add a standard header for license info (on new files) or inform us of their wishes regarding which of the following licenses they would like their code to be made available under: the [BSD-3-Clause](http://opensource.org/licenses/BSD-3-Clause) license, the [LGPL-2.1](http://opensource.org/licenses/LGPL-2.1), or the [GPL-2.0](http://opensource.org/licenses/GPL-2.0).

License
=======
The MAME project as a whole is made available under the terms of the
[GNU General Public License, version 2](http://opensource.org/licenses/GPL-2.0)
or later (GPL-2.0+), since it contains code made available under multiple
GPL-compatible licenses.  A great majority of the source files (over 90%
including core files) are made available under the terms of the
[3-clause BSD License](http://opensource.org/licenses/BSD-3-Clause), and we
would encourage new contributors to make their contributions available under the
terms of this license.

Please note that MAME is a registered trademark of Gregory Ember, and permission
is required to use the "MAME" name, logo, or wordmark.

<a href="http://opensource.org/licenses/GPL-2.0" target="_blank">
<img align="right" src="http://opensource.org/trademarks/opensource/OSI-Approved-License-100x137.png">
</a>

    Copyright (C) 1997-2021  MAMEDev and contributors

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License version 2, as provided in
    docs/legal/GPL-2.0.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
    more details.

Please see COPYING for more details.
