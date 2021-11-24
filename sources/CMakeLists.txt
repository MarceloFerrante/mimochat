add_library(email
        email/email.h
        email/email.cpp
        )
target_include_directories(email PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(encripta
        encripta/encripta.h
        encripta/encripta.cpp
        )
target_include_directories(encripta PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(amigos
        amigos/listaAmigos.h
        amigos/listaAmigos.cpp
        )
target_include_directories(amigos PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
