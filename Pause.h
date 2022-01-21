//
// Created by cezar on 04.12.2021.
//

#ifndef GKLAB_PAUSE_H
#define GKLAB_PAUSE_H
#include "Button.h"
#include "Label.h"
/**@class Klasa pouse kalsa mająca na cele obsługę pauzy
 *
 */
class Pause{
private:
    ///Obiekt służący do wyświetlania nagłówka
    Label title;
    ///Button odpowiedzialny za wyjście z rozgrywki
    Button exit;
    ///Button odpowiedzialny za wyjście i zapis gry
    Button saveAndExit;
public:
    /**Metoda zwracjąca
     *
     * @return Wskażnik na pole nagłówka
     */
    Label* getTitle(){return &title;}
    /**Metoda Zwracjąca
     *
     * @return Wskażnik na przycisk exit
     */
    Button* GetExit(){return &exit;}
    /**
     *
     * @return Wskażnik na przycik saveAndExit
     */
    Button* GetSaveAndExit(){return &saveAndExit;}

};
#endif //GKLAB_PAUSE_H
