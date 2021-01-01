# **OpenEmu Notes**

## Building .dylib

### arcade (MAME)

#### release build:

```sh
$ make macosx_x64_clang OSD="headless" verbose=1 TARGETOS="macosx" CONFIG="headless-rel" TARGET=mame SUBTARGET=arcade -j8
```

#### release build (with ccache):

```sh
$ make macosx_x64_clang CC='/usr/local/bin/ccache clang' CXX='/usr/local/bin/ccache clang++' OSD="headless" PRECOMPILE=0 verbose=1 TARGETOS="macosx" CONFIG="headless-rel" TARGET=mame SUBTARGET=arcade -j8
```

`PRECOMPILE=0` ensures precompiled headers are disabled, as ccache has limited compatibility with this feature.

### mess (consoles)

### dummy (ColecoVision) (with ccache):

```sh
make macosx_x64_clang CC='/usr/local/bin/ccache clang' CXX='/usr/local/bin/ccache clang++' OSD="headless" PRECOMPILE=0 OPTIMIZE=0 verbose=1 TARGETOS="macosx" CONFIG="headless-dbg" TARGET=mame SUBTARGET=dummy -j6
```

`OPTIMIZE=0` ensures -O0


## Generating CMake:

```sh
make cmake OSD="headless" verbose=1 TARGETOS="macosx" CONFIG="headless-dbg" TARGET=mame SUBTARGET=tiny -j8
```

CMakeLists:

```cmake
cmake_minimum_required(VERSION 3.14.1)
project(mametiny_headless)
set (CMAKE_CXX_STANDARD 14)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    SET_PROPERTY(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${CCACHE_FOUND})
    SET_PROPERTY(GLOBAL PROPERTY RULE_LAUNCH_LINK ${CCACHE_FOUND})
endif(CCACHE_FOUND)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -MMD -MP -MP -g -m64 -arch x86_64 -fobjc-arc")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -MMD -MP -MP -g -m64 -arch x86_64 -fobjc-arc")
add_subdirectory(src)
add_subdirectory(build/projects/headless/mametiny/cmake)
set_property (TARGET mametiny_headless APPEND_STRING PROPERTY COMPILE_FLAGS "-fobjc-arc")
```

mametiny/CMakeLists.txt:

```cmake
# CMake project autogenerated by GENie
cmake_minimum_required(VERSION 2.8.4)

project(mametiny)
set(
source_list
  ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../generated/mame/tiny/drivlist.cpp
  ../../../../../generated/version.cpp
  ../../../../../../src/mame/mame.cpp
  ../../../../../../src/osd/headless/headless.mm
  ../../../../../../src/osd/headless/driver.mm
  ../../../../../../src/osd/osdnet.cpp
  ../../../../../../src/osd/osdnet.h
)

include_directories(../../../../../../src/osd/headless)
include_directories(../../../../../../src/osd)
include_directories(../../../../../../src/emu)
include_directories(../../../../../../src/devices)
include_directories(../../../../../../src/mame)
include_directories(../../../../../../src/lib)
include_directories(../../../../../../src/lib/util)
include_directories(../../../../../../3rdparty)
include_directories(../../../../../generated/mame/layout)
include_directories(../../../../../generated/resource)
include_directories(../../../../../../3rdparty/zlib)
include_directories(../../../../../../3rdparty/libflac/include)
include_directories(../../../../../../src/osd/modules/render)
add_definitions(-DPTR64=1)
add_definitions(-DCRLF=2)
add_definitions(-DLSB_FIRST)
add_definitions(-DFLAC__NO_DLL)
add_definitions(-DPUGIXML_HEADER_ONLY)
add_definitions(-DNATIVE_DRC=drcbe_x64)
add_definitions(-DLUA_COMPAT_ALL)
add_definitions(-DLUA_COMPAT_5_1)
add_definitions(-DLUA_COMPAT_5_2)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
  add_definitions(-DMAME_DEBUG)
  add_definitions(-DMAME_PROFILER)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -MMD -MP -MP -g -m64 -arch x86_64")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -MMD -MP -MP -g -m64 -arch x86_64")
endif()

if(CMAKE_BUILD_TYPE MATCHES "Release")
  add_definitions(-DNDEBUG)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -MMD -MP -MP -g -m64 -arch x86_64")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -MMD -MP -MP -g -m64 -arch x86_64")
endif()

if(CMAKE_BUILD_TYPE MATCHES "headless-rel")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -MMD -MP -MP -O2 -g -m64 -fPIC -arch x86_64")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -MMD -MP -MP -O2 -g -m64 -fPIC -arch x86_64")
endif()

if(CMAKE_BUILD_TYPE MATCHES "headless-dbg")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -MMD -MP -MP -g -m64 -fPIC -arch x86_64")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -MMD -MP -MP -g -m64 -fPIC -arch x86_64")
endif()

file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../generated/resource")
file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../generated/mame/tiny")

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../generated/resource/tiny-Info.plist
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../generated/version.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../../scripts/build/verinfo.py
  COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../../scripts/build/verinfo.py   -p -b tiny ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../generated/version.cpp  > ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../generated/resource/tiny-Info.plist
  COMMENT "@echo Emitting tiny-Info.plist..."
)

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../generated/mame/tiny/drivlist.cpp
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../../src/mame/tiny.lst ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../../scripts/build/makelist.py
  COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../../scripts/build/makelist.py  ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../../src/mame/tiny.lst  > ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../generated/mame/tiny/drivlist.cpp
  COMMENT "@echo Building driver list..."
)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
  add_executable(mametiny64d ${source_list})
  target_link_libraries(mametiny64d mame_tiny frontend optional emu formats dasm utils expat softfloat softfloat3 jpeg 7z lua lualibs linenoise zlib flac utf8proc sqlite3 ocore_headless -lm -lpthread -lutil)
endif()

if(CMAKE_BUILD_TYPE MATCHES "Release")
  add_executable(mametiny64 ${source_list})
  target_link_libraries(mametiny64 mame_tiny frontend optional emu formats dasm utils expat softfloat softfloat3 jpeg 7z lua lualibs linenoise zlib flac utf8proc sqlite3 ocore_headless -lm -lpthread -lutil)
endif()

if(CMAKE_BUILD_TYPE MATCHES "headless-rel")
  add_library(mametiny_headless SHARED ${source_list})
  target_link_libraries(mametiny_headless mame_tiny frontend optional emu formats dasm utils expat softfloat softfloat3 jpeg 7z lua lualibs linenoise zlib flac utf8proc sqlite3 ocore_headless -lm -lpthread -lutil)
endif()

if(CMAKE_BUILD_TYPE MATCHES "headless-dbg")
  add_library(mametiny_headless SHARED ${source_list})
  target_link_libraries(mametiny_headless mame_tiny frontend optional emu formats dasm utils expat softfloat softfloat3 jpeg 7z lua lualibs linenoise zlib flac utf8proc sqlite3 ocore_headless -lm -lpthread -lutil)
endif()
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
make vs2017
```
or use this command to build it directly using msbuild

```
make vs2017 MSBUILD=1
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

    Copyright (C) 1997-2020  MAMEDev and contributors

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License version 2, as provided in
    docs/legal/GPL-2.0.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
    more details.

Please see COPYING for more details.
