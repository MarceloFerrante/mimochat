#include <iostream>
#include <queue>
#include "algorithm"
#include <cliente/encripta.h>
#include "listas/amigos.h"
#include "cliente/cliente.h"
#include "cliente/servidor.h"

int main() {
    using namespace std;


    //lista de listas
    vector<listaAmigos::data> amigos;

    listaAmigos::data local;
    //popula lista
    for (int x = 0; x < 5; ++x){
        local.usuario.email = encripta::random_string(2) + "email@ab.com";
        local.usuario.nome = encripta::random_string(1) +" amigo " + to_string(x);
        local.servidor.ipv4 = "192.168.0.1";
        local.chave.publica = encripta::random_string(16);
        local.chave.privada = local.chave.publica;
        local.mensagem.inicial = "Mensagem de teste " + to_string(x);
        amigos.push_back(local); // push pra popular
    }
    local.usuario.nome = "Amaral";
    amigos.push_back(local);

    //ordem alfaetica pelo nome
    sort(amigos.begin(), amigos.end(), [](listaAmigos::data a,listaAmigos::data b) { return a.usuario.nome < b.usuario.nome; });

    listaAmigos::imprimeNomes(amigos);
    encripta::enviaChave();

    return 0;
}
