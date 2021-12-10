#include "bancoDeDados/BD.h"
#include <servidorCliente/encripta.h>
//#include "cliente/cliente.h"
//#include "servidorCliente/endereco.h"
//#include "boost/asio.hpp"
#include <iostream>
#include "interface/console.h"

int main()
{
  using namespace std;

  bancoDeDados listaDePessoas;

  // popula lista
  for (int x = 0; x < 5; ++x) {
    string nome, email, ipv4, pub, priv, msg;
    nome = encripta::random_string(4) + " amigo " + to_string(x);
    email = encripta::random_string(4) + "@ab.com";
    ipv4 =  "192.168.0.10" + to_string(x);
    pub = encripta::random_string(16);
    priv =  pub;
    msg =  "Mensagem de teste " + to_string(x);
    listaDePessoas.adicionaContato(email, nome, ipv4, pub, priv, msg);
  }

//    listaDePessoas.ordenaNomes();
//    listaDePessoas.imprimeNomes();
//    listaDePessoas.ordenaEmail();
//    listaDePessoas.imprimeEmail();

  //  listaDePessoas.ordena([](BD::dados& d) { return d.id.email; });
  //  listaDePessoas.imprime([](BD::dados &d) { std::cout << d.id.nome; });]

    console console;
//
//    char opcao;
//    do{
//        console.draw();
//        opcao = console.opcao(listaDePessoas);
//    }
//    while (opcao);

    listaDePessoas.pingAll();
  return 0;
}
