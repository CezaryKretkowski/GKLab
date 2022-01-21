//
// Created by cezary on 15.11.2021.
//

#ifndef GKLAB_DRAWABLEOBJECT_H
#define GKLAB_DRAWABLEOBJECT_H
#include <SFML/Graphics.hpp>
class DrawableObject{
protected:
    sf::Texture ts;
    sf::Image img;
    sf::Sprite painter;
    double posX;
    double posY;
    std::string imgName;
public:
    std::string getImageName(){return imgName;}
    void setImg(std::string path);
    virtual void draw(sf::RenderWindow *super);
    virtual ~DrawableObject();
    void setPosX(double x){posX=x;};
    void setPosY(double y){posY=y;};
    double getPosX(){return posX;}
    double getPosY(){return posY;}
};
#endif //GKLAB_DRAWABLEOBJECT_H
