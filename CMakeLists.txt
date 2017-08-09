cmake_minimum_required(VERSION 3.7)
project(typelist)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp type_list.h)
add_executable(typelist ${SOURCE_FILES})