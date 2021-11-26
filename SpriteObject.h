//
// Created by cezar on 25.11.2021.
//

#ifndef GKLAB_SPRITEOBJECT_H
#define GKLAB_SPRITEOBJECT_H
#include "BitmapObject.h"
#include "AnimatedObject.h"
class SpriteObject :public BitmapObject , public AnimatedObject {
private:
    int iter=0;
public:
    void init();
    int getIterator(){return iter;};
    void  animate(sf::RenderWindow *parent,bool t)override;
    void draw(sf::RenderWindow *parent)override;
};
#endif //GKLAB_SPRITEOBJECT_H
