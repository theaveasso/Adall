cmake_minimum_required(VERSION 3.28)
project(Adall)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(external)

FILE(GLOB_RECURSE sources "src/*.cpp")
FILE(GLOB_RECURSE headers "include/Adall/*.hpp")

add_executable(${PROJECT_NAME}
        main.cpp
        ${sources}
        ${headers}
)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
