//
// Created by marcelo on 13/11/2021.
//

#include "amigos.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>

namespace listaAmigos {
//    using namespace std;

    //lista nomes em ordem alfabetica

    template<typename T>
    void print_queue(T q) { //passa uma copia do queue pra imprimir
        while(!q.empty()) {

            listaAmigos::data d = q.top();
            std::cout << d.usuario.nome << ' ';
            q.pop();
        }
        std::cout << '\n';
    }

//    void imprimeNomes( vector<listaAmigos::data> &containerGeral){

//        std::priority_queue<listaAmigos::data> q;

//            for (auto n: containerGeral)
//                q.push(n);
//    }

}
