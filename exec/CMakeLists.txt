add_executable(mimochat
        main.cpp
        )

target_link_libraries(mimochat PRIVATE email)
target_link_libraries(mimochat PRIVATE encripta)
target_link_libraries(mimochat PRIVATE amigos)
