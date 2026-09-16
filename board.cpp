#include "board.h"
#include <cstdlib>   // rand
#include <bitset>
// borrar
#include <iostream>
using namespace std;


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

int locateInitialBitPiece(int row,int column)
{
    int pieceIndex = row*tableColumns + column;
    int initialBit=pieceIndex*TamanoFicha;
    return initialBit;
}

int getPiece(int row, int column)
{
    int initialBit = locateInitialBitPiece(row, column);
    int associatedByte = initialBit / 8;
    int bitInBytePosition = initialBit % 8;

    int piece = (table[associatedByte] >> bitInBytePosition) & 0b111;

    if (bitInBytePosition > 5)
    {
        int bitsQueCupieron = 8 - bitInBytePosition;   // 2 si off=6, 1 si off=7

        int resto = (table[associatedByte + 1] << bitsQueCupieron) & 0b111;

        piece = piece | resto;   // se juntan sin borrarse
    }

    return piece;
}


void setPiece(int row, int column, int value){
    int initialBit = locateInitialBitPiece(row, column);
    int associatedByte = initialBit / 8;
    int bitInBytePosition = initialBit % 8;

    value = value & 0b111;

    int mascara = 0b111 << bitInBytePosition;

    table[associatedByte] = (table[associatedByte] & ~mascara) | (value << bitInBytePosition);

    if (bitInBytePosition > 5)
    {
        int bitsQueCupieron = 8 - bitInBytePosition;

        int mascara2 = 0b111 >> bitsQueCupieron;

        table[associatedByte + 1] = (table[associatedByte + 1] & ~mascara2) | (value >> bitsQueCupieron);
    }
}


void fillRandom(){
    for(int row = 0 ; row < tableRows ; row++ ){
        for(int column = 0 ; column< tableColumns ; column++){
            setPiece(row,column,(rand()%6));
        }
    }
}

void removePiece(int row, int column){
    setPiece(row,column,6);
}


