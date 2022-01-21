//
// Created by cezary on 11.10.2021.
//

#ifndef GK_LAB_KEYLISTENER_H
#define GK_LAB_KEYLISTENER_H
#include <SFML/Graphics.hpp>
class Engine;

class KeyListener {
private:
    sf::Keyboard::Key key;
    void (*onKeyPressed)(Engine *parent);
    void (*onReleased)(Engine *parent)=NULL;
public:
    KeyListener(sf::Keyboard::Key key,void (*onKeyPressed)(Engine *parent));
    void onKeyPressedFun(Engine* parent);
    void overrideRelesedFun(void (*onReleasedPressed)(Engine *parent));
    void setKey(sf::Keyboard::Key key);
    void setOnKeyPressedFun(void (*onKeyPressed)(Engine *parent));

};
#endif //GK_LAB_KEYLISTENER_H
