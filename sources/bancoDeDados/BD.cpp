//
// Created by marcelo on 25/11/2021.
//
#include "BD.h"
#include "cliente/encripta.h"
#include "string"
#include <iostream>
#include <vector>

void bancoDeDados::imprimeNomes() {
  for (auto &n : bancoInterno) {
    std::cout << n.id.nome << '\n';
  }
}

void bancoDeDados::imprimeEmail() {
  for (auto &n : bancoInterno) {
    std::cout << n.id.email << '\n';
  }
}

void bancoDeDados::adicionaContato(BD::dados local) {
  bancoInterno.push_back(local);
}

void bancoDeDados::adicionaContato(BD::pessoa p) {
  BD::dados local;
  local.id.email = p.email;

  if (p.nome.empty())
      p.nome = "Anônimo";
  local.id.nome = p.nome;
  bancoInterno.push_back(local);
}

void bancoDeDados::adicionaContato(std::string email) {
    bancoDeDados::adicionaContato(BD::pessoa{email, });

}

// ver
// https://stackoverflow.com/questions/33379846/case-insensitive-sorting-of-an-array-of-strings
//     https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
void bancoDeDados::ordenaNomes() { // TODO transformar em template
    bancoDeDados::ordena([](BD::dados &x) { return x.id.nome; });
}

void bancoDeDados::ordenaEmail() {
    bancoDeDados::ordena([](BD::dados &x) { return x.id.email; });
}

void bancoDeDados::imprimeTudo() {

  for (auto &n : bancoInterno) {

    std::cout << n.id.nome << '\n';
    std::cout << n.id.email << '\n';
    std::cout << "Chave:       " << n.chave.publica << std::endl;
    std::cout << "Inicial:     " << n.mensagem.simples << std::endl;

    n.mensagem.cifrada = encripta::cifraMensagem(n, "");
    std::cout << "Cifrada:     " << n.mensagem.cifrada << std::endl;

    std::string cifrada = n.mensagem.cifrada;
    n.mensagem.decifrada = encripta::decifraMensagem(n, n.mensagem.cifrada);
    std::cout << "Decifrada:   " << n.mensagem.decifrada << std::endl;
    std::cout << std::endl;
  }
}
