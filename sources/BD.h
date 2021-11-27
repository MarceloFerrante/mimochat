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

    typedef struct pessoa {
        string email,
                nome; // TODO pegar nome a partir do email
    }pessoa;

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

    struct dados {
        pessoa id;
        chaves chave;
        rede servidor;
        texto mensagem;
    };

} // namespace BD

class bancoDeDados {
public:

  void imprimeNomes();
  void imprimeEmail();
  void ordenaNomes();
  void ordenaEmail();
  void imprimeTudo();

  void adicionaContato(BD::dados local);
  void adicionaContato(std::string);
  void adicionaContato(BD::pessoa p);

//  template <class FN> void ordena(FN extrai);
  template <typename FN> void ordena();
    template <class FN> void ordena(FN extrai) {
        sort(bancoInterno.begin(), bancoInterno.end(),
             [extrai](BD::dados &a, BD::dados &b) {
                 return lexicographical_compare(
                         extrai(a).begin(), extrai(a).end(),
                         extrai(b).begin(), extrai(b).end(),
                         [](const char &char1, const char &char2) {
                             return tolower(char1) < tolower(char2);
                         });
             });
    }


private:
  std::vector<BD::dados> bancoInterno;
};

#endif // MIMOCHAT_BD_H
