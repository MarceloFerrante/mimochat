//trata dados do email
/* https://github.com/google/gmail-oauth2-tools/tree/master/java
 * oauth2 https://github.com/sirikata/liboauthcpp
 * https://github.com/d99kris/nmail
 */
#include "email.h"

namespace mimochat {

    int conecta(int x) { return x; }

    std::string conecta(BD::dados d) {
        return d.endereco.ipv4; //
    }
//
//std::string conecta(bancoDeDados bd){
//    return 0;
//}

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
