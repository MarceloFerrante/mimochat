//
// Created by marcelo on 24/11/2021.
//

#ifndef MIMOCHAT_CLIENTE_H
#define MIMOCHAT_CLIENTE_H

#include "bancoDeDados/BD.h"

int enviaMensagem(BD::dados &d);

int pingAll(bancoDeDados &bd);

#endif //MIMOCHAT_CLIENTE_H
