#include "board.h"

unsigned char* table = nullptr;
int tableRows = 0;
int tableColumns = 0;
int tableBytes = 0;

void createBoard(int rows, int columns)
{
    tableRows = rows;
    tableColumns = columns;

    int bits = TamanoFicha*rows*columns;
    tableBytes = (bits % 8 == 0) ? bits / 8 : bits / 8 + 1;

    table = new unsigned char[tableBytes]();
}

void freeBoard()
{
    delete[] table;
    table = nullptr;
    tableRows = 0;
    tableColumns = 0;
    tableBytes = 0;
}

int locatePiece(int row,int column)
{
    int pieceIndex = row*tableColumns + column;
    int initialBit=pieceIndex*TamanoFicha;
    return initialBit;
}

