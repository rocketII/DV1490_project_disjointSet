cmake_minimum_required(VERSION 3.3)
project(projekt_disjointSet)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Test_DisjointSet.cpp DisjointSets.h DisjointSets.cpp)
add_executable(projekt_disjointSet ${SOURCE_FILES})