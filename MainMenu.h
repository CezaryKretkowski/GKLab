//
// Created by cezar on 29.10.2021.
//

#ifndef GKLAB_MAINMENU_H
#define GKLAB_MAINMENU_H
#include <SFML/Graphics.hpp>
#include "Label.h"
#include "Button.h"
#include <SFML/Audio.hpp>
class MainMenu{
    /**Kalsa Main menu przechowuje wszytkie obiekty służące za wyświetlanie i logikę głównego menu gry takie jak:
     * Textura tła która jest przechowywana w polu background ,
     * Muzyki w menu przechowywanej w polu music
     * Nagłówk W polu header
     * Button newGame opdowiedzialny za uruchamianie nowej gry
     * Button loadGame opdowiedzialny za wczytanie zapisanego stanu gry
     * Button onlineGame opdowiedzialny za uruchomienie rozgrywki online
     * Button endButton opdowiedzialny za wyjscie z gry
     * **/
private:
    sf::Image background;
    Label header;


public:
    Button newGame;
    Button loadGame;
    Button onlineGame;
    Button endButton;
    sf::SoundBuffer sound;
    sf::Music music;
    void setBackground(std::string path);
    sf::Image getBackGround();
    Label* getLabel();
    void loadMusic(std::string path);
};
#endif //GKLAB_MAINMENU_H
