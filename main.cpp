#include <iostream>
#include "board.h"

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

    createBoard(rows, columns);
    // TODO: llenar el tablero con fichas aleatorias (distribucion uniforme)


    int option = -1;

    do {
        showMenu();
        option = readInt("Escoge una opcion: ", 0, 6);

        switch (option) {

        case 1: {   // Eliminar una ficha
            int row = readInt("Fila de la ficha: ", 1, tableRows) - 1;
            int column = readInt("Columna de la ficha: ", 1, tableColumns) - 1;
            cout << "[pendiente] eliminar la ficha en (" << row << ", " << column << ")" << endl;
            // implementar logica de eliminar la ficha, detectar combinaciones, reorganizar y procesar cascadas
            removals= removals + 1;
            break;
        }

        case 2: {   // Agregar una fila
            int row = readInt("Antes de que fila se inserta: ", 1, tableRows + 1) - 1;
            cout << "[pendiente] agregar fila en la posicion " << row << endl;
            // implementar logica
            break;
        }

        case 3: {   // Eliminar una fila
            int row = readInt("Que fila se elimina: ", 1, tableRows) - 1;
            cout << "[pendiente] eliminar la fila " << row << endl;
            // implementar logica
            break;
        }

        case 4: {   // Agregar una columna
            int column = readInt("Antes de que columna se inserta: ", 1, tableColumns + 1) - 1;
            cout << "[pendiente] agregar columna en la posicion " << column << endl;
            // implementar logica
            break;
        }

        case 5: {   // Eliminar una columna
            int column = readInt("Que columna se elimina: ", 1, tableColumns) - 1;
            cout << "[pendiente] eliminar la columna " << column << endl;
            // implementar logica
            break;
        }

        case 6: {   // Mostrar el tablero
            cout << "[pendiente] mostrar el tablero en formato fichas y en formato binario" << endl;
            // implementar logica
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
