//
// Created by marcelo on 06/01/2022.
//

#include "interfaceImGui.h"
#include "bancoDeDados/BD.h"

#include "imgui.h"
class menu{
public:
    void Amigos(bancoDeDados& bd) {
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
    void adicionaPessoa(bancoDeDados& bd)
    {
        ImGui::SetNextWindowSize(ImVec2(300, 100), ImGuiCond_Always);
        if (!ImGui::Begin("Adicionar contato:", janelaAdicionaPessoa))
        {
            ImGui::End();
            return;
        }
        std::string nome, email;
        email.reserve(128);
        nome.reserve(64);

        {
            ImGui::Text("Email"); ImGui::SameLine();
            ImGui::InputText("##edit", email.begin().base(), email.capacity());
            ImGui::Text("Nome"); ImGui::SameLine();
            ImGui::InputText("##edit1", nome.begin().base(), nome.capacity());
            if (ImGui::Button("Adiciona")) {
                bd.adicionaContato(email, nome);
                ImGui::CloseCurrentPopup();
            }
            ImGui::SameLine();
            if (ImGui::Button("Cancela"))
                ImGui::CloseCurrentPopup();
        }
        ImGui::End();
    }

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

