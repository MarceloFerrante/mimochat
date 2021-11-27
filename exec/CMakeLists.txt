add_executable(mimochat
        main.cpp
        )

target_link_libraries(mimochat PRIVATE email)
target_link_libraries(mimochat PRIVATE cliente)
target_link_libraries(mimochat PRIVATE bancoDeDados)
target_link_libraries(mimochat PRIVATE interface)
