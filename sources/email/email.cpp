//trata dados do email
//oauth2

#include "email.h"
namespace mimochat {

int conecta(int x) { return x; }

std::string conecta(BD::dados d) {
  return d.servidor.ipv4; //
}

//
//    int enviaChave(dados d){
//        d.chave.publica; //
//        return 0;
//    }

int enviaChave(int d) { return d; }

//    template< typename T1, typename T2>
//    T2 conecta(T1 d) {
//        return d;
//    }
} // namespace mimochat
