//
// Created by marcelo on 25/11/2021.
//

#ifndef MIMOCHAT_BD_H
#define MIMOCHAT_BD_H

#include "BD.h"
#include "listas/amigos.h"
#include <string>
#include <vector>
class bancoDeDados {
public:
  void imprimeNomes(std::vector<listaAmigos::data> &bancoInterno);
  void imprimeEmail(std::vector<listaAmigos::data> &bancoInterno);
  void ordenaNomes(std::vector<listaAmigos::data> &bancoInterno);
  void ordenaEmail(std::vector<listaAmigos::data> &bancoInterno);
  void imprimeTudo(std::vector<listaAmigos::data> &bancoInterno);

  void imprimeNomes();
  void imprimeEmail();
  void ordenaNomes();
  void ordenaEmail();
  void imprimeTudo();

  void adicionaContato(listaAmigos::data local);
  void adicionaContato(std::string, std::string);

  template <typename FN> void ordena(FN extrai);
  template <typename FN> void ordena();

private:

  std::vector<listaAmigos::data> bancoInterno;
};

#endif // MIMOCHAT_BD_H
