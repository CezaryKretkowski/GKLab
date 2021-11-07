//
// Created by cezar on 15.10.2021.
//

#ifndef GK_LAB_MOUSELISTENER_H
#define GK_LAB_MOUSELISTENER_H
#include <SFML/Graphics.hpp>
#define LeftMouseButton 1000
#define RightMouseButton 1001
#define MidleMouseButton 1002

class MouseListener{
private:
    int x;
    int y;

    sf::RenderWindow *super;
    void (*onMouseButtonLeftPressed)(sf::RenderWindow *parent,MouseListener *This )=NULL;
    void (*onMouseButtonRightPressed)(sf::RenderWindow *parent,MouseListener *This )=NULL;
    void (*onMouseButtonScrollPressed)(sf::RenderWindow *parent,MouseListener *This )=NULL;
    void (*onMouseButtonLeftReleased)(sf::RenderWindow *parent,MouseListener *This )=NULL;
    void (*onMouseButtonRightReleased)(sf::RenderWindow *parent,MouseListener *This )=NULL;
    void (*onMouseButtonScrollReleased)(sf::RenderWindow *parent,MouseListener *This )=NULL;
    void (*onMouseMove)(sf::RenderWindow *parent,MouseListener *This )=NULL;
    void (*onMouseEnter)(sf::RenderWindow *parent,MouseListener *This )=NULL;
    void (*onMouseLeft)(sf::RenderWindow *parent,MouseListener *This )=NULL;
public:

    void mouseMove(sf::RenderWindow *parent,sf::Event event);
    void mouseButtonPressed(sf::RenderWindow *parent,sf::Event event);
    void mouseButtonReleased(sf::RenderWindow *parent,sf::Event event);
    void mouseButtonEnter(sf::RenderWindow *parent,sf::Event event);
    void mouseButtonLeft(sf::RenderWindow *parent,sf::Event event);
    void overrideMouseMove(void (*onMouseMove)(sf::RenderWindow *parent,MouseListener *This ));
    void overrideMousePressed(void (*onMousePressed)(sf::RenderWindow *parent,MouseListener *This ),int button);
    void overrideMouseReleased(void (*onMouseRelessed)(sf::RenderWindow *parent,MouseListener *This ),int button);
    void overrideMouseEnter(void (*onMouseEnter)(sf::RenderWindow *parent,MouseListener *This ));
    void overrideMouseLeft(void (*onMouseLeft)(sf::RenderWindow *parent,MouseListener *This ));
    int getX();
    int getY();


};
#endif //GK_LAB_MOUSELISTENER_H
