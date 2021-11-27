//
// Created by marcelo on 13/11/2021.
//

#include "amigos.h"
#include "cliente/encripta.h"
#include "string"
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

namespace listaAmigos {

// ver
// https://stackoverflow.com/questions/33379846/case-insensitive-sorting-of-an-array-of-strings
//     https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
void ordenaAlfabetico(
    vector<listaAmigos::data> &amigos) { // TODO transformar em template
  sort(amigos.begin(), amigos.end(),
       [](listaAmigos::data &a, listaAmigos::data &b) {
         return lexicographical_compare(
             a.id.nome.begin(), a.id.nome.end(), b.id.nome.begin(),
             b.id.nome.end(), [](const char &char1, const char &char2) {
               return tolower(char1) < tolower(char2);
             });
       });
}

void ordenaEmail(vector<listaAmigos::data> &amigos) {
  sort(amigos.begin(), amigos.end(),
       [](listaAmigos::data &a, listaAmigos::data &b) {
         return lexicographical_compare(
             a.id.email.begin(), a.id.email.end(), b.id.email.begin(),
             b.id.email.end(), [](const char &char1, const char &char2) {
               return tolower(char1) < tolower(char2);
             });
       });
}

void imprimeTudo(vector<listaAmigos::data> &amigos) {

  for (auto &n : amigos) {
    std::cout << n.id.nome << '\n';
    std::cout << n.id.email << '\n';
    //            cout << "Chave:       " << n.chave.publica << endl;
    //            cout << "Inicial:     " << n.texto.inicial << endl;
    //
    //            n.texto.cifrada = encripta::cifraMensagem(n, "");
    //            cout << "Cifrada:     " << n.texto.cifrada << endl;
    //
    //            std::string cifrada = n.texto.cifrada;
    //            n.texto.decifrada = encripta::decifraMensagem(n,
    //            n.texto.cifrada); cout << "Decifrada:   " << n.texto.decifrada
    //            << endl;
    cout << endl;
  }
}

void adicionaContato(string nome, string email = "@") {
  listaAmigos::data local;
  local.id.nome = nome;
  local.id.email = email;
  //            bancoInterno.push_back(local);
}

} // namespace listaAmigos
