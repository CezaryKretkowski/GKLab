//
// Created by cezar on 29.10.2021.
//

#ifndef GKLAB_MAINMENU_H
#define GKLAB_MAINMENU_H

#include <SFML/Graphics.hpp>
#include "Label.h"
#include "Button.h"
#include <SFML/Audio.hpp>

class MainMenu {
    /**Kalsa Main menu przechowuje wszytkie obiekty służące za wyświetlanie i logikę głównego menu gry takie jak:
     **/
private:
    ///Textura tła
    sf::Image background;
    ///Nagłówk W polu header
    Label header;


public:
    ///Button newGame opdowiedzialny za uruchamianie nowej gry
    Button newGame;
    ///Button loadGame opdowiedzialny za wczytanie zapisanego stanu gry
    Button loadGame;
    ///Button onlineGame opdowiedzialny za uruchomienie rozgrywki online
    Button onlineGame;
    /// Button endButton opdowiedzialny za wyjscie z gry
    Button endButton;
    sf::SoundBuffer sound;
    ///Muzyki w menu przechowywanej w polu music
    sf::Music music;
    /**Metoda ustawiająca
     *
     * @param path ścierzka do pliku zawierajca
     */
    void setBackground(std::string path);
    /**Metoda zwracjąca
     *
     * @return obraz tła
     */
    sf::Image getBackGround();
    /**Metoda zrwacjąca
     *
     * @return wskżnik na nagłówek
     */
    Label *getLabel();
    /**Metoda służaca do wczytania z pliku muzyki która natępnie ma być odtwarzana w menu
     *
     * @param path ścieżka do pliku dzwiękowego
     */
    void loadMusic(std::string path);
};

#endif //GKLAB_MAINMENU_H
