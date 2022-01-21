//
// Created by cezar on 26.11.2021.
//

#ifndef GKLAB_DEMOVIEW_H
#define GKLAB_DEMOVIEW_H
#include "PlayerObject.h"
class DemoView{
private:
    PlayerObject p1;
public:
    PlayerObject* getP1(){return &p1;}
};
#endif //GKLAB_DEMOVIEW_H
