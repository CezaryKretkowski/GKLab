//
// Created by cezar on 11.11.2021.
//

#ifndef GKLAB_GAMEFUN_H
#define GKLAB_GAMEFUN_H
#include "Engine.h"
/**Metoda odpowiedzialna z główną logike trybu gry. W tej metodzie realizowny jest ruch graczy po planszy ,detekcja kolizji oraza trafień.
 * W tej pętli realizowne jest wyświetlanie wszystki obiektów na planszy .
 *
 * @param super wksażnik na głowne okno gry
 */
void GameRun(Engine *super);
/**Metoda odpowiedzialna za przygotawaniew głównego widoku gry.
 * w tej metodzie wczytywane są wszystkie grafik oraz incjolizowane są wszytkie niezmienne stałe
 * @param super wksażnik na głowne okno gry
 */
void GameSetUp(Engine *super);
/**Metoda służaca do sprzątania pamięci po zakończeniu tego trybu rozgrywki
 *
 * @param super  wksażnik na głowne okno gry
 */
void GameClear(Engine *super);
#endif //GKLAB_GAMEFUN_H
