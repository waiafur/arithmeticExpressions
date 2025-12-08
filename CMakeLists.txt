cmake_minimum_required(VERSION 3.10)

project(arithEq)
include_directories(src)
include_directories(include)
file(GLOB hdrs "*.h*" "include/*.h*")
file(GLOB srcs "*.cpp" "src/*.cpp*")

add_executable(arithEq ${srcs} ${hdrs})