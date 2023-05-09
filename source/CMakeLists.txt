################################################################################
# Copyright (c) 2018-2021, Initialsoft, Inc.
# All rights reserved.
#
# Root cmake script entry
#
# author   : hunt978(hunt978@initialsoft.com)
# create   : 2018-05-02 09:34:07 UTC
# modified : 2021-06-19 09:11:39 UTC
################################################################################

# cmake version
cmake_minimum_required(VERSION 3.5.0)

# project
project(test)

# collect sources
file(GLOB_RECURSE SOURCES *.cc *.h *.qrc *.ui *.rc *.cpp)
group_by_folder(SOURCES ${CMAKE_CURRENT_LIST_DIR}/..)

# qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# package
find_package(Qt5 COMPONENTS Core Widgets Gui Designer REQUIRED)

# build target shared
add_executable(${PROJECT_NAME} WIN32 ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Gui)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Designer)

# deploy
target_deploy_qt(${PROJECT_NAME})


