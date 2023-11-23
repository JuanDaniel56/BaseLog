cmake_minimum_required(VERSION 3.5)

project(PACKAGE_LOGGER)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# set(SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/baselogger.cc)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
add_library(baselogger SHARED ${SRC_LIST})