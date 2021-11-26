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
                email;
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

    struct data { //TODO fazer classe
        pessoa usuario;
        chaves chave;
        rede servidor;
        carga texto;
    };

    void imprimeTudo(vector<listaAmigos::data> &amigos);
    void ordenaAlfabetico(vector<listaAmigos::data> &amigos);
    void ordenaEmail(vector<listaAmigos::data> &amigos);

    class bancoDeDados{ //TODO Converter dados pra esta classe
    public:
        void imprimeNome(vector<data> &bancoInterno);
        void imprimeEmail(vector<data> &bancoInterno);
        void ordenaNomes(vector<data> &bancoInterno);
        void ordenaEmail(vector<data> &bancoInterno);
        void imprimeTudo(vector<data> &bancoInterno);
        void adicionaContato(string nome, string email = "@");

    private:
        struct chaves {
            string  publica,
                    privada;
        };

        struct rede {
            string  ipv4;
            u_int16_t porta;
        };

        struct texto{ //TODO desnescessãrio?
            string simples,
                    cifrado;

        };

        struct identidade {
            string  nome,
                    email;
        };

        struct dados { //TODO fazer classe
            identidade id;
            chaves chave;
            rede servidor;
            texto mensagem;
        };

        vector<dados> bancoInterno;
    };
}

#endif //MIMOCHAT_AMIGOS_H
