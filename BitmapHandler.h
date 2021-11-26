//
// Created by cezar on 25.11.2021.
//

#ifndef GKLAB_BITMAPHANDLER_H
#define GKLAB_BITMAPHANDLER_H
#include <SFML/Graphics.hpp>
class BitmapHandler{
protected:
    sf::Image img;
    sf::Texture texture;
    sf::Sprite sr;
public:
    void loadFromFille(std::string path);
    void safeToFille(sf::RenderWindow* parent, std::string path);
    void draw(sf::RenderWindow* parent);

};
#endif //GKLAB_BITMAPHANDLER_H
