#include <iostream>
#include <queue>
#include <encripta/encripta.h>
#include "amigos/listaAmigos.h"

int main() {
    using namespace std;


    //lista de amigos
    vector<listaAmigos::data> amigos;

    listaAmigos::data local;
    //popula lista
    for (int x = 0; x < 5; ++x){
        local.usuario.email = "usuario@ab.com";
        local.usuario.nome = "amigo " + to_string(x);
        local.servidor.ipv4 = "192.168.0.100";
        local.chave.publica = encripta::random_string(50);
        local.chave.privada = local.chave.publica;
        local.mensagem.inicial = "Mensagem de teste " + to_string(x);
        amigos.push_back(local); // push pra popular
    }


    //teste de impressão
    std::queue<listaAmigos::data> q; //TODO usar priority_queue para ordem alfabetica. Tem que fazer overload de operadoress

    for(auto& n : amigos) //TODO cria queue em ordem alfabetica (ver https://en.cppreference.com/w/cpp/container/priority_queue)
        q.emplace(n);

    while(!q.empty()) {

        listaAmigos::data temp_data = q.front();

        std::cout << temp_data.usuario.nome << '\n';
        cout << "Chave:       " << temp_data.chave.publica << endl;
        cout << "Inicial:     " << temp_data.mensagem.inicial << endl;


        temp_data.mensagem.cifrada = encripta::cifraMensagem(temp_data.mensagem.inicial, local);
        cout << "Cifrada:     " << temp_data.mensagem.cifrada << endl;

        temp_data.mensagem.decifrada = encripta::decifraMensagem(temp_data.mensagem.cifrada, local);
        cout << "Decifrada:   " <<  temp_data.mensagem.decifrada << endl << endl;

        q.pop();
    }
    return 0;
}
