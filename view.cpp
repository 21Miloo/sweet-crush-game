#include <iostream>
#include "view.h"
#include "board.h"

using namespace std;
// El tablero guarda un chorro de bits (unsigned char* table, 3 bits por ficha)

const char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F', '.', '?'};


// Funcion provisional para probar pintado del tablero
int getPiece(int row, int col){
    return (row + col) % 6;
}

// Imprime un numero ocupando siempre 'width' caracteres, alineado a la derecha.
// Sirve para que las columnas queden cuadradas aunque los numeros tengan 1 o 2 cifras.
void printPadded(int value, int width){
    int digits = 1;
    int n = value;
    while (n >= 10) { n /= 10; digits++; }

    for (int i = digits; i < width; i++) {
        cout << ' ';
    }
    cout << value;
}


// El tablero en formato fichas. Las filas y columnas se numeran desde 1,
// que es como las pide el menu; la conversion a indice (restar 1) la hace main.
void showBoard(){

    // Encabezado con el numero de cada columna
    cout << "   ";
    for (int j = 0; j < tableColumns; j++) {
        cout << ' ';
        printPadded(j + 1, 2);
    }
    cout << endl;

    for (int i = 0; i < tableRows; i++) {

        printPadded(i + 1, 3);          // numero de la fila, al margen izquierdo

        for (int j = 0; j < tableColumns; j++) {
            int piece = getPiece(i, j);
            cout << "  " << symbols[piece];
        }

        cout << endl;
    }
}


// El mismo tablero, pero mostrando los 3 bits de cada ficha.
void showBoardBinary(){

    cout << "   ";
    for (int j = 0; j < tableColumns; j++) {
        cout << ' ';
        printPadded(j + 1, 3);
    }
    cout << endl;

    for (int i = 0; i < tableRows; i++) {

        printPadded(i + 1, 3);

        for (int j = 0; j < tableColumns; j++) {
            int piece = getPiece(i, j);

            int bit0 = (piece >> 0) & 1; // -> Bit menos significativo
            int bit1 = (piece >> 1) & 1;
            int bit2 = (piece >> 2) & 1; // -> Bit mas significativo

            cout << ' ' << bit2 << bit1 << bit0;   // se imprime de izquierda a derecha
        }

        cout << endl;
    }
}
