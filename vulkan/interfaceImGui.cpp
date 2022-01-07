//
// Created by marcelo on 06/01/2022.
//

#include "interfaceImGui.h"
namespace interface{
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
            ImGui::InputText("##editEmail", email.begin().base(), email.capacity());
            ImGui::Text("Nome"); ImGui::SameLine();
            ImGui::InputText("##editNome", nome.begin().base(), nome.capacity());
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

    void menu::Chat() {
        if (ImGui::MenuItem("Procurar", "CTRL+F")) {
        }
        if (ImGui::MenuItem("Limpar Chat")) {
        }
    }

    void menu::Amigos(BD::bancoDeDados& bd) {
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
    void menu::janelinha()
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
//                  ShowPlaceholderObject("Object", obj_i);
                ImGui::Separator();
            }
            ImGui::EndTable();
        }
        ImGui::PopStyleVar();
        ImGui::End();
    }

    void menu::janelaChat()
    {
        ImGui::SetNextWindowSize(ImVec2(520, 600), ImGuiCond_FirstUseEver);
        if (!ImGui::Begin("Example: Long text display", janelaTexto))
        {
            ImGui::End();
            return;
        }

        static int test_type = 0;
        static ImGuiTextBuffer log;
        static int lines = 0;
        ImGui::Text("Printing unusually long amount of text.");
        ImGui::Combo("Test type", &test_type,
                     "Single call to TextUnformatted()\0"
                     "Multiple calls to Text(), clipped\0"
                     "Multiple calls to Text(), not clipped (slow)\0");
        ImGui::Text("Buffer contents: %d lines, %d bytes", lines, log.size());
        if (ImGui::Button("Clear")) { log.clear(); lines = 0; }
        ImGui::SameLine();
        if (ImGui::Button("Add 1000 lines"))
        {
            for (int i = 0; i < 1000; i++)
                log.appendf("%i The quick brown fox jumps over the lazy dog\n", lines + i);
            lines += 1000;
        }
        ImGui::BeginChild("Log");
        switch (test_type)
        {
            case 0:
                // Single call to TextUnformatted() with a big buffer
                ImGui::TextUnformatted(log.begin(), log.end());
                break;
            case 1:
            {
                // Multiple calls to Text(), manually coarsely clipped - demonstrate how to use the ImGuiListClipper helper.
                ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
                ImGuiListClipper clipper;
                clipper.Begin(lines);
                while (clipper.Step())
                    for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; i++)
                        ImGui::Text("%i The quick brown fox jumps over the lazy dog", i);
                ImGui::PopStyleVar();
                break;
            }
            case 2:
                // Multiple calls to Text(), not clipped (slow)
                ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
                for (int i = 0; i < lines; i++)
                    ImGui::Text("%i The quick brown fox jumps over the lazy dog", i);
                ImGui::PopStyleVar();
                break;
        }
        ImGui::EndChild();
        ImGui::End();
    }
}