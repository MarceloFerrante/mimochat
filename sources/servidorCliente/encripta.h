#ifndef ENCRIPTA_H
#define ENCRIPTA_H

#include <string>
#include "bancoDeDados/BD.h"

namespace encripta {

    int enviaChave();

    int recebeChave();

    int usaChave();

    int rsa(double p, double q);

    std::string cifraMensagem(BD::dados &d, std::string mensagem);

    std::string decifraMensagem(BD::dados &d, std::string mensagem);

    std::string random_string(std::size_t length);

} // namespace encripta

#endif // ENCRIPTA_H
