################################################################################
# Copyright (c) 2018-2022, Induspotis, Inc.
# All rights reserved.
#
# Root cmake script entry
#
# author   : hunt978(hubq@initialsoft.com)
# create   : 2018-05-02 09:34:07 UTC
# modified : 2022-05-11 07:35:49 UTC
################################################################################

# cmake version
cmake_minimum_required(VERSION 3.5.0)

# build dock project
MACRO(EnableCxx17)

  # msvc
  if( MSVC_VERSION GREATER_EQUAL "1914" )
    add_compile_options("/Zc:__cplusplus")
  endif()

  if( MSVC_VERSION GREATER_EQUAL "1900" )
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++17" _compiler_supports_cxx17)
    CHECK_CXX_COMPILER_FLAG("/std:c17" _compiler_supports_c17)
    if(_compiler_supports_cxx17)
      add_compile_options("/std:c++17")
      add_compile_options("/std:c17")
    endif()
  endif()

  # gnu
  if( CMAKE_COMPILER_IS_GNUCXX )
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("-std=c++17" _compiler_supports_cxx17)
    if(_compiler_supports_cxx17)
      set(CMAKE_CXX_FLAGS "-std=c++17 ${CMAKE_CXX_FLAGS}")
    endif()
  endif()

ENDMACRO(EnableCxx17)



# build dock project
MACRO(EnableCxx20)

  message(STATUS "MSVC_VERSION :" ${MSVC_VERSION})

  # msvc
  if( MSVC_VERSION GREATER_EQUAL "1914" )
    add_compile_options("/Zc:__cplusplus")
  endif()

  if( MSVC_VERSION GREATER_EQUAL "1929" )
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++20" _compiler_supports_cxx20)
    CHECK_CXX_COMPILER_FLAG("/std:c17" _compiler_supports_c17)
    if(_compiler_supports_cxx20)
      add_compile_options("/std:c++20")
      add_compile_options("/std:c17")
    endif()
  endif()

  # gnu
  if( CMAKE_COMPILER_IS_GNUCXX )
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("-std=c++20" _compiler_supports_cxx20)
    if(_compiler_supports_cxx20)
      set(CMAKE_CXX_FLAGS "-std=c++20 ${CMAKE_CXX_FLAGS}")
    endif()
  endif()

ENDMACRO(EnableCxx20)