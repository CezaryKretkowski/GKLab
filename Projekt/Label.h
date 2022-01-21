//
// Created by cezar on 15.10.2021.
//

#ifndef GK_LAB_LABEL_H
#define GK_LAB_LABEL_H
#include <SFML/Graphics.hpp>
#include "../Silnik/Point2D.h"
#define Path "Resource/fonts/"
/**@class Klasa reprezętująca napis
 *
 */
class Engine;
class Label {
    private:
        ///Tekst jak ma być wyświetlany
        std::string text;
        ///Czcionka jaką ma być wypisany tekst
        sf::Font font;
        ///Rozmiar czcionki
        int size;
        ///Kolor Czcionki
        sf::Color color;
        ///Pozycja napisu
        Point2D posytion;

    public:
        ///Obiekt reprezętujący napis
       sf::Text label;
        /**Konstruktor klasy
         * @param text ciąg znaków jaki ma być wypisany na ekranie
         * @param size rozmiar czcionki
         * @param font czcionka
         * @param posX pozycja x
         * @param posY pozycja
         * @param color kolor napisu
         */
        Label(std::string  = "", int = 24, std::string  = "Begoky.ttf", int =0,int =0,
              sf::Color  = sf::Color::White);
        /**Metoda ustawiająca
         *
         * @param text Nowy tekst który ma zostać wypisany na ekranie
         */
        void setString(std::string text);
        /**Metoda ustawiająca
         *
         * @param fontName ścieżka do pliku z czcionką
         */
        void setFont(std::string fontName);
        /**Metoda ustawiająca
         *
         * @param color Nowe kolor napisu
         */
        void setColor(sf::Color color);
        /**Metoda ustwiająca
         *
         * @param size Rozmiar czcionki
         */
        void setSize(int size);
        /**Metoda ustwiająca
         *
         * @param p nowa pozycycja
         */
        void setPos(Point2D p);
        /**Metoda zwrcająca
         *
         * @return zwraca obiket zawierjący teks rozmiar i rodzaj czcionki
         */
        sf::Text getText() { return this->label; }
        /**Metoda zwracająca
         *
         * @return tekst napisu
         */
        std::string getString() { return this->text; }
        /**Metoda zwracjąca
         *
         * @return rozmiar tekstu
         */
        int getSize() { return this->size; }
        /**Metoda zwracjąca
         *
         * @return pozycje teksu
         */
        Point2D getPos() { return this->posytion; }
        /**Meoda Zwracjąca
         *
         * @return zwraca kolor
         */
        sf::Color getColor() { return this->color; }

        /**Przeciążenie operatora przypisania dla klasy label
         *
         * @param l Obiekt Label
         * @return Nowy obiekt labael
         */
        Label operator=(Label l) {
            this->label = l.label;
            this->posytion = l.posytion;
            this->size = l.size;
            this->color = l.color;
            this->text = l.text;
            this->font = l.font;
        }

};

#endif //GK_LAB_LABEL_H
