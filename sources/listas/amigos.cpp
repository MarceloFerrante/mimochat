//
// Created by marcelo on 13/11/2021.
//

#include "amigos.h"
#include "cliente/encripta.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include "string"

namespace listaAmigos {

    // ver https://stackoverflow.com/questions/33379846/case-insensitive-sorting-of-an-array-of-strings
    //     https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
    void ordenaAlfabetico(vector<listaAmigos::data> &amigos) {
        sort(
                amigos.begin(),
                amigos.end(),
                [](listaAmigos::data &a, listaAmigos::data &b){
                    return lexicographical_compare(
                            a.usuario.nome.begin(), a.usuario.nome.end(),
                            b.usuario.nome.begin(), b.usuario.nome.end(),
                            [](const char& char1, const char& char2) {
                                return tolower(char1) < tolower(char2);
                            }
                    );
                }
        );
    }

    void ordenaEmail(vector<listaAmigos::data> &amigos) {
        sort(amigos.begin(), amigos.end(),
             [](listaAmigos::data &a, listaAmigos::data &b) { return a.usuario.email < b.usuario.email; }); //TODO não tá ordenando
    }

    void imprimeTudo(vector<listaAmigos::data> &amigos) {

        for (auto& n:amigos) {
            std::cout << n.usuario.nome << '\n';
            std::cout << n.usuario.email << '\n';
//            cout << "Chave:       " << n.chave.publica << endl;
//            cout << "Inicial:     " << n.texto.inicial << endl;
//
//            n.texto.cifrada = encripta::cifraMensagem(n, "");
//            cout << "Cifrada:     " << n.texto.cifrada << endl;
//
//            std::string cifrada = n.texto.cifrada;
//            n.texto.decifrada = encripta::decifraMensagem(n, n.texto.cifrada);
//            cout << "Decifrada:   " << n.texto.decifrada << endl;
            cout << endl;
        }
    }
}
