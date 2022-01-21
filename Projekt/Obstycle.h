//
// Created by cezar on 19.11.2021.
//

#ifndef GKLAB_OBSTYCLE_H
#define GKLAB_OBSTYCLE_H
#include "../Silnik/DrawableObject.h"
#include <iostream>
/**@class
 * Klasa Reprezętująca przeszkody która dziedziczy bo klasie DrawableObject
 */
class Obstycle :public DrawableObject
{
public:
    /**Przysłonięta metoda draw której celem jest wyrysowanie przeszkody
     *
     * @param super wskażnik na główne okno gry
     */
  virtual void draw(sf::RenderWindow *super) override{
      painter.setPosition(posX,posY);
      painter.setTexture(ts);
      super->draw(this->painter);

  }
  /**Przysłonięcie destruktora **/
  ~Obstycle();
  /**Metoda zwracjąca
   *
   * @return zwaca obraz przszkody
   */
  sf::Image getImage();

};
#endif //GKLAB_OBSTYCLE_H
