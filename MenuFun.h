//
// Created by cezar on 29.10.2021.
//

#ifndef GKLAB_MENUFUN_H
#define GKLAB_MENUFUN_H
#include "Engine.h"
///Plik zawiera deklaracje statycznych funkcji wymaganych do obsługi głównego menu
void menuRun(Engine *super);
void menuSetUp(Engine *super);
void menuClear(Engine *super);
void menuEventSetUp(Engine *super,sf::Event e);
#endif //GKLAB_MENUFUN_H
