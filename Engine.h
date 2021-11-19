//
// Created by cezar on 29.10.2021.
//

#ifndef GKLAB_ENGINE_H
#define GKLAB_ENGINE_H
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "GameView.h"
#include "KeyListener.h"
#include "MouseListener.h"
#include <list>
//#define Path
#define  FullScreenMode 1
#define  WindowMode 0
#define  NoLimits 0

class Engine{
private:
    sf::RenderWindow*  frame;//=NULL;
    int windowHeight;
    int windowWidth;
    sf::Clock clock;
    sf::Event event;
    sf::Texture source;
    sf::Sprite background;
    sf::Image img;
    bool end=false;
    bool KeyBoardON=false;
    bool MouseListenerON=false;
public:
    std::list<KeyListener> KeyBaordList;
    void (*run)(Engine *parent)=NULL;
    void (*setUp)(Engine *parent)=NULL;
    void (*setEventUp)(Engine *parent)=NULL;
    void (*setClear)(Engine *parent)=NULL;

public:
    bool init(int wHeight=800,int wWidth=600,int mode=0,int frameRate=0,bool KeyBoardON=false,bool MouseListenerON=false);
    sf::RenderWindow* getFrame();
    void overrideRunFun(void (*run)(Engine *parent)=NULL);
    void overrideSetUpFun(void (*setUp)(Engine *parent)=NULL);
    void overrideClearFun(void (*setClear)(Engine *parent)=NULL);
    void clear(sf::Color color=sf::Color::White);
    void clear(sf::Image img);
    void mainLoop();
    sf::Event getEvent();
    void setBitmap(std::string path);
    void addKeyListener(KeyListener ls);
    void toDo();
    void setEnd(bool end);
    bool getEnd();
    sf::Clock* getClock();
    void reload();
    sf::Texture* getSource();
    void getImg();
    MouseListener*listener;
    void clearKeys();

    MainMenu menu;
    GameView game;
};
#endif //GKLAB_ENGINE_H
