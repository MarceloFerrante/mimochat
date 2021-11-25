//
// Created by marcelo on 08/10/2021.
//
#ifndef MIMOCHAT_EMAIL_H
#define MIMOCHAT_EMAIL_H

#include "listas/amigos.h"

namespace mimochat {

//    template< typename T1, typename T2>
//    T2 conecta(T1 d);

    int enviaChave();
    int conecta(int x);
    std::string conecta(listaAmigos::data d);
}

#endif //MIMOCHAT_EMAIL_H
