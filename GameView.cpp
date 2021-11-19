//
// Created by cezar on 19.11.2021.
//
#include "GameView.h"

Obstycle GameView::getObstycle(int index) {
    return this->obstycle[index];
}
void GameView::addObstycle(Obstycle o) {
    obstycle.push_back(o);

}
std::vector<Obstycle>* GameView::getObtycleList() {
    return &obstycle;
}
void GameView::drawObstycles(sf::RenderWindow *parent) {
    std::vector<Obstycle>::iterator i;
    i=this->obstycle.begin();
    for(i;i<obstycle.end();i++){
        i->draw(parent);
    }
}
