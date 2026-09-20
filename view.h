#ifndef VIEW_H
#define VIEW_H

void showBoard();        // el tablero en formato fichas
void showBoardBinary();  // el mismo tablero en formato binario
void showMenu();         // las opciones de la partida
void showState(int removals, int piecesRemoved, int matches, int cascades, int score);

#endif // VIEW_H
