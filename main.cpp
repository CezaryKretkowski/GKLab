#include <iostream>
#include "Engine.h"
#include "DemoFun.h"
#include "MenuFun.h"
#include "Button.h"
#include "PrimitiveRenderer.h"
#include "LineSegment.h"
#include "GameFun.h"
#include "LineShape.h"
#include "BitmapHandler.h"
#include "BitmapObject.h"
#include "PlayerObject.h"
float x,y;
Button button1;
Button button2;
BitmapObject tlo;
void runPrimitiveRender(Engine*super){
    PrimitiveRenderer r;
    std::list<Point2D> ls;
    Point2D a(220,10);
    Point2D b(320,120);
    r.drawCircle(super->getFrame(),sf::Color::Magenta,50,20,20);
    r.drawLineMain(super->getFrame(),sf::Color::Magenta,a,b);
    r.drawTriangle(super->getFrame(),sf::Color::White,60,130,20);
    r.drawElispeAlg(super->getFrame(),400,80,80,50,sf::Color::Green);
    Point2D a1(550,40);
    ls.push_front(a1);
    a1.setX(550);a1.setY(140);
    ls.push_front(a1);
    a1.setX(750);a1.setY(140);
    ls.push_front(a1);
    a1.setX(650);a1.setY(120);
    ls.push_front(a1);
    a1.setX(750);a1.setY(40);
    ls.push_front(a1);
    a1.setX(550);a1.setY(40);
    ls.push_front(a1);
    r.drawSegment(super->getFrame(),sf::Color::Red,ls);

}

void ecapeEndDemo(Engine *parent){
    parent->setEnd(false);
    parent->getFrame()->close();
    std::cout<<"działa"<<std::endl;
}
void setUP(Engine*super){
    sf::Image s1;
    Point2D p1(0.0);
    s1.loadFromFile("Resource/image/tlom.jpg");
    tlo.setImg("Resource/image/tlom.jpg");
    tlo.addImage(s1,p1);

    button1.setPosX(100);
    button1.setPosY(100);
    button1.setHight(50);
    button1.setWidth(200);
    button1.setImages("Resource/image/Button1.png","Resource/image/Button1Se.png","Resource/image/Button1.png");

    button2.setPosX(100);
    button2.setPosY(200);
    button2.setHight(50);
    button2.setWidth(200);
    button2.setImages("Resource/image/Button2.png","Resource/image/Button2Se.png","Resource/image/Button2.png");
}
void Run(Engine*super){
    tlo.draw(super->getFrame());
    button1.onSelected(super->getFrame(),super->getEvent());

    if(button1.onClicked(super->getFrame(),super->getEvent())){
        super->setEnd(true);
        std::cout<<"Reload startet"<<std::endl;
        super->overrideSetUpFun(NULL);
        super->overrideRunFun(NULL);
        super->overrideSetUpFun(&DemoSetUp);
        super->overrideRunFun(&DemoRun);
        super->reload();
    }
    button2.onSelected(super->getFrame(),super->getEvent());
    if(button2.onClicked(super->getFrame(),super->getEvent())){
        super->setEnd(true);
        std::cout<<"Reload startet"<<std::endl;
        super->overrideSetUpFun(NULL);
        super->overrideRunFun(NULL);

        super->overrideRunFun(&runPrimitiveRender);
        super->reload();
    }
}

void clicked(sf::RenderWindow *parent,MouseListener *This){
    std::cout<<"click"<<std::endl;
}
void Relesed(sf::RenderWindow *parent,MouseListener *This){
    std::cout<<"relesed"<<std::endl;
}
bool save=false;
void keyBack(Engine *super){
    super->setEnd(true);
    std::cout<<"Reload startet"<<std::endl;
    super->overrideSetUpFun(NULL);
    super->overrideRunFun(NULL);
    super->overrideSetUpFun(&setUP);
    super->overrideRunFun(&Run);
    super->reload();
}




void BitmapTest(Engine* super){






}
int main() {
;
    Engine engine;
    //newBitmap.init();
    //KeyListener ks(sf::Keyboard::D,&BitmapTest);
    //ks.overrideRelesedFun(&keyRelesed);
  //  KeyListener end(sf::Keyboard::Escape,&ecapeEndDemo);
   // KeyListener back(sf::Keyboard::Space,&keyBack);
    //engine.addKeyListener(end);
    //engine.addKeyListener(back);

   //engine.overrideSetUpFun(&setUP);
    //engine.overrideRunFun(&Run);
     engine.overrideSetUpFun(&menuSetUp);
     engine.overrideRunFun(&menuRun);
   engine.overrideClearFun(&menuClear);
  // KeyListener ks(sf::Keyboard::A,&primityvRederfun);
   //ks.overrideRelesedFun(&keyRelesed);
    //engine.addKeyListener(ks);
    //MouseListener ml;
   // ml.overrideMousePressed(&clicked,LeftMouseButton);
    //ml.overrideMouseMove(&move);
    //ml.overrideMouseReleased(&Relesed,LeftMouseButton);
    //engine.listener=&ml;
    engine.init(800,600,WindowMode,false, true,false);


    //if(engine.KeyBaordList.empty())
      //  std::cout<<"wyczyszczona"<<std::endl;
    return 0;
}
