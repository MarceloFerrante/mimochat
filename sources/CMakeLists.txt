add_library(email
        email/email.h
        email/email.cpp
        )

add_library(encripta
        encripta/encripta.h
        encripta/encripta.cpp
        )
target_include_directories(email PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(encripta PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
