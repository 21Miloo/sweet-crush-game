#include <iostream>
#include "board.h"
#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include "view.h"

using namespace std;


// Lee un entero por consola y no devuelve hasta que sea valido.
// Valido = es un entero, no sobra nada detras, y esta entre min y max (ambos incluidos).
// El prompt es un const char* (puntero al literal)
int readInt(const char* prompt, int min, int max){

    int num = 0;
    bool valid = false;

    do {
        cout << prompt;
        cin >> num;

        if (cin.fail() || cin.peek() != '\n') {
            // cin.fail() -> metodo que nos dice si no se pudo validar un entero en la entrada. (el metodo retorna boolean FALSE si la entrada no es un entero)
            // cin.peek() -> mira el siguiente caracter sin sacarlo del buffer;
            //               si no es el salto de linea, sobraba algo detras y lo limpia
            if (cin.eof()) {
                // La entrada se cerro (Ctrl+Z, o un archivo redirigido que se acabo).
                // Sin este corte el bucle se repetiria para siempre.
                cout << endl << "Entrada terminada." << endl;
                return min;
            }
            cin.clear();              // quita el estado de error del cin
            cin.ignore(1000, '\n');   // descarta la basura que quedo en el buffer
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

    // Contadores del estado de la partida
    int removals = 0;       // eliminaciones pedidas por el usuario
    int piecesRemoved = 0;  // fichas eliminadas en total
    int matches = 0;        // combinaciones detectadas
    int cascades = 0;       // cascadas de la jugada actual
    int score = 0;          // puntuacion

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

        case 1: {   // Eliminar una ficha
            int row = readInt("Fila de la ficha: ", 1, tableRows) - 1; // Le restamos 1 por la correspondencia en el indice de un arreglo (Yo -> 1  C++ -> 0 / Yo -> 2, C++ -> 1)
            int column = readInt("Columna de la ficha: ", 1, tableColumns) - 1;

            // implementar logica de eliminar la ficha, detectar combinaciones, reorganizar y procesar cascadas
            removePiece(row, column);
            applyGravity();

            showBoard(); // Muestra tablero normal
            cout << endl;
            showBoardBinary(); // Muestra tablero en Binario

            removals= removals + 1;
            break;
        }

        case 2: {   // Agregar una fila
            int row = readInt("Antes de que fila se inserta: ", 1, tableRows + 1) - 1;
            // implementar logica
            addRow(row);
            showBoard(); // Muestra tablero normal
            cout << endl;
            showBoardBinary(); // Muestra tablero en Binario
            break;
        }

        case 3: {   // Eliminar una fila
            int row = readInt("Que fila se elimina: ", 1, tableRows) - 1;
            // implementar logica
            removeRow(row);
            showBoard(); // Muestra tablero normal
            cout << endl;
            showBoardBinary(); // Muestra tablero en Binario
            break;
        }

        case 4: {   // Agregar una columna
            int column = readInt("Antes de que columna se inserta: ", 1, tableColumns + 1) - 1;
            cout << "[pendiente] agregar columna en la posicion " << column << endl;
            // implementar logica
            addColumn(column);
            showBoard(); // Muestra tablero normal
            cout << endl;
            showBoardBinary(); // Muestra tablero en Binario
            break;
        }

        case 5: {   // Eliminar una columna
            int column = readInt("Que columna se elimina: ", 1, tableColumns) - 1;
            // implementar logica
            removeColumn(column);
            showBoard(); // Muestra tablero normal
            cout << endl;
            showBoardBinary(); // Muestra tablero en Binario
            break;
        }

        case 6: {   // Mostrar el tablero
            showBoard(); // Muestra tablero normal
            cout << endl;
            showBoardBinary(); // Muestra tablero en Binario
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

    return 0;
}
