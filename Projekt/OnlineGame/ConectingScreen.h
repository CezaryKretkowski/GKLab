//
// Created by cezar on 01.01.2022.
//

#ifndef GKLAB_CONECTINGSCREEN_H
#define GKLAB_CONECTINGSCREEN_H
/**@class ConectingScreen Klasa zawierająca widok służacy do ustalenia połazzenia **/
class ConectingScreen{
private:
    ///Obiekt zwaierający nagłówek
    Label title;
    ///Button odpowiedzialny za tworzenie serwera
    Button CreteGame;
    ///Button odpowiedszialny za dołączenie do rozgrywki
    Button JoinGame;
public:
    /**Metoda zwracająca
     *
     * @return wskażnik na nagłówek
     */
    Label* getTitle(){return &title;}
    /**Metoda zwracająca
     *
     * @return wskażnik na przycik utwórz nową grę
     */
    Button* GetCreteGame(){return &CreteGame;}
    /**Metoda zwracająca
     *
     * @return wskażnik na przycik utwórz nową grę
     */
    Button* GetJoinGame(){return &JoinGame;}

};
#endif //GKLAB_CONECTINGSCREEN_H
