//
// Created by cezar on 12.11.2021.
//

#ifndef GKLAB_MISSILE_H
#define GKLAB_MISSILE_H
#include <SFML/Graphics.hpp>
/**@class Klasa Reprezuntująca pocisk
 *
 */
class Missile{

private:
    ///Pozycja x pocisku
    float posX;
    ///Pozycja y pocisku
    float posY;
    ///Pozycja kąt pocisku
    float rot;
    ///Sprite służacy do wyświetlania pocisku
    sf::Sprite painter;
    ///Obiekt zawierjący obraz pocisku
    sf::Image img;
    ///Obiekt zawierjący tekosturę pociku
    sf::Texture tx;
    ///Licznik służacy do wyświetlania pociku
    int count;
public:
    /**Konstruktor klasy
     * @param WspX wpółżedna x
     * @param WspY wpółżedna Y
     * @param count wartość licznika.
     */
    Missile(float =0.0,float =0.0,int =0);
    /**Metoda ustaiwająca
     *
     * @param path ścioeżkę do pliku z obrazem pociksu
     */
    void setImg(std::string path);
    /**Metoda Uswtiająca
     *
     * @param x pozycje x Pociksu
     */
    void setPosX(float x){posX=x;};
    /**Metoda Uswtiająca
    *
    * @param y pozycje x Pociksu
    */
    void setPosY(float y){posY=y;};
    /**MEtoda ustwiająca licznik
     *
     * @param i  nowa wrtość licznika
     */
    void setCount(int i){count=i;};
    /**Metoda zwracjąca
     *
     * @return pozycję x pociksu
     */
    float getX(){return posX;}
    /**Metoda zwracjąca
    *
    * @return pozycję y pociksu
    */
    float getY(){return posY;}
    /**Metoda zwracjąca
    *
    * @return pkąt pod jakim jest obrócony pociks
    */
    float getRot(){return rot;}
    /**Metoda zwracjąca
    *
    * @return wartość licznika
    */
    float getCount(){return count;}
    /**Mtoda służaca do narysowania pocisku
     *
     * @param parent Wskażnik na główne okno gry
     */
    void draw(sf::RenderWindow *parent);
    /**Metoda ustwiająca
     *
     * @param rot Metoda ustwiająca kąt obrócenia pociksu
     */
    void setRot(float rot){this->rot=rot;}
};
#endif //GKLAB_MISSILE_H
