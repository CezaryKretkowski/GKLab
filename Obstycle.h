//
// Created by cezar on 19.11.2021.
//

#ifndef GKLAB_OBSTYCLE_H
#define GKLAB_OBSTYCLE_H
#include "DrawableObject.h"
class Obstycle :public DrawableObject
{
public:
  virtual void draw(sf::RenderWindow *super) override{
      painter.setPosition(posX,posY);
      super->draw(this->painter);
  }
  ~Obstycle();
  sf::Image getImage();

};
#endif //GKLAB_OBSTYCLE_H
