#include "BD.h"
#include "cliente/cliente.h"
#include "cliente/servidor.h"
#include <cliente/encripta.h>

int main() {
  using namespace std;

  bancoDeDados listaDePessoas;
  BD::dados local;
  // popula lista
  for (int x = 0; x < 5; ++x) {
    local.id.nome = encripta::random_string(4) + " amigo " + to_string(x);
    local.id.email = encripta::random_string(4) + "@ab.com";
    local.servidor.ipv4 = "192.168.0.1";
    local.chave.publica = encripta::random_string(16);
    local.chave.privada = local.chave.publica;
    local.mensagem.simples = "Mensagem de teste " + to_string(x);
    listaDePessoas.adicionaContato(local);
  }


  listaDePessoas.adicionaContato("marcelo@c.com");

//  listaDePessoas.ordenaNomes();
//  listaDePessoas.imprimeNomes();
//  listaDePessoas.ordenaEmail();
//  listaDePessoas.imprimeEmail();

  listaDePessoas.imprimeEmail();
  listaDePessoas.ordena([](BD::dados &x) { return x.id.email; });
  listaDePessoas.imprimeEmail();
  return 0;
}
