//
// Created by cezar on 01.01.2022.
//

#ifndef GKLAB_ONLINEGAMEVIEWFUN_H
#define GKLAB_ONLINEGAMEVIEWFUN_H
#include "../../Silnik/Engine.h"
/**Metoda odpowiedzialna za przygotawaniew głównego widoku gry.
 * w tej metodzie wczytywane są wszystkie grafik oraz incjolizowane są wszytkie niezmienne stałe
 * @param super wksażnik na głowne okno gry
 */
void onlineGameSetUP(Engine* super);
/**Metoda odpowiedzialna z główną logike trybu gry. W tej metodzie realizowny jest ruch graczy po planszy ,detekcja kolizji oraza trafień.
 * W tej pętli realizowne jest wyświetlanie wszystki obiektów na planszy , W tym trybie ustawiamy rówanież połączynie oraz realizujemy
 * nizbędną wymianę danych przez sieć .
 *
 * @param super wksażnik na głowne okno gry
 */
void onlineGameRun(Engine* super);
/**Metoda służaca do sprzątania pamięci po zakończeniu tego trybu rozgrywki
 *
 * @param super  wksażnik na głowne okno gry
 */
void onlineGameClear(Engine* super);
#endif //GKLAB_ONLINEGAMEVIEWFUN_H
