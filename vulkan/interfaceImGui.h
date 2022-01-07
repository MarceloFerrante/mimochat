//
// Created by marcelo on 06/01/2022.
//

#ifndef MIMOCHAT_INTERFACEIMGUI_H
#define MIMOCHAT_INTERFACEIMGUI_H

#include "bancoDeDados/BD.h"
#include "imgui.h"

//static void menuAmigos(bancoDeDados& listaAmigos);
////static void menuChat();

class menu{
public:
    void Amigos(BD::bancoDeDados& bd) {
        if (ImGui::Button("Adicionar"))
            ImGui::OpenPopup("Adicionar");

        if (ImGui::BeginPopup("Adicionar") ) {
            adicionaPessoa(bd);
            ImGui::EndPopup();
        }

        if (ImGui::MenuItem("Procurar", "Ctrl+F"))
        {
            //TODO Procurar pessoa na lista
        }

        if (ImGui::MenuItem("Testar conexões")){
            bd.pingAll();
        }
    }

    void Chat() {
        if (ImGui::MenuItem("Procurar", "CTRL+F")) {
        }
        if (ImGui::MenuItem("Limpar Chat")) {
        }
    }


    // Janelas
    void adicionaPessoa(BD::bancoDeDados& bd);

    void janelinha()
    {
        ImGui::SetNextWindowSize(ImVec2(430, 450), ImGuiCond_FirstUseEver);
        if (!ImGui::Begin("Example: Property editor", janelaJanelinha))
        {
            ImGui::End();
            return;
        }

        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));
        if (ImGui::BeginTable("split", 2, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_Resizable))
        {
            // Iterate placeholder objects (all the same data)
            for (int obj_i = 0; obj_i < 4; obj_i++)
            {
                ImGui::Button("teste");
//            ShowPlaceholderObject("Object", obj_i);
                ImGui::Separator();
            }
            ImGui::EndTable();
        }
        ImGui::PopStyleVar();
        ImGui::End();
    }

private:
    bool    *janelaAdicionaPessoa,
            *janelaJanelinha;

};

#endif //MIMOCHAT_INTERFACEIMGUI_H

