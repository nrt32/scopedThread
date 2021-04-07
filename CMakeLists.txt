cmake_minimum_required(VERSION 3.6)
set(PROJECT_NAME scopedThread)
set(SOURCE_DIR "./source/")
set(INCLUDE_DIR "./include/")

project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

file(GLOB_RECURSE SOURCE_FILES ${SOURCE_DIR}*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
                           "${INCLUDE_DIR}"
                           )
