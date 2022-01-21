//
// Created by cezar on 29.10.2021.
//

#ifndef GKLAB_MENUFUN_H
#define GKLAB_MENUFUN_H
#include "Engine.h"
/**Metoda słuząca do wyswietlania zadeklorawanego w w pliku MainMenu.h Widoku
 * Jako parametr przyjmuje wskażnik do silnika gry dzieki czemu możliwe są wszystkie akcje silnika
 * np. ryowanie obługa klawiatóry
 * Ta metoda będzie wywoływana co każdą iteracje głównej pętli
 * Odpowiedzialna jest za logikę gry  między innymi obłsugę przycisków
 * Oraz uruchamienie poszczególnych typów gry
 * @param Wskażnik na Obiekt Engine
 * **/
void menuRun(Engine *super);
/**Metoda ODpowiedzialna jest za ustawienie parametrów widoku menu między innymi ustawienie
 * odpowiedniego tła wczytanie i uruchomienie muzyki
 * Wczytywane na tym etapie wczytywane sa rownież tekstury przycisków oraz inicjalizowane
 * niezbęden epola kasy Mainmenu
 * Metoda jest wywoływana zwsze przed staretem pętli  która wyświetla menu.
 * @param Wskażnik na Obiekt Engine
 * **/
void menuSetUp(Engine *super);
/**Metoda służąca do sprzątania pamięci oraz zerowania wskażników
 * Wywoływana jest w moencie przejścia z menu gry do innego menu lub w momencie zakończenia
 * gry
 * @param Wskażnik na Obiekt Engine
 * **/
void menuClear(Engine *super);
void menuEventSetUp(Engine *super,sf::Event e);
#endif //GKLAB_MENUFUN_H
