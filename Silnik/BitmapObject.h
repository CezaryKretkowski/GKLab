//
// Created by cezar on 25.11.2021.
//

#ifndef GKLAB_BITMAPOBJECT_H
#define GKLAB_BITMAPOBJECT_H
#include "DrawableObject.h"
#include <iterator>
#include "Point2D.h"
#include <list>

class BitmapObject: public DrawableObject{
protected:
    std::list<sf::Image> imges;
    std::list<Point2D> points;
    std::list<sf::Image>::iterator i;
    std::list<Point2D>::iterator number;
public:


    std::list<sf::Image>* getImageList();
    sf::Image* getImage(int idex);
    void addImage(sf::Image img,Point2D p);
    void deleteImage();
    void draw(sf::RenderWindow *super)override;
};
#endif //GKLAB_BITMAPOBJECT_H
