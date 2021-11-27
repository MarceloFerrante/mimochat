add_executable(mimochat
        main.cpp
        )

target_link_libraries(mimochat PRIVATE email)
target_link_libraries(mimochat PRIVATE servidorCliente)
target_link_libraries(mimochat PRIVATE bancoDeDados)
target_link_libraries(mimochat PRIVATE interface)


target_link_libraries( mimochat ${Boost_LIBRARIES} )

