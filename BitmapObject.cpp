//
// Created by cezar on 25.11.2021.
//
#include "BitmapObject.h"

std::list<sf::Image> *BitmapObject::getImageList() {
    return &imges;
}

sf::Image* BitmapObject::getImage(int index) {
    sf::Image *tmp=NULL;
    int w;
    i=imges.begin();
    while (i!=imges.end()){
        if(w==index)
            *tmp = *i;

        w++;
        i++;

    }
    return tmp;

}

void BitmapObject::addImage(sf::Image img,Point2D p) {
    imges.push_front(img);
    points.push_front(p);
}

void BitmapObject::deleteImage() {
    imges.pop_back();
    points.pop_back();
}

void BitmapObject::draw(sf::RenderWindow *super) {
    number=points.begin();
    this->ts.loadFromImage(*imges.begin());
    for(i=imges.begin();i!=imges.end();i++){
        this->ts.update(*i);
        painter.setTexture(ts);
        this->painter.setPosition(number->getX(),number->getY());
        super->draw(painter);
                number++;
    }
}

