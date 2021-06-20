cmake_minimum_required(VERSION 3.5)

project(combine_mode)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS "-g ${CMAKE_CXX_FLAGS}")

aux_source_directory(. FILE)

add_executable(combine_mode ${FILE})