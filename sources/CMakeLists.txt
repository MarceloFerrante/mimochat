add_library(email
        email/email.h
        email/email.cpp
        interface/console.cpp interface/console.h)
target_include_directories(email PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(cliente
        cliente/encripta.h
        cliente/encripta.cpp
        cliente/cliente.cpp
        cliente/cliente.h
        cliente/servidor.cpp
        cliente/servidor.h)
target_include_directories(cliente PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library( bancoDeDados
        bancoDeDados/BD.cpp
        bancoDeDados/BD.h
        bancoDeDados/BD.hpp )
target_include_directories( bancoDeDados PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(interface
        interface/console.h
        interface/console.cpp)
target_include_directories(interface PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
