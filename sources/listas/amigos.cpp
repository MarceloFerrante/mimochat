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
             [](listaAmigos::data a, listaAmigos::data b) { return a.usuario.nome < b.usuario.nome; }); //mudar de lugar
    }

    void ordenaEmail(vector<listaAmigos::data> &amigos) {
        sort(amigos.begin(), amigos.end(),
             [](listaAmigos::data a, listaAmigos::data b) { return a.usuario.email < b.usuario.email; }); //mudar de lugar
    }

    void imprimeNomes(vector<listaAmigos::data> &amigos) {

        //teste de impressão
        std::queue<listaAmigos::data> q;

        for (auto &n: amigos) //TODO desnescessário
            q.emplace(n);

        while (!q.empty()) {

            listaAmigos::data& temp_data = q.front();

            std::cout << temp_data.usuario.nome << '\n';
            std::cout << temp_data.usuario.email << '\n';
            cout << "Chave:       " << temp_data.chave.publica << endl;
            cout << "Inicial:     " << temp_data.mensagem.inicial << endl;


            temp_data.mensagem.cifrada = encripta::cifraMensagem(temp_data, "");
            cout << "Cifrada:     " << temp_data.mensagem.cifrada << endl;

            std::string cifrada = temp_data.mensagem.cifrada;
            temp_data.mensagem.decifrada = encripta::decifraMensagem(temp_data, temp_data.mensagem.cifrada);
            cout << "Decifrada:   " << temp_data.mensagem.decifrada << endl << endl;

            q.pop();
        }
    }
}