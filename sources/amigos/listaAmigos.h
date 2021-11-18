//
// Created by marcelo on 13/11/2021.
//

#ifndef MIMOCHAT_LISTAAMIGOS_H
#define MIMOCHAT_LISTAAMIGOS_H

#include <iostream>
namespace listaAmigos {
    using namespace std;

    struct emailData {
        string  usuario,
                endereço,
                corpo;
    };

    struct chaves {
        string  publica,
                privada;
    };

    struct rede {
        string  ipv6,
                ipv4;
    };

    struct data {
        emailData email;
        chaves chave;
        rede ip;
    };
}


#endif //MIMOCHAT_LISTAAMIGOS_H
