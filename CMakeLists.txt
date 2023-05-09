################################################################################
# Copyright (c) 2019-2022, Initialsoft, Inc.
# All rights reserved.
#
# [description]
#
# author   : hunt978(hunt978@initialsoft.com)
# create   : 2019-05-18 00:19:50 UTC
# modified : 2022-10-11 08:02:01 UTC
################################################################################

# cmake version
cmake_minimum_required(VERSION 3.5.0)

# project
project(test_sln)

# output
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)
set(CMAKE_PDB_OUTPUT_DIRECTORY     ${CMAKE_HOME_DIRECTORY}/build)

# project group
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# debug
if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

# local modules
set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_LIST_DIR}/modules/xtlibuxcarbon)

# import scripts
include(cmake/GroupByFolder.cmake)
include(cmake/CXXHelper.cmake)
include(cmake/DeployQt.cmake)

# enable cxx17
EnableCxx17()

# goto source
add_subdirectory(source)