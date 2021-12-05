//
// Created by cezar on 19.11.2021.
//
#include <fstream>
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
void GameView::pauseKey(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
        std::cout<<"works"<<std::endl;

            keyPressed=true;

    }else{
        keyPressed=false;
    }

    if(keyPressed)
        if(pause)
            pause=false;
        else
            pause=true;

}
void GameView::saveToFile(Point2D p1Pos, Point2D p2Pos, std::string skin1, std::string skin2,
                          std::list<std::string> obs, std::list<Point2D> oPos, int Point1, int Point2) {
    std::fstream plik;
    plik.open("Saves/save1.txt",std::ios::in);
    if(plik.is_open()){
       // plik >> p1Pos.getX();

    }



}
