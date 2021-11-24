#include <email/email.h>
#include "amigos/listaAmigos.h"
//#include <cassert>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE( "mimochat" ) {
    using namespace mimochat;

    SECTION("Conexão") {
        REQUIRE(conecta(12) == 12);
        REQUIRE(conecta("teste") == "teste");
        }

    SECTION("Encriptação"){
        listaAmigos::data local;
        local.chave.publica = "ABCDE";
        local.chave.privada = "ABCDE";
        std::string mensagem_inicial = "Uma mensagem de teste";
        std::string mensagem_cifrada = encripta::cifraMensagem(mensagem_inicial, local);
        REQUIRE(encripta::decifraMensagem(mensagem_cifrada, local)) == mensagem_inicial;
    }
}
