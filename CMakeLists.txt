cmake_minimum_required(VERSION 3.1)
project(mimochat LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(MIMOCHAT_BUILD_EXEC "Build exec" ON)
option(MIMOCHAT_BUILD_CLIENTE "build cliente/servidor" OFF)
option(MIMOCHAT_BUILD_TESTS "Build tests" OFF)

add_subdirectory(sources)

IF(MIMOCHAT_BUILD_TESTS)
    add_subdirectory(tests)
ENDIF()

if(MIMOCHAT_BUILD_EXEC)
    add_subdirectory(exec)
ENDIF()

if(MIMOCHAT_BUILD_CLIENTE)
    add_subdirectory(cliente)
ENDIF()

find_package( boost )