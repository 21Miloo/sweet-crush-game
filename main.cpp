#include <iostream>
#include "board.h"

using namespace std;

int main()
{
    int rows;
    int columns;
    cout<<"Cuales son las dimensiones del tablero: "<<endl<<endl;

    cout<<"Ingresa el numero de filas: ";
    cin>>rows;
    while (cin.fail() || rows <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Valor invalido, ingresa el numero de filas nuevamente: ";
        cin>>rows;
    }

    cout<<"Ingresa el numero de columnas: ";
    cin>>columns;
    while (cin.fail() || columns <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Valor invalido, ingresa el numero de columnas nuevamente: ";
        cin>>columns;
    }

    createBoard(rows, columns);

    cout<<endl;
    cout<<"Bytes reservados: "<<tableBytes<<endl;

    cout << locatePiece(2, 3) << endl;

    freeBoard();

    return 0;
}
