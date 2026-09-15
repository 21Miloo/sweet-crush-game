#include <iostream>
#include <string>
#include "board.h"

using namespace std;


// Lee un entero por consola y no devuelve hasta que sea valido.
// Valido = es un entero, no sobra nada detras, y esta entre min y max (ambos incluidos).
int readInt(const string& prompt, int min, int max){

    int num = 0;
    bool valid = false;

    do {
        cout << prompt;
        cin >> num;

        if (cin.fail() || cin.peek() != '\n') {
            // cin.fail() -> metodo que nos dice si no se pudo validar un entero en la entrada. (el metodo retorna boolean FALSE si la entrada no es un entero)
            // cin.peek() -> mira el siguiente carácter del buffer sin sacarlo. si después de leer el número lo siguiente es el salto de línea, el usuario escribió solo el número.
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
    int option = readInt("Escoge una opcion: ", 0, 10);
    const int maxDimension = 50;

    cout<<"Cuales son las dimensiones del tablero: "<<endl<<endl;

    int rows = readInt("Ingresa el numero de filas: ", 1, maxDimension);
    int columns = readInt("Ingresa el numero de columnas: ", 1, maxDimension);



    createBoard(rows, columns);

    cout<<endl;
    cout<<"Bytes reservados: "<<tableBytes<<endl;

    cout << locatePiece(2, 3) << endl;

    freeBoard();


    do{

        cout << endl;




    }while(option !=0);



    return 0;
}
