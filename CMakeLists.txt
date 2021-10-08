cmake_minimum_required(VERSION 3.5)
project(mimochat LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(MIMOCHAT_BUILD_TESTS "Build tests" ON)
option(MIMOCHAT_BUILD_EXEC "Build exec" ON)

add_subdirectory(sources)

IF(MIMOCHAT_BUILD_TESTS)
    add_subdirectory(tests)
ENDIF()

if(MIMOCHAT_BUILD_EXEC)
    add_subdirectory(exec)
ENDIF()
