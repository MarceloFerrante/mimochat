//
// Created by marcelo on 06/01/2022.
//

#ifndef MIMOCHAT_INTERFACEIMGUI_H
#define MIMOCHAT_INTERFACEIMGUI_H

#include "bancoDeDados/BD.h"
#include "imgui.h"

//static void menuAmigos(bancoDeDados& listaAmigos);
////static void menuChat();
namespace interface{
    class menu{
    public:
        //menus
        void Amigos(BD::bancoDeDados& bd);
        void Chat();

        // Janelas
        void adicionaPessoa(BD::bancoDeDados& bd);

        void janelaChat();

        void janelinha();

    private:
        bool    *janelaAdicionaPessoa,
                *janelaJanelinha,
                *janelaTexto;
    };

}

#endif //MIMOCHAT_INTERFACEIMGUI_H

