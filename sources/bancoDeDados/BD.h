//
// Created by marcelo on 25/11/2021.
//

#ifndef MIMOCHAT_BD_H
#define MIMOCHAT_BD_H

#include <string>
#include <vector>
#include "iostream"

namespace BD { //TODO remover todas as referencias ao BD e colocar como privada
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
        rede endereco;
        texto mensagem;
    };

} // namespace BD

class bancoDeDados { //fazer iterador para percorrer toda as entradas
public:

      void imprimeNomes();
      void imprimeEmail();
      void ordenaNomes();
      void ordenaEmail();
      void imprimeTudo();

      std::string getNome(size_t);

    void adicionaContato(BD::dados d);
    void adicionaContato(BD::pessoa p);
    void adicionaContato(std::string email);

    //template <class FN> void ordena(FN extrai) no include abaixo
    #include "BD.hpp" //TODO mover para o topo do arquivo. Extender classe?

private:
  std::vector<BD::dados> bancoInterno;
};

#endif // MIMOCHAT_BD_H
