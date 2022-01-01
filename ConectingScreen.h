//
// Created by cezar on 01.01.2022.
//

#ifndef GKLAB_CONECTINGSCREEN_H
#define GKLAB_CONECTINGSCREEN_H
class ConectingScreen{
private:
    Label title;
    Button CreteGame;
    Button JoinGame;
public:
    Label* getTitle(){return &title;}
    Button* GetCreteGame(){return &CreteGame;}
    Button* GetJoinGame(){return &JoinGame;}

};
#endif //GKLAB_CONECTINGSCREEN_H
