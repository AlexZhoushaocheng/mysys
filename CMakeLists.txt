cmake_minimum_required(VERSION 3.20)

project(exe_mysys)

add_subdirectory(mysys)

add_executable(${PROJECT_NAME} main.cpp)
