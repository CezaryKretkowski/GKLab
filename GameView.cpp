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

std::vector<Obstycle> *GameView::getObtycleList() {
    return &obstycle;
}

void GameView::drawObstycles(sf::RenderWindow *parent) {
    std::vector<Obstycle>::iterator i;
    i = this->obstycle.begin();
    for (i; i < obstycle.end(); i++) {
        i->draw(parent);
    }
}

void GameView::pauseKey() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        std::cout << "works" << std::endl;

        keyPressed = true;

    } else {
        keyPressed = false;
    }

    if (keyPressed)
        if (pause)
            pause = false;
        else
            pause = true;

}

void
GameView::saveToFile(Point2D p1Pos, Point2D p2Pos, std::string skin1, std::string skin2, std::vector<Obstycle> *obs,
                     int Point1, int Point2) {
    std::fstream plik;
    plik.open("../Resource/Save/save1.txt", std::ios::out);
    std::string endl = "\n";
    std::vector<Obstycle>::iterator i;
    if (plik.good() == true) {
        plik << p1Pos.getX() << std::endl;
        plik << p1Pos.getY() << std::endl;
        plik << p2Pos.getX() << std::endl;
        plik << p2Pos.getY() << std::endl;
        plik << skin1 << std::endl;
        plik << skin2 << std::endl;
        plik << Point1 << std::endl << Point2 << std::endl;
        for (i = obs->begin(); i != obs->end(); i++) {
            plik << i->getImageName() << std::endl;
            plik << i->getPosX() << std::endl << i->getPosY() << std::endl;
        }



    }
    plik.close();


}

void GameView::loadFromFile() {
    std::fstream plik;
    plik.open("../Resource/Save/save1.txt", std::ios::in);
    float x1;
    float y1;
    float x2;
    float y2;
    std::string name;
    int p1,p2;
    std::string skin1, skin2;
    std::string endl = "\n";
    std::vector<Obstycle>::iterator i;
    if (plik.good() == true) {

        plik >> x1;
        plik >> y1;
        plik >> x2;
        plik >> y2;
        plik >> skin1;
        plik >> skin2;
        plik >> p1;
        plik >> p2;
        player1.setUpTank(Point2D(x1, y1), getObtycleList(), skin1, "Resource/image/Missile.png", sf::Keyboard::W,
                          sf::Keyboard::S, sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::Space);
        player2.setUpTank(Point2D(x2, y2), getObtycleList(), skin2, "Resource/image/Missile.png", sf::Keyboard::Up,
                          sf::Keyboard::Down, sf::Keyboard::Right, sf::Keyboard::Left, sf::Keyboard::P);
        player1.setPoints(p1);
        player2.setPoints(p2);


        while (!plik.eof()){
            plik>>name;
            plik >> x1;
            plik >> y1;
            Obstycle testeing;
            testeing.setPosY(y1);
            testeing.setPosX(x1);
            testeing.setImg(name);
            addObstycle(testeing);

        }

    }
    plik.close();

}
