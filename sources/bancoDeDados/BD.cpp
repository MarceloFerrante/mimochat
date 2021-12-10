//
// Created by marcelo on 25/11/2021.
//
#include "BD.h"
#include "servidorCliente/encripta.h"
#include "string"
#include <iostream>

bancoDeDados::bancoDeDados() { //fazer iterador para percorrer toda as entradas
    indice = 0;
}


void
bancoDeDados::imprimeNomes()
{ // TODO fazer template
  for (auto& n : bancoInterno) {
    std::cout << n.id.nome << '\n';
  }
}

void
bancoDeDados::imprimeEmail()
{
  for (auto& n : bancoInterno) {
    std::cout << n.id.email << '\n';
  }
}

void bancoDeDados::adicionaContato(std::string& email,
                                   std::string& nome,
                                   std::string& ipv4,
                                   std::string& publica ,
                                   std::string& privada,
                                   std::string& mensagem)
{
    BD::dados local;
    local.id.nome = nome;
    local.id.email = email;
    local.endereco.ipv4 = ipv4;
    local.chave.publica = publica;
    local.chave.privada =  privada;
    local.mensagem.simples = mensagem;
    bancoInterno.push_back(local);
}


void bancoDeDados::adicionaContato(std::string email, std::string nome = " ")
{
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
bancoDeDados::ordenaNomes()
{ // TODO transformar em template
  bancoDeDados::ordena([](BD::dados& x) { return x.id.nome; });
}

void
bancoDeDados::ordenaEmail()
{
  bancoDeDados::ordena([](BD::dados& x) { return x.id.email; });
}

void
bancoDeDados::imprimeTudo()
{

  for (auto& n : bancoInterno) {

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

std::string bancoDeDados::getNome(std::string &email) {
    return bancoInterno[indice].id.nome; //implementar busca por email
}

std::string bancoDeDados::getIpv4(size_t indice) {
    return bancoInterno[indice].endereco.ipv4;
}

std::string bancoDeDados::getIpv4(std::string &email) {
    return bancoInterno[indice].endereco.ipv4; //TODO implementar busca por email
}
