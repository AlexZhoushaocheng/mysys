project(mysys)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LOG_SRC ${CMAKE_CURRENT_LIST_DIR}/thirdparty/easyloggin++/easylogging++.cc)

# include(src/CMakeLists.txt)
aux_source_directory(src/core SRC)
aux_source_directory(src/core/notifier N_SRC)

add_library(${PROJECT_NAME} ${SRC} ${N_SRC} ${LOG_SRC})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/thirdparty/easyloggin++)