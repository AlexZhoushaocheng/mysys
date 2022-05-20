cmake_minimum_required(VERSION 3.20)

project(exe_mysys)

add_subdirectory(mysys)

add_executable(${PROJECT_NAME} main.cpp)

add_dependencies(${PROJECT_NAME} mysys)
target_include_directories(${PROJECT_NAME} PUBLIC mysys)
target_link_libraries(${PROJECT_NAME} mysys pthread)
