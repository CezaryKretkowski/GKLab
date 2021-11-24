//
// Created by cezar on 29.10.2021.
//
#include "Engine.h"

void Engine::toDo(){

    clear(menu.getBackGround());
}
void Engine::mainLoop() {
    while(frame->isOpen()&&(!end)){

        while (frame->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                frame->close();

        }
        clear(sf::Color::Black);


        if(MouseListenerON) {
            listener->mouseMove(this->frame,event);
            listener->mouseButtonPressed(this->frame,event);
            listener->mouseButtonReleased(this->frame,event);
            listener->mouseButtonLeft(this->frame,event);
            listener->mouseButtonEnter(this->frame,event);
        }
        if(KeyBoardON) {
            for (std::list<KeyListener>::iterator it = KeyBaordList.begin(); it != KeyBaordList.end(); ++it)
                (*it).onKeyPressedFun(this);
        }
        if(this->run!=NULL)
            this->run(this);


        frame->display();


    }
    //clear(this->img);
}
bool Engine::init(int wHeight,int wWidth,int mode,int frameRate,bool KeyBoardON,bool MouseListenerON) {
    bool check;
    this->KeyBoardON=KeyBoardON;
    this->MouseListenerON=MouseListenerON;
   // if(MouseListenerON){

     //   listener.setSuper(this);
    //}

    switch (mode) {
        case 1:this->frame = new sf::RenderWindow(sf::VideoMode(wHeight, wWidth), "SFML Window", sf::Style::Fullscreen);

            break;
        default:this->frame=new sf::RenderWindow(sf::VideoMode(wHeight, wWidth), "SFML Window");

            break;
    }
    if(frame)
        check=true;
    else
        check=false;

    if(frameRate!=0)
        frame->setFramerateLimit(frameRate);


    if(this->setUp!=NULL)
        setUp(this);
    mainLoop();
    if(this->setClear!=NULL)
        setClear(this);

    return check;
}

sf::RenderWindow* Engine::getFrame() {
    return this->frame;
}
void Engine::overrideRunFun(void (*run)(Engine *parent)){
    this->run=*run;
}
void Engine::overrideSetUpFun(void (*setUp)(Engine *)) {
    this->setUp=*setUp;
}
void Engine::overrideClearFun(void (*clear)(Engine *parent)){
    this->setClear=*clear;
}
void Engine::clear(sf::Color color) {
    this->frame->clear(color);
}
void Engine::clear(sf::Image img) {
    this->source.update(img);
    this->background.setTexture(source);
    this->frame->draw(background);
}
void Engine::setBitmap(std::string filName) {
    sf::Image img;
    std::string path="Resource/image/"+filName;
    //img.
    img.loadFromFile(path);
    this->img=img;
}

void Engine::setEnd(bool end) {
    end=end;
}

bool Engine::getEnd() {
    return end;
}
void Engine::reload(){
    setEnd(false);
    mainLoop();
}
sf::Texture* Engine::getSource() {
    return &source;
}
void Engine::addKeyListener(KeyListener ls) {
    this->KeyBaordList.push_front(ls);
}
sf::Event Engine::getEvent() {
    return this->event;
}
void Engine::clearKeys() {
    this->KeyBaordList.clear();
}
sf::Clock* Engine::getClock() {
    return &clock;
}
