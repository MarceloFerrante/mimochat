cmake_minimum_required(VERSION 3.5)
project(mimochat LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

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
    add_subdirectory(servidorCliente)
ENDIF()

# see https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package( Boost REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )
