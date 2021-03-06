//
// Created by marcelo on 25/11/2021.
//
#include "BD.h"
#include "servidorCliente/encripta.h"
#include "string"
#include <iostream>
#include "boost/asio.hpp"

namespace BD{

    bancoDeDados::bancoDeDados() { //fazer iterador para percorrer toda as entradas
        indice = 0;
    }

    size_t bancoDeDados::size(){
        return bancoInterno.size();
    }

    void
    bancoDeDados::imprimeNomes() { // TODO fazer template
        size_t i=0;
        for (auto &n: bancoInterno) {
            std::cout << i++ << " " << n.id.nome << '\n';
        }
    }

    void
    bancoDeDados::imprimeEmail() {
        for (auto &n: bancoInterno) {
            std::cout << n.id.email << '\n';
        }
    }

    void bancoDeDados::adicionaContato(std::string &email,
                                       std::string &nome,
                                       std::string &ipv4,
                                       std::string &publica,
                                       std::string &privada,
                                       std::string &mensagem) {
        BD::dados local;
        local.id.nome = nome;
        local.id.email = email;
        local.endereco.ipv4 = ipv4;
        local.chave.publica = publica;
        local.chave.privada = privada;
        local.mensagem.simples = mensagem;
        bancoInterno.push_back(local);
    }

    void bancoDeDados::adicionaContato(std::string email, std::string nome = " ") {
        if (nome.empty())
            nome = "Anônimo";
        std::string s;
        adicionaContato(email, nome, s, s, s, s);
    }

//void
//bancoDeDados::adicionaContato(std::string email)
//{
//    //TODO:chegar validade do email;
//  bancoDeDados::adicionaContato(email, "" );
//}

// ver
// https://stackoverflow.com/questions/33379846/case-insensitive-sorting-of-an-array-of-strings
//     https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
    void
    bancoDeDados::ordenaNomes() { // TODO transformar em template
        bancoDeDados::ordena([](BD::dados &x) { return x.id.nome; });
    }

    void
    bancoDeDados::ordenaEmail() {
        bancoDeDados::ordena([](BD::dados &x) { return x.id.email; });
    }

    void
    bancoDeDados::imprimeTudo() {

        for (auto &n: bancoInterno) {

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

    void bancoDeDados::setNome(std::string &nome) {
        bancoInterno[indice].id.nome = nome;
    }

    void bancoDeDados::setEmail(std::string &email) {
        bancoInterno[indice].id.email = email;
    }

    void bancoDeDados::setChavePub(std::string &key) {
        bancoInterno[indice].chave.publica = key;
    }

    void bancoDeDados::setChavePriv(std::string &key) {
        bancoInterno[indice].chave.privada = key;
    }

    void bancoDeDados::setIpv4(std::string &ip) {
        bancoInterno[indice].endereco.ipv4 = ip;
    }

    std::string bancoDeDados::getNome(size_t indice) {
        return bancoInterno[indice].id.nome;
    }

    std::string bancoDeDados::getEmail(size_t indice) {
        return bancoInterno[indice].id.email;
    }

//TODO busca fuzzy logic https://github.com/typesense/typesense
    std::string bancoDeDados::getNome(std::string &email) {
        for (size_t n=0; n<bancoInterno.size(); ++n) {
            if (getEmail(n) == email) {
                return getNome(n);
            }
        }
    }

    std::string bancoDeDados::getIpv4(size_t indice) {
        return bancoInterno[indice].endereco.ipv4;
    }

//retorna ip a partir do email
    std::string bancoDeDados::getIpv4(std::string &email) {
        return bancoInterno[indice].endereco.ipv4; //TODO implementar busca por email, arvore binaria
    }

    void bancoDeDados::ping(std::string ipv4) {
        if(ipv4.empty())
            return;
        std::cout << "pingando " << ipv4 << " " /*<< std::this_thread::get_id()*/ << std::endl;
    }

    void bancoDeDados::pingAll() {
        boost::asio::thread_pool pool(std::thread::hardware_concurrency());

        for (auto &n: bancoInterno) {
            boost::asio::post(pool, [&n, this]() {
                ping(n.endereco.ipv4);
            });
        }
        pool.join();
        return;
    }

    void bancoDeDados::removeContato(size_t pos) {
        if (bancoInterno.empty())
            return;
        bancoInterno.erase(bancoInterno.begin() + pos);
    }

    void bancoDeDados::removeContato(std::string email) {
        //encontra indice
        for (size_t n=0; n<bancoInterno.size(); ++n) {
            if (getEmail(n) == email) {
                removeContato(n);
                return;
            }
        }
    }

    void bancoDeDados::editaContato(std::string email, std::string nome ="") {
        for (size_t n=0; n<bancoInterno.size(); ++n) {
            if (getEmail(n) == email) {
                editaContato(n, email, nome);
            }
        }
    }

    void bancoDeDados::editaContato(size_t pos, std::string email="", std::string nome ="") {
        indice = pos;
        if(!nome.empty())
            setNome(nome);
        if(!email.empty())
            setEmail(email);
    }
}