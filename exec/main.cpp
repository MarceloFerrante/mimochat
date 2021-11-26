#include <iostream>
#include <queue>
#include "algorithm"
#include <cliente/encripta.h>
#include "listas/amigos.h"
#include "cliente/cliente.h"
#include "cliente/servidor.h"
#include "BD.h"
int main() {
    using namespace std;


    //lista de bancoDeDados
    vector<listaAmigos::data> pessoas;

    bancoDeDados listaDePessoas;
    listaAmigos::data local;
    //popula lista
    for (int x = 0; x < 5; ++x){
        local.usuario.nome = encripta::random_string(4) +" amigo " + to_string(x);
        local.usuario.email = encripta::random_string(4) + "@ab.com";
        local.servidor.ipv4 = "192.168.0.1";
        local.chave.publica = encripta::random_string(16);
        local.chave.privada = local.chave.publica;
        local.texto.inicial = "Mensagem de teste " + to_string(x);
        pessoas.push_back(local); // push pra popular
        listaDePessoas.adicionaContato(local);
    }

//    local.usuario.nome = "Carlos";
//    pessoas.push_back(local);

//    local.usuario.nome = "Amaral";
//    pessoas.push_back(local);
//
//    listaAmigos::ordenaNomes(bancoDeDados);
//    listaAmigos::ordenaEmail(bancoDeDados);
//    listaAmigos::imprimeTudo(bancoDeDados);

//
//    listaAmigos::ordenaEmail(bancoDeDados);
//    listaAmigos::imprimeTudo(bancoDeDados);

    auto geral = new bancoDeDados;
    geral->ordenaNomes(pessoas);
//    geral->imprimeNomes(pessoas);
    geral->imprimeNomes();

    geral->ordenaEmail(pessoas);
//    geral->imprimeEmail(pessoas);

//    listaDePessoas.imprimeTudo(listaDePessoas);
//    geral->imprimeTudo(pessoas);
    return 0;
}
