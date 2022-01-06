//
// Created by marcelo on 25/11/2021.
//

#include "console.h"
#include <iostream>
#include "bancoDeDados/BD.h"
#include "servidorCliente/cliente.h"

console::console() {

    menu_principal = \
    "            C H A T        \n\
    Q Sair                      \n\
    1 Adicionar contato         \n\
    2 Remover contato           \n\
    3 Checar conexões           \n\
    4 Imprimir contatos         \n";

    //TODO limpar tela
}

void console::draw() {
    //desenha menus
    std::cout << menu_principal;
}

char console::opcao(bancoDeDados& bd) {
    using namespace std;

    string s;
    cin >> s;
    char opcao = s.back();
    if (opcao == 'Q' || opcao == 'q') return 0;

    switch (opcao) {
        case '1': {
            string nome, email;
            std::cout << "Opção " << opcao << endl;
            cout << "Digite o email da pessoa?\n";
            cin >> email;
            cout << "Qual o nome dela?\n";
            cin >> nome;
            bd.adicionaContato(email, nome);
            break;
        }
        case '2': {
            std::cout << "Opção " << opcao << endl;
            bd.imprimeNomes();

            cout << "Qual contato apagar?\n";
            string str;
            cin >> str;

            bd.removeContato(stoi(str));
        }
            break;

        case '3': {
            std::cout << "Opção " << opcao << endl;
            bd.pingAll();
        }
            break;

        case '4': {
            bd.imprimeNomes();
            break;
        }

        default:
            std::cout << "Opcao inválida";
    }
    std::cout << std::endl;

    return opcao;
}
