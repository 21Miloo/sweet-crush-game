#include <iostream>
#include "board.h"
#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include "view.h"
#include "game.h"
using namespace std;


int readInt(const char* prompt, int min, int max){

    int num = 0;
    bool valid = false;

    do {
        cout << prompt;
        cin >> num;

        if (cin.fail() || cin.peek() != '\n') {
            if (cin.eof()) {
                cout << endl << "Entrada terminada." << endl;
                return min;
            }
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Valor invalido. ";
        }
        else if (num < min || num > max) {
            cout << "Debe estar entre " << min << " y " << max << ". ";
        }
        else {
            valid = true;
        }

    } while (!valid);

    return num;
}

int main()
{
    const int maxDimension = 50;

    int removals = 0;
    int piecesRemoved = 0;
    int matches = 0;
    int cascades = 0;
    int score = 0;

    cout << "===== SWEET CRUSH =====" << endl << endl;

    int rows = readInt("Ingresa el numero de filas: ", 1, maxDimension);
    int columns = readInt("Ingresa el numero de columnas: ", 1, maxDimension);

    srand(time(0));
    createBoard(rows, columns);
    fillRandom();

    int option = -1;

    do {
        showMenu();
        option = readInt("Escoge una opcion: ", 0, 6);
        cout << endl;

        switch (option) {

        case 1: {
            int row = readInt("Fila de la ficha: ", 1, tableRows) - 1;
            int column = readInt("Columna de la ficha: ", 1, tableColumns) - 1;

            removePiece(row, column);
            applyGravity();
            cascades = processCascades(piecesRemoved, matches, score);
            showBoard();
            cout << endl;
            // showBoardBinary();

            removals= removals + 1;
            break;
        }

        case 2: {
            int row = readInt("Antes de que fila se inserta: ", 1, tableRows + 1) - 1;
            addRow(row);
            cascades = processCascades(piecesRemoved, matches, score);
            showBoard();
            cout << endl;
            // showBoardBinary();
            break;
        }

        case 3: {
            int row = readInt("Que fila se elimina: ", 1, tableRows) - 1;
            removeRow(row);
            cascades = processCascades(piecesRemoved, matches, score);
            showBoard();
            cout << endl;
            // showBoardBinary();
            break;
        }

        case 4: {
            int column = readInt("Antes de que columna se inserta: ", 1, tableColumns + 1) - 1;    
            addColumn(column);
            cascades = processCascades(piecesRemoved, matches, score);
            showBoard();
            cout << endl;
            // showBoardBinary();
            break;
        }

        case 5: {
            int column = readInt("Que columna se elimina: ", 1, tableColumns) - 1;
            removeColumn(column);
            cascades = processCascades(piecesRemoved, matches, score);
            showBoard();
            cout << endl;
            // showBoardBinary();
            break;
        }

        case 6: {
            showBoard();
            cout << endl;
            showBoardBinary();
            break;
        }

        case 0: {
            cout << endl << "Gracias por jugar a Sweet Crush." << endl;
            break;
        }

        }

        // Luego de cada jugada (no al salir) se muestra el estado del juego.
        if (option != 0) {
            showState(removals, piecesRemoved, matches, cascades, score);
        }

    } while (option != 0);

    freeBoard();
    freeMarks();
    return 0;
}
