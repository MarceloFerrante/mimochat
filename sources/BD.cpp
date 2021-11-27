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

void bancoDeDados::adicionaContato(BD::data local) {
  bancoInterno.push_back(local);
}

void bancoDeDados::adicionaContato(std::string email,
                                   std::string nome = "anonimo") {
  BD::data local;
  local.id.email = email;
  local.id.nome = nome;
  bancoInterno.push_back(local);
}
// ver
// https://stackoverflow.com/questions/33379846/case-insensitive-sorting-of-an-array-of-strings
//     https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
void bancoDeDados::ordenaNomes() { // TODO transformar em template
  sort(bancoInterno.begin(), bancoInterno.end(),
       [](const BD::data &a, const BD::data &b) {
         return lexicographical_compare(
             a.id.nome.begin(), a.id.nome.end(), b.id.nome.begin(),
             b.id.nome.end(), [](const char &char1, const char &char2) {
               return tolower(char1) < tolower(char2);
             });
       });
}

void bancoDeDados::ordenaEmail() {
  sort(bancoInterno.begin(), bancoInterno.end(),
       [](BD::data &a, BD::data &b) {
         return lexicographical_compare(
             a.id.email.begin(), a.id.email.end(), b.id.email.begin(),
             b.id.email.end(), [](const char &char1, const char &char2) {
               return tolower(char1) < tolower(char2);
             });
       });
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

// BD::data extrai(BD::data d) { return d; }

template <class FN> void bancoDeDados::ordena(FN extrai) { // TODO
  sort(bancoInterno.begin(), bancoInterno.end(),
       [extrai](BD::data &a, BD::data &b) {
         return lexicographical_compare(
             extrai(a).begin(), extrai(a).end(),
             extrai(b).begin(), extrai(b).end(),
             [](const char &char1, const char &char2) {
               return tolower(char1) < tolower(char2);
             });
       });
}

template <typename FN> void bancoDeDados::ordena() {
  bancoDeDados::ordena([](BD::data &x) { return x.id.email; });
}
