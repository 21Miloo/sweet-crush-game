#include <iostream>
#include "view.h"
#include "board.h"

using namespace std;
// El tablero guarda un chorro de bits (unsigned char* table, 3 bits por ficha)

const char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F', '.', '?'};


// ===== TEMPORAL: borrar cuando se mergee el board.cpp de Camilo =====
// Tablero de mentira para poder ver la vista sin depender de board.
int getPiece(int row, int col){
    return (row + col) % 6;
}
// ====================================================================


// Imprime un numero ocupando siempre 'width' caracteres, alineado a la derecha.
// Sirve para que las columnas queden cuadradas aunque los numeros tengan 1 o 2 cifras.

//Funcion para alinear el tablero -------------------------------------------------------------------
void printPadded(int value, int width){
    int digits = 1;
    int n = value;
    while (n >= 10) { n /= 10; digits++; }

    for (int i = digits; i < width; i++) {
        cout << ' ';
    }
    cout << value;
}

// -----------------------------------------------------------------------------------------------------


// El tablero en formato fichas. Las filas y columnas se numeran desde 1,
// que es como las pide el menu; la conversion a indice (restar 1) la hace main.
void showBoard(){

    // Encabezado con el numero de cada columna
    cout << "   "; // Imprimimos 3 espacios para dejar libre la esquina superior izquierda.

    for (int j = 0; j < tableColumns; j++) {
        cout << ' ';
        printPadded(j + 1, 2); // Imprime 1 espacio + el numero  (j+1) ajustado a 2 caracteres de ancho
    }
    cout << endl;

    for (int i = 0; i < tableRows; i++) {

        printPadded(i + 1, 3); // por cada fila imprime  primero (i+1) con ancho 3 en el margen izquierdo

        for (int j = 0; j < tableColumns; j++) {
            int piece = getPiece(i, j); // pedimos la pieza con getPiece() y usamos ese valos como indice dentro del arreglo symbols
            cout << "  " << symbols[piece];
        }

        cout << endl; // salto de linea al terminar la fila
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


// Imprime las opciones disponibles durante la partida.
void showMenu(){
    cout << endl;
    cout << "------------ MENU ------------" << endl;
    cout << " 1. Eliminar una ficha"        << endl;
    cout << " 2. Agregar una fila"          << endl;
    cout << " 3. Eliminar una fila"         << endl;
    cout << " 4. Agregar una columna"       << endl;
    cout << " 5. Eliminar una columna"      << endl;
    cout << " 6. Mostrar el tablero"        << endl;
    cout << " 0. Salir"                     << endl;
    cout << "------------------------------" << endl;
}


// Estado del juego que el enunciado exige mostrar luego de cada jugada.
void showState(int removals, int piecesRemoved, int matches, int cascades, int score){
    cout << endl;
    cout << "Dimensiones del tablero   : " << tableRows << " x " << tableColumns << endl;
    cout << "Eliminaciones del usuario : " << removals << endl;
    cout << "Fichas eliminadas en total: " << piecesRemoved << endl;
    cout << "Combinaciones detectadas  : " << matches << endl;
    cout << "Cascadas de esta jugada   : " << cascades << endl;
    cout << "Puntuacion                : " << score << endl;
}





