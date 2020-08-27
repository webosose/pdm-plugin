# Copyright (c) 2019-2020 LG Electronics, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 2.8.7)
project(pdm-plugin CXX)
include(webOS/webOS)
webos_modules_init(1 0 0 QUALIFIER RC4)
webos_component(1 0 1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

include(FindPkgConfig)

pkg_check_modules(PBNJSON_CPP REQUIRED pbnjson_cpp)
include_directories(${PBNJSON_CPP_INCLUDE_DIRS})
webos_add_compiler_flags(ALL ${PBNJSON_CPP_CFLAGS_OTHER})

pkg_check_modules(GLIB2 REQUIRED glib-2.0)
#include_directories(${GLIB2_INCLUDE_DIRS})
webos_add_compiler_flags(ALL ${GLIB2_CFLAGS})

pkg_check_modules(LUNASERVICE REQUIRED luna-service2)
include_directories(${LUNASERVICE_INCLUDE_DIR})
webos_add_compiler_flags(ALL ${LUNASERVICE_CFLAGS})

pkg_check_modules(PMLOG REQUIRED PmLogLib)
include_directories(${PMLOG_INCLUDE_DIRS})
webos_add_compiler_flags(ALL ${PMLOG_CFLAGS_OTHER})

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/common)
include_directories(${CMAKE_SOURCE_DIR}/src/RefPlugIn)

set(PLUGIN_LIB pdm-plugin)

file(GLOB_RECURSE SRC_LIB ${CMAKE_SOURCE_DIR} *.cpp)

add_library(${PLUGIN_LIB} SHARED ${SRC_LIB})

webos_build_library(NAME ${PLUGIN_LIB} NOHEADERS)
install(FILES ${CMAKE_SOURCE_DIR}/files/conf/pdm.conf DESTINATION ${WEBOS_INSTALL_SYSCONFDIR}/pdm/)
