//
// Created by marcelo on 13/11/2021.
//

#ifndef MIMOCHAT_AMIGOS_H
#define MIMOCHAT_AMIGOS_H

#include <iostream>
#include <vector>
namespace listaAmigos {
    using namespace std;

    struct pessoa {
        string  nome,
                email,
                corpo;
    };

    struct chaves {
        string  publica,
                privada;
    };

    struct rede {
        string  ipv4;
        u_int16_t porta;
    };

    struct carga{
        string inicial,
            cifrada,
            decifrada;

    };

    struct data {
        pessoa usuario;
        chaves chave;
        rede servidor;
        carga mensagem;
    };

    void imprimeNomes(vector<listaAmigos::data> &amigos);
    void ordenaAlfabetico(vector<listaAmigos::data> &amigos);
    void ordenaEmail(vector<listaAmigos::data> &amigos);
}

#endif //MIMOCHAT_AMIGOS_H
