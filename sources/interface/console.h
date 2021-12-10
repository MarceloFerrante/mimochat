//
// Created by marcelo on 25/11/2021.
//

#ifndef MIMOCHAT_CONSOLE_H
#define MIMOCHAT_CONSOLE_H
#include "iostream"
#include "vector"
#include "bancoDeDados/BD.h"
class console
{
public:
    console();
    void draw();
    char opcao(bancoDeDados bd);
private:
    void select();
    void novelo();
    std::string menu_principal;

};

#endif // MIMOCHAT_CONSOLE_H
