//
// Created by marcelo on 25/11/2021.
//

#ifndef MIMOCHAT_BD_H
#define MIMOCHAT_BD_H

#include "listas/amigos.h"
#include "BD.h"
#include <vector>
#include <string>
class bancoDeDados {

    public:
        void imprimeNomes(std::vector<listaAmigos::data> &bancoInterno);
        void imprimeEmail(std::vector<listaAmigos::data> &bancoInterno);
        void ordenaNomes(std::vector<listaAmigos::data> &bancoInterno);
        void ordenaEmail(std::vector<listaAmigos::data> &bancoInterno);
        void imprimeTudo(std::vector<listaAmigos::data> &bancoInterno);

        void imprimeNomes();
        void imprimeEmail();
        void ordenaNomes();
        void ordenaEmail();
        void imprimeTudo();

        void adicionaContato(listaAmigos::data local);
        void adicionaContato();

    private:
        struct chaves {
            std::string  publica,
                    privada;
        };

        struct rede {
            std::string  ipv4;
            u_int16_t porta;
        };

        struct texto{ //TODO desnescessãrio?
            std::string simples,
                    cifrado;

        };

        struct identidade {
            std::string  nome,
                    email;
        };

        struct dados { //TODO fazer classe
            identidade id;
            chaves chave;
            rede servidor;
            texto mensagem;
        };

        std::vector<listaAmigos::data> bancoInterno;
    };




#endif //MIMOCHAT_BD_H
