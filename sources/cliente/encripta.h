#ifndef ENCRIPTA_H
#define ENCRIPTA_H

#include <string>
#include "listas/amigos.h"

namespace encripta{
    int enviaChave();
    int recebeChave();
    int usaChave();
        int rsa(double p, double q);
    std::string cifraMensagem(listaAmigos::data &d, std::string mensagem );
    std::string decifraMensagem(listaAmigos::data &d, std::string mensagem);
    std::string random_string(std::size_t length);

}


#endif // ENCRIPTA_H
