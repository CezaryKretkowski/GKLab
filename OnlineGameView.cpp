//
// Created by cezar on 01.01.2022.
//
#include "OnlineGameView.h"

void OnlineGameView::addObstycle(Obstycle o) {
    obstycle.push_back(o);

}

std::vector<Obstycle> *OnlineGameView::getObtycleList() {
    return &obstycle;
}

void OnlineGameView::drawObstycles(sf::RenderWindow *parent) {
    std::vector<Obstycle>::iterator i;
    i = this->obstycle.begin();
    for (i; i < obstycle.end(); i++) {
        i->draw(parent);
    }
}
