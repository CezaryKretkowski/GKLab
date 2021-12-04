//
// Created by cezar on 19.11.2021.
//
#include "Player.h"
#include "Obstycle.h"
void Player::setUpTank(std::vector<Obstycle>* obstycle,std::string skin,std::string missile,sf::Keyboard::Key up,sf::Keyboard::Key down,sf::Keyboard::Key left
                       ,sf::Keyboard::Key right,sf::Keyboard::Key fire) {
    tank.setSkin(skin);
    tank.setPosX(100.0);
    tank.setPosY(100.0);
    tank.setAngel(0.0);
    tank.ofset.x=15;
    tank.ofset.y=25;
    tank.setUpKey(up);
    tank.setDownKey(down);
    tank.setLeftKey(left);
    tank.setRightKey(right);
    tank.setFireKey(fire);
    tank.getMissile()->setImg(missile);
    tank.obstycleList=obstycle;

}
void Player::setUpTank(Point2D offset,Point2D pos,std::vector<Obstycle>* obstycle,std::string skin,std::string missile,sf::Keyboard::Key up,sf::Keyboard::Key down,sf::Keyboard::Key left
        ,sf::Keyboard::Key right,sf::Keyboard::Key fire) {
    tank.setSkin(skin);
    tank.setPosX(pos.getX());
    tank.setPosY(pos.getY());
    tank.setAngel(0.0);
    tank.ofset.x=offset.getX();
    tank.ofset.y=offset.getY();
    tank.setUpKey(up);
    tank.setDownKey(down);
    tank.setLeftKey(left);
    tank.setRightKey(right);
    tank.setFireKey(fire);
    tank.getMissile()->setImg(missile);
    tank.obstycleList=obstycle;

}
Player::Player() {
    this->points=10;
}
int Player::getPoints() {
    return this->points;
}
void Player::setPoints(int points) {
    this->points=points;
}
