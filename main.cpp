#include <iostream>
#include "Engine.h"
#include "MenuFun.h"
#include "PrimitiveRenderer.h"
void primityvRederfun(Engine *parent){
    PrimitiveRenderer render;
    //render.drawCircle(parent,sf::Color::Red,50);
    Point2D p1(200.0,200.0);
    Point2D p2(200.0,100.0);
    parent->clear(sf::Color::Black);
    render.drawLineMain(parent->getFrame(),sf::Color::Magenta,p2,p1);

    p1.setX(200.0);
    p1.setY(100.0);
    p2.setX(45);
    p2.setY(59.7);
    render.drawLineMain(parent->getFrame(),sf::Color::Magenta,p1,p2);

    p1.setX(45.0);
    p1.setY(59.7);
    p2.setX(40);
    p2.setY(200);
    render.drawLineMain(parent->getFrame(),sf::Color::Magenta,p1,p2);

    p1.setX(40);
    p1.setY(200);
    p2.setX(160);
    p2.setY(150);
    render.drawLineMain(parent->getFrame(),sf::Color::Magenta,p1,p2);

    p1.setX(160);
    p1.setY(150);
    p2.setX(200);
    p2.setY(200);
    render.drawLineMain(parent->getFrame(),sf::Color::Magenta,p1,p2);

    render.drawPiksel(parent->getFrame(),sf::Color::Magenta,200.0,200.0);
    render.drawCircle(parent->getFrame(),sf::Color::Red,50,260.0,200.0);
    render.drawOctagon(parent->getFrame(), sf::Color::Yellow, 50, 400, 200);
    render.drawPolygon(parent->getFrame(), sf::Color::Green, 50, 300, 300);
}
void move(sf::RenderWindow *parent,MouseListener *This){
    std::cout<<"X= "<<This->getX()<<"Y= "<<This->getY()<<std::endl;
}
void clicked(sf::RenderWindow *parent,MouseListener *This){
    std::cout<<"click"<<std::endl;
}
void Relesed(sf::RenderWindow *parent,MouseListener *This){
    std::cout<<"relesed"<<std::endl;
}
void keyRelesed(Engine *parent){

    parent->clear();
}

int main() {
    Engine engine;
    engine.overrideSetUpFun(&menuSetUp);
    engine.overrideRunFun(&menuRun);

//   KeyListener ks(sf::Keyboard::A,&primityvRederfun);
  // ks.overrideRelesedFun(&keyRelesed);
  // engine.addKeyListener(ks);
    //MouseListener ml;
   // ml.overrideMousePressed(&clicked,LeftMouseButton);
    //ml.overrideMouseMove(&move);
    //ml.overrideMouseReleased(&Relesed,LeftMouseButton);
    //engine.listener=&ml;
    engine.init(800,600,WindowMode,false, true,false);
    return 0;
}
