//
// Created by cezar on 04.12.2021.
//

#ifndef GKLAB_PAUSE_H
#define GKLAB_PAUSE_H
#include "Button.h"
#include "Label.h"
class Pause{
private:
    Label title;
    Button exit;
    Button saveAndExit;
public:
    Label* getTitle(){return &title;}
    Button* GetExit(){return &exit;}
    Button* GetSaveAndExit(){return &saveAndExit;}

};
#endif //GKLAB_PAUSE_H
