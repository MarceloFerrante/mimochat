//
// Created by marcelo on 25/11/2021.
//

#ifndef MIMOCHAT_BD_H
#define MIMOCHAT_BD_H

#include <string>
#include <vector>
#include "iostream"

namespace BD { //TODO remover todas as referencias externas ao BD e colocar como privada
    using namespace std;

    typedef struct pessoa {
        string email,
                nome; // TODO pegar nome a partir do email
    } pessoa;

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
    bancoDeDados();

    void imprimeNomes();

    void imprimeEmail();

    void ordenaNomes();

    void ordenaEmail();

    void imprimeTudo();

    void setNome(std::string &nome);

    void setEmail(std::string &email);

    void setChavePub(std::string &key);

    void setChavePriv(std::string &key);

    void setIpv4(std::string &ip);

    std::string getNome(size_t indice); //retorna nome do endereço []
    std::string getNome(std::string &email); //retorna nome do email. Usar map? <nome,email>?

    std::string getIpv4(size_t indice);

    std::string getIpv4(std::string &email);

//    void adicionaContato(BD::dados d);
    void adicionaContato(std::string email, std::string nome);

    void adicionaContato(std::string email);

    void adicionaContato(std::string &email, std::string &nome, std::string &ipv4, std::string &publica,
                         std::string &privada, std::string &mensagem);

    //template <class FN> void ordena(FN extrai) no include abaixo
#include "BD.hpp" //TODO mover para o topo do arquivo. Extender classe?

private:

    std::vector<BD::dados> bancoInterno;
    size_t indice;
    size_t size_;

};

#endif // MIMOCHAT_BD_H
