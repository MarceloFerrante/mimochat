add_library(email
        email/email.h
        email/email.cpp
        )

target_include_directories(email PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})