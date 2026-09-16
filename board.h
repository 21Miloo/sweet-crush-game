#ifndef BOARD_H
#define BOARD_H

const short int TamanoFicha = 3;

extern unsigned char* table;
extern int tableRows;
extern int tableColumns;
extern int tableBytes;

void createBoard(int rows, int columns);

void freeBoard();

int locateInitialBitPiece(int row,int column);

int getPiece(int row, int column);

void setPiece(int row, int column, int value);

void fillRandom();

void removePiece(int row, int column);


#endif // BOARD_H
