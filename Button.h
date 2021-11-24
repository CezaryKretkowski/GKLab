//
// Created by cezar on 29.10.2021.
//

#ifndef GKLAB_BUTTON_H
#define GKLAB_BUTTON_H
#include <SFML/Graphics.hpp>
class Button{
private:
    sf::Image s1,s2,s3;
    sf::Texture source;

    float posX;
    float posY;
    int width;
    int hight;
    int x;
    int y;

public:
    Button();
    void setImages(std::string p1,std::string p2,std::string p3);
    void onSelected(sf::RenderWindow * parent,sf::Event event);
    bool onClicked(sf::RenderWindow * parent,sf::Event event);
    void setWidth(int w){this->width=w;}
    void setHight(int h){this->hight=h;}
    int getWidth(){return width;}
    int getHight(){return hight;}
    void setPosX(float x){posX=x;}
    void setPosY(float y){posY=y;}
    float getPosX(){return posX;}
    float getPosY(){return posY;}
    bool (*toDo)(sf::RenderWindow *parent )=NULL;
    void overrideMouseMove(bool (*onToDo)(sf::RenderWindow *parent));
    sf::Sprite painer;
};
#endif //GKLAB_BUTTON_H
