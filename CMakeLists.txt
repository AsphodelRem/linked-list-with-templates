cmake_minimum_required(VERSION 3.14)
project(linked_list C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")

add_executable(test example.c)