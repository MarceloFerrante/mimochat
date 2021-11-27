//
// Created by marcelo on 25/11/2021.
//

#ifndef MIMOCHAT_BD_H
#define MIMOCHAT_BD_H

#include "BD.h"
#include <string>
#include <vector>

namespace BD {
    using namespace std;

    struct pessoa {
        string email,
                nome; // TODO pegar nome a partir do emailb
    };

    struct chaves {
        string publica, privada;
    };

    struct rede {
        string ipv4;
        u_int16_t porta;
    };

    struct texto {
        string simples, cifrada, decifrada;
    };

    struct data { // TODO fazer classe
        pessoa id;
        chaves chave;
        rede servidor;
        texto mensagem;
    };

    void imprimeTudo(vector<BD::data> &amigos);
    void ordenaAlfabetico(vector<BD::data> &amigos);
    void ordenaEmail(vector<BD::data> &amigos);

} // namespace BD

class bancoDeDados {
public:

  void imprimeNomes();
  void imprimeEmail();
  void ordenaNomes();
  void ordenaEmail();
  void imprimeTudo();

  void adicionaContato(BD::data local);
  void adicionaContato(std::string, std::string);

  template <class FN> void ordena(FN extrai);
  template <typename FN> void ordena();

private:
  std::vector<BD::data> bancoInterno;
};

#endif // MIMOCHAT_BD_H
