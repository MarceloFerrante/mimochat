#include <iostream>
#include <email/email.h>
#include <encripta/encripta.h>
#include "amigos/listaAmigos.h"
#include <queue>
using namespace std;

int main() {
    queue<listaAmigos::data> amigos;
    listaAmigos::data local;

    local.email.endereço = "email@ab.com";
    local.email.usuario = "amigo 1";
    local.ip.ipv4 = "192.168.0.100";
    amigos.push(local);

    local.email.endereço = "email@cd.com";
    local.email.usuario = "amigo 2";
    local.ip.ipv4 = "192.168.0.200";

    amigos.push(local);

    listaAmigos::data temporario = amigos.front();
    string nome = temporario.email.usuario;
    string email = temporario.email.endereço;
    string ipv4 = temporario.ip.ipv4;
    cout << nome <<'\n' << email <<'\n' << ipv4 <<'\n' << endl;

    amigos.pop();

    temporario = amigos.front();
    nome = temporario.email.usuario;
    email = temporario.email.endereço;ipv4 = temporario.ip.ipv4;

    cout << nome <<'\n' << email <<'\n' << ipv4 <<'\n' << endl;


//    mimochat::conecta(nome); //TODO corrigir template e renomear o namespace

//    cout << mimochat::conecta(12) << endl;


    encripta::enviaChave();
    return 0;
}
