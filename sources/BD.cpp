//
// Created by marcelo on 25/11/2021.
//
#include "BD.h"
#include "string"
#include "listas/amigos.h"
#include "cliente/encripta.h"
#include <vector>
#include <iostream>

    void bancoDeDados::imprimeNomes(std::vector <listaAmigos::data> &bancoInterno) {
        for (auto &n: bancoInterno) {
            std::cout << n.usuario.nome << '\n';
        }
    }

    void bancoDeDados::imprimeNomes() {
        bancoDeDados::imprimeNomes(bancoInterno);
    }

    void bancoDeDados::imprimeEmail(std::vector <listaAmigos::data> &bancoInterno) {
        for (auto &n: bancoInterno) {
            std::cout << n.usuario.email << '\n';
        }
    }
    void bancoDeDados::imprimeEmail() {
        imprimeEmail(bancoInterno);
    }


    void bancoDeDados::adicionaContato(listaAmigos::data local){
        bancoInterno.push_back(local);
    }

    void bancoDeDados::adicionaContato()
    {

    }


// ver https://stackoverflow.com/questions/33379846/case-insensitive-sorting-of-an-array-of-strings
//     https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
    void bancoDeDados::ordenaNomes(std::vector <listaAmigos::data> &amigos) { //TODO transformar em template
        sort(
                amigos.begin(),
                amigos.end(),
                [](listaAmigos::data &a, listaAmigos::data &b) {
                    return lexicographical_compare(
                            a.usuario.nome.begin(), a.usuario.nome.end(),
                            b.usuario.nome.begin(), b.usuario.nome.end(),
                            [](const char &char1, const char &char2) {
                                return tolower(char1) < tolower(char2);
                            }
                    );
                }
        );
    }
    void bancoDeDados::ordenaNomes(){
        bancoDeDados::ordenaNomes(bancoInterno);
    }

    void bancoDeDados::ordenaEmail(std::vector <listaAmigos::data> &amigos) {
        sort(
                amigos.begin(),
                amigos.end(),
                [](listaAmigos::data &a, listaAmigos::data &b) {
                    return lexicographical_compare(
                            a.usuario.email.begin(), a.usuario.email.end(),
                            b.usuario.email.begin(), b.usuario.email.end(),
                            [](const char &char1, const char &char2) {
                                return tolower(char1) < tolower(char2);
                            }
                    );
                }
        );
    }

void bancoDeDados::ordenaEmail() {
    bancoDeDados::ordenaEmail(bancoInterno);
}

    void bancoDeDados::imprimeTudo(std::vector <listaAmigos::data> &amigos) {

        for (auto &n: amigos) {

            std::cout << n.usuario.nome << '\n';
            std::cout << n.usuario.email << '\n';
            std::cout << "Chave:       " << n.chave.publica << std::endl;
            std::cout << "Inicial:     " << n.texto.inicial << std::endl;

            n.texto.cifrada = encripta::cifraMensagem(n, "");
            std::cout << "Cifrada:     " << n.texto.cifrada << std::endl;

            std::string cifrada = n.texto.cifrada;
            n.texto.decifrada = encripta::decifraMensagem(n, n.texto.cifrada);
            std::cout << "Decifrada:   " << n.texto.decifrada << std::endl;
            std::cout << std::endl;
        }
    }
void bancoDeDados::imprimeTudo() {
    bancoDeDados::imprimeTudo(bancoInterno);
}

