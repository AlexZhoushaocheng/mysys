project(mysys)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include(src/CMakeLists.txt)
aux_source_directory(src/core SRC)

add_library(${PROJECT_NAME} ${SRC})