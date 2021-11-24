find_package(Catch2 QUIET)
if (NOT Catch2_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2
            GIT_TAG v2.13.7
    )
    FetchContent_GetProperties(Catch2)
    if (NOT catch2_POPULATED)
        FetchContent_Populate(catch2)
        add_subdirectory(${catch2_SOURCE_DIR} ${catch2_BINARY_DIR})
    endif()
endif()

find_package(cryptopp QUIET)
if (NOT cryptopp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            cryptopp
            GIT_REPOSITORY https://github.com/weidai11/cryptopp
            GIT_TAG CRYPTOPP_8_6_0
    )
    FetchContent_GetProperties(cryptopp)
    if (NOT cryptopp_POPULATED)
        FetchContent_Populate(cryptopp)
        add_subdirectory(${cryptopp_SOURCE_DIR} ${cryptopp_BINARY_DIR})
    endif()
endif()


find_package(botan QUIET)
if (NOT botan_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            botan
            GIT_REPOSITORY https://github.com/randombit/botan/
            GIT_TAG 2.18.2
    )
    FetchContent_GetProperties(botan)
    if (NOT botan_POPULATED)
        FetchContent_Populate(botan)
        add_subdirectory(${botan_SOURCE_DIR} ${botan_BINARY_DIR})
    endif()
endif()

add_executable(ut_email ut_email.cpp)
target_link_libraries(ut_email PRIVATE email)
target_link_libraries(ut_email PRIVATE encripta)
target_link_libraries(ut_email PRIVATE amigos)
target_link_libraries(ut_email PRIVATE Catch2)
add_test(ut_email_test ut_email)
