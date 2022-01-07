//
// Created by marcelo on 06/01/2022.
//

#include "interfaceImGui.h"

void menu::adicionaPessoa(BD::bancoDeDados &bd) {
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


