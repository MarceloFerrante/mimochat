//
// Created by marcelo on 25/11/2021.
//

#ifndef MIMOCHAT_BD_H
#define MIMOCHAT_BD_H

#include <string>
#include <vector>
#include "iostream"

namespace BD {
    //TODO remover todas as referencias externas ao BD e colocar como privada
//    using namespace std;

    typedef struct pessoa {
        std::string email,
                nome; // TODO pegar nome a partir do email
    } pessoa;

    struct chaves {
        std::string publica, privada;
    };

    struct rede {
        std::string ipv4;
        u_int16_t porta;
    };

    struct texto {
        std::string simples, cifrada, decifrada;
    };

    struct dados {
        pessoa id;
        chaves chave;
        rede endereco;
        texto mensagem;
    };

//TODO carregar e salvar em arquivo
//fazer iterador para percorrer todas as entradas

    class bancoDeDados {
    public:
        bancoDeDados();

        size_t size();

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

        void ping(std::string ipv4);
        void pingAll();

        std::string getNome(size_t indice); //retorna nome do endereço []
        std::string getNome(std::string &email); //retorna nome do email. Usar map? <nome,email>?

        std::string getEmail(size_t indice);

        std::string getIpv4(size_t indice);

        std::string getIpv4(std::string &email);

//    void adicionaContato(BD::dados d);
        void adicionaContato(std::string email, std::string nome);

        void adicionaContato(std::string email);

        void adicionaContato(std::string &email, std::string &nome, std::string &ipv4, std::string &publica,
                             std::string &privada, std::string &mensagem);

        void removeContato(size_t pos);
        void removeContato(std::string nome);

        template<class FN>
        void ordena(FN extrai);

        template<class FN>
        void imprime(FN extrai);

    private:

        std::vector<BD::dados> bancoInterno;
        size_t indice;
        size_t size_;

    };

} // namespace BD


#include "BD.hpp" //TODO mover para o topo do arquivo. Extender classe?

#endif // MIMOCHAT_BD_H
