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
    BD::dados local;
    local.id.nome = encripta::random_string(4) + " amigo " + to_string(x);
    local.id.email = encripta::random_string(4) + "@ab.com";
    local.endereco.ipv4 = "192.168.0.1";
    local.chave.publica = encripta::random_string(16);
    local.chave.privada = local.chave.publica;
    local.mensagem.simples = "Mensagem de teste " + to_string(x);
    listaDePessoas.adicionaContato(local);
  }

//    listaDePessoas.ordenaNomes();
//    listaDePessoas.imprimeNomes();
//    listaDePessoas.ordenaEmail();
//    listaDePessoas.imprimeEmail();

  //  listaDePessoas.ordena([](BD::dados& d) { return d.id.email; });
  //  listaDePessoas.imprime([](BD::dados &d) { std::cout << d.id.nome; });]

    console console;

    char opcao;

    do{
        console.draw();
        opcao = console.opcao(listaDePessoas);
    }
    while (opcao);


  return 0;
}
