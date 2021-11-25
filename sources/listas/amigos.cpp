//
// Created by marcelo on 13/11/2021.
//

#include "amigos.h"
#include "cliente/encripta.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>

namespace listaAmigos {

    void ordenaAlfabetico(vector<listaAmigos::data> &amigos) {
        sort(amigos.begin(), amigos.end(),
             [](listaAmigos::data &a, listaAmigos::data &b) { return a.usuario.nome < b.usuario.nome; });
    }

    void ordenaEmail(vector<listaAmigos::data> &amigos) {
        sort(amigos.begin(), amigos.end(),
             [](listaAmigos::data &a, listaAmigos::data &b) { return a.usuario.email < b.usuario.email; });
    }

    void imprimeNomes(vector<listaAmigos::data> &amigos) {

        for (auto& n:amigos) {
            std::cout << n.usuario.nome << '\n';
            std::cout << n.usuario.email << '\n';
//            cout << "Chave:       " << n.chave.publica << endl;
//            cout << "Inicial:     " << n.mensagem.inicial << endl;
//
//            n.mensagem.cifrada = encripta::cifraMensagem(n, "");
//            cout << "Cifrada:     " << n.mensagem.cifrada << endl;
//
//            std::string cifrada = n.mensagem.cifrada;
//            n.mensagem.decifrada = encripta::decifraMensagem(n, n.mensagem.cifrada);
//            cout << "Decifrada:   " << n.mensagem.decifrada << endl << endl;
            cout << endl;
        }
    }
}