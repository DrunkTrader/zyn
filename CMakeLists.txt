cmake_minimum_required(VERSION 3.20)

project(copycat
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(zyn
    src/main.cpp
    src/cli.cpp
    src/copier.cpp
)

target_include_directories(zyn
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)