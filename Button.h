//
// Created by cezar on 29.10.2021.
//

#ifndef GKLAB_BUTTON_H
#define GKLAB_BUTTON_H

#include <SFML/Graphics.hpp>

/**
 * classa implemętująca przycisk
 */
class Button {
private:
    /**Obiekty image przechowujące odopowiednie grafiki odpowiedzialne z 3 stany przycisku
     */
    sf::Image s1, s2, s3;
    ///Obiekt Tekstury służacy do wywietlania odpowiedniego stanu przycisku
    sf::Texture source;

    ///Pozycja x przycisku
    float posX;
    ///Pozycja y przycisku
    float posY;
    ///Szerekość przyciksu
    int width;
    ///Wysokość przycisku
    int hight;
    int x;
    int y;

public:
    ///Kostruktur klasy button
    Button();

    /**Metoda ustawiająca
     *
     * @param p1 ścieżka do obrazu reprezętująca bazową grafikę przycisku
     * @param p2 ścieżka do obrazu reprezętująca grafikę przycisku w momencie najachnia na niego myszą
     * @param p3 ścieżka do obrazu reprezętująca grafikę przycisku w momencie kliknięcia
     */
    void setImages(std::string p1, std::string p2, std::string p3);

    /**Metoda wywoływana w momencie zaznaczenia przycisku
     *
     * @param parent Wskażnik na główne okno gry
     * @param event Obiekt służący do osługi zdażenia
     */
    void onSelected(sf::RenderWindow *parent, sf::Event event);

    /**Metoda wywływana w momencie cliknięc
     *
     * @param parent Wskażnik na główne okno gry
     * @param event Obiekt służący do osługi zdażenia
     * @return zwraca prawdę jeśli zostanie wykryte nciśnięcie na przycisk w przeciwnym przypadku zwraca fałsz
     */
    bool onClicked(sf::RenderWindow *parent, sf::Event event);

    /**Metoda ustawiająca
     *
     * @param w nowa wartość szerokości przycisku
     */
    void setWidth(int w) { this->width = w; }

    /**Metoda ustawiająca
     *
     * @param h nowa wartość wysokości przycisku
     */
    void setHight(int h) { this->hight = h; }

    /**Metoda Zwracająca
     *
     * @return zwraca szerokości przycisku
     */
    int getWidth() { return width; }

    /**Metoda Zwracająca
    *
    * @return zwraca wysokość przycisku
    */
    int getHight() { return hight; }

    /**Metoda ustawiająca
    *
    * @param x Pozycje przycisku przycisku
    */
    void setPosX(float x) { posX = x; }
    /**Metoda ustawiająca
    *
    * @param y pozycje przycisku
    */
    void setPosY(float y) { posY = y; }
    /**Metoda Zwracająca
    *
    * @return zwraca pozycje X
    */
    float getPosX() { return posX; }
    /**Metoda Zwracająca
    *
    * @return zwraca pozycje Y
    */
    float getPosY() { return posY; }

    bool (*toDo)(sf::RenderWindow *parent) = NULL;

    void overrideMouseMove(bool (*onToDo)(sf::RenderWindow *parent));

    sf::Sprite painer;
};

#endif //GKLAB_BUTTON_H
