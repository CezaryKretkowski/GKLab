//
// Created by cezar on 15.10.2021.
//

#ifndef GK_LAB_LABEL_H
#define GK_LAB_LABEL_H
#include <SFML/Graphics.hpp>
#include "Point2D.h"
#define Path "Resource/fonts/"
class Engine;
class Label {
    private:
        std::string text;
        sf::Font font;
        int size;

        sf::Color color;
        Point2D posytion;

    public:

       sf::Text label;
        Label(std::string  = "", int = 24, std::string  = "Begoky.ttf", int =0,int =0,
              sf::Color  = sf::Color::White);

        void setString(std::string text);

        void setFont(std::string fontName);

        void setColor(sf::Color color);

        void setSize(int size);

        void setPos(Point2D p);

        sf::Text getText() { return this->label; }

        std::string getString() { return this->text; }

        int getSize() { return this->size; }

        Point2D getPos() { return this->posytion; }

        sf::Color getColor() { return this->color; }


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
