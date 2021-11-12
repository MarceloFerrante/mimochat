#include <iostream>
#include "email.h"

namespace mimochat {
    int conecta(int  x) {
        return x;
    }
    int enviaChave(){
        return 0;
    }

    struct emailData{
        string usuario;
        string endereço;
        string corpo;
    };

    struct chaves{
        string chavePublica;
        string chavePrivada;
    };

    struct rede{
        string ipv6;
        string ipv4;
    };

    struct data{
        emailData email;
        chaves c;
        rede ip;
    };
}
