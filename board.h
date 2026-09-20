#ifndef BOARD_H
#define BOARD_H

const short int TamanoFicha = 3;

extern unsigned char* table;
extern int tableRows;
extern int tableColumns;
extern int tableBytes;
extern int tableCapacity;

void createBoard(int rows, int columns);

void freeBoard();

int locateInitialBitPiece(int row,int column);

int getPiece(int row, int column);

void setPiece(int row, int column, int value);

void fillRandom();

void removePiece(int row, int column);

int neededbytes(int rows, int columns);

void resizeMemory(int rows, int columns);

void applyGravity();

void addRow(int pos);

void addColumn(int pos);

void removeRow(int pos);

void removeColumn(int pos);

#endif // BOARD_H
