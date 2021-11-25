#include "encripta.h"
#include "listas/amigos.h"
#include <string>
#include <random>

namespace encripta {
    int enviaChave(){
        return 0;
    }

    int recebeChave() {
        return 0;
    }

    std::string usaChave(listaAmigos::data) {
        return 0;
    }

    /* TODO olhar:
     * https://www.thecrazyprogrammer.com/2017/03/rsa-algorithm.html
     * https://cryptopp.com/#download
     * https://github.com/randombit/botan
     * https://cryptopp.com/docs/ref/class_a_e_s.html
     * https://github.com/weidai11/cryptopp
     * https://github.com/weidai11/cryptopp/releases/tag/CRYPTOPP_8_6_0
     */
    std::string cifraMensagem(listaAmigos::data& d, std::string mensagem = "")
    {
        if (mensagem.empty())
            mensagem = d.mensagem.inicial;
        std::string mensagemCifrada = mensagem; //TODO  alocar apenas espaço da mensagem cifrada, sem copiar

        const std::string chave = d.chave.privada;

        for (size_t var = 0; var < mensagem.length(); ++var) {

            mensagemCifrada [var] ^= chave[var%chave.size()]; //TODO trocar encriptacao xor por algo melhor
        }
        return mensagemCifrada;
    }

    std::string decifraMensagem(listaAmigos::data& d, std::string mensagem = "")
    {
        if (mensagem.empty())
        mensagem = d.mensagem.inicial;
        std::string mensagemCifrada = mensagem; //TODO  alocar apenas espaço da mensagem cifrada, sem copiar


        const std::string chave = d.chave.privada;

        for (size_t var = 0; var < mensagem.length(); ++var) {

            mensagemCifrada [var] ^= chave[var%chave.size()]; //TODO trocar encriptacao xor por algo melhor
        }
        return mensagemCifrada;
    }


    //fonte https://inversepalindrome.com/blog/how-to-create-a-random-string-in-cpp
    std::string random_string(std::size_t length)
    {
        const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

        std::string random_string;

        for (std::size_t i = 0; i < length; ++i)
        {
            random_string += CHARACTERS[distribution(generator)];
        }

        return random_string;
    }

}