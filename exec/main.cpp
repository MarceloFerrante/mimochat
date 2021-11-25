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
        local.usuario.nome = encripta::random_string(4) +" amigo " + to_string(x);
        local.usuario.email = encripta::random_string(4) + "@ab.com";
        local.servidor.ipv4 = "192.168.0.1";
        local.chave.publica = encripta::random_string(16);
        local.chave.privada = local.chave.publica;
        local.mensagem.inicial = "Mensagem de teste " + to_string(x);
        amigos.push_back(local); // push pra popular
    }
    local.usuario.nome = "Amaral";
    amigos.push_back(local);


    listaAmigos::ordenaAlfabetico(amigos);
    listaAmigos::imprimeNomes(amigos);
//
//    listaAmigos::ordenaEmail(amigos);
//    listaAmigos::imprimeNomes(amigos);

    encripta::enviaChave();

    return 0;
}
