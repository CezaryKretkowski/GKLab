//
// Created by cezar on 29.10.2021.
//
#include "MainMenu.h"
void MainMenu::setBackground(std::string filName) {
    /**Metoda setBackground służy do ustawienia tła jako Parametr przyjmuję scieżkę do pliku z tłem   **/
    std::string path="Resource/image/"+filName;
    this->background.loadFromFile(path);
}
sf::Image MainMenu::getBackGround() {
    ///Metoda Zwracająca background tło
    return this->background;
}
Label* MainMenu::getLabel() {
    ///Metoda zwracająca nagłówek
    return &header;
}
void MainMenu::loadMusic(std::string path){
    //sound.loadFromFile(path);
    ///Metoda służaca do wczytania z pliku muzyki która natępnie ma być odtwarzana w menu
    music.openFromFile("Resource/Sounds/bensound-epic.ogg");
    music.setVolume(30.00);
    music.setLoop(true);
}
