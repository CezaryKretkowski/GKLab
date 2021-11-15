//
// Created by cezar on 12.11.2021.
//

#ifndef GKLAB_MISSILE_H
#define GKLAB_MISSILE_H
#include <SFML/Graphics.hpp>
class Missile{

private:
    float posX;
    float posY;
    float rot;
    sf::Sprite painter;
    sf::Image img;
    sf::Texture tx;
    int count;
public:

    Missile(float =0.0,float =0.0,int =0);
    void setImg(std::string path);
    void setPosX(float x){posX=x;};
    void setPosY(float y){posY=y;};
    void setCount(int i){count=i;};
    float getX(){return posX;}
    float getY(){return posY;}
    float getRot(){return rot;}
    float getCount(){return count;}
    void draw(sf::RenderWindow *parent);
    void setRot(float rot){this->rot=rot;}
};
#endif //GKLAB_MISSILE_H
