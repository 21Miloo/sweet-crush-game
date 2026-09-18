#include "board.h"
#include <cstdlib>
#include <iostream>

using namespace std;


unsigned char* table = nullptr;
int tableRows = 0;
int tableColumns = 0;
int tableBytes = 0;
int tableCapacity = 0;
void createBoard(int rows, int columns)
{
    tableRows = rows;
    tableColumns = columns;

    tableBytes = neededbytes(tableRows,tableColumns);

    table = new unsigned char[tableBytes]();
    tableCapacity = tableBytes;
}

void freeBoard()
{
    delete[] table;
    table = nullptr;
    tableRows = 0;
    tableColumns = 0;
    tableBytes = 0;
    tableCapacity = 0;
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


int neededbytes(int rows, int columns){
    int bits = TamanoFicha*rows*columns;
    int bytes = (bits % 8 == 0) ? bits / 8 : bits / 8 + 1;
    return bytes;
}

void resizeMemory(int rows, int columns)
{
    int bytesNeeded = neededbytes(rows, columns);

    bool mustReallocate = (bytesNeeded > tableCapacity) || (bytesNeeded * 100 < tableCapacity * 65);

    if (mustReallocate)
    {
        unsigned char* newTable = new unsigned char[bytesNeeded]();

        int bytesToCopy = (bytesNeeded < tableCapacity) ? bytesNeeded : tableCapacity;

        for (int i = 0; i < bytesToCopy; i++)
        {
            newTable[i] = table[i];
        }

        delete[] table;
        table = newTable;
        tableCapacity = bytesNeeded;
    }

    tableRows = rows;
    tableColumns = columns;
    tableBytes = bytesNeeded;
}

void applyGravity()
{
    for (int column = 0; column < tableColumns; column++)
    {
        for (int row = tableRows - 1; row >= 0; row--)
        {
            if (getPiece(row, column) != 6) continue;

            int rowWithPiece = row - 1;
            while (rowWithPiece >= 0 && getPiece(rowWithPiece, column) == 6){
                rowWithPiece--;
            }

            if (rowWithPiece >= 0){
                setPiece(row, column, getPiece(rowWithPiece, column));
                setPiece(rowWithPiece, column, 6);
            }
            else{
                setPiece(row, column, rand() % 6);
            }
        }
    }
}
