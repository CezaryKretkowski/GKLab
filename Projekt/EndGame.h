//
// Created by cezar on 26.12.2021.
//

#ifndef GKLAB_ENDGAME_H
#define GKLAB_ENDGAME_H
#include "Button.h"
#include "Label.h"
class EndGame{
private:
    Label title;
    Button exit;
public:
    Label* getTitle(){return &title;}
    Button* GetExit(){return &exit;}

};
#endif //GKLAB_ENDGAME_H
