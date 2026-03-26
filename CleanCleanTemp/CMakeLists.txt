cmake_minimum_required(VERSION 3.10)

project(CleanCleanTemp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CleanCleanTemp
    CleanCleanTemp.cpp
    Cleaner.cpp
    PathUtils.cpp
    UserUtils.cpp
)