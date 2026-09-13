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
    table[0] = 0b10101100;
    cout<<endl;
    cout<<"Bytes reservados: "<<tableBytes<<endl;

    cout<<"locatIndexPiece: "<<locateInitialBitPiece(0,0)<<endl;
    cout<<"locatebyte: "<<getPiece(0,1)<<endl;


    freeBoard();

    return 0;
}
