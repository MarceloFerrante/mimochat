//trata dados do email
//oauth2

#include "email.h"
namespace mimochat {

int conecta(int x) { return x; }

std::string conecta(BD::data d) {
  return d.servidor.ipv4; // TODO conectar rede com ipv4
}

//
//    int enviaChave(data d){
//        d.chave.publica; // TODO enviar chave publica
//        return 0;
//    }

int enviaChave(int d) { return d; }

//    template< typename T1, typename T2>
//    T2 conecta(T1 d) {
//        return d;
//    }
} // namespace mimochat
