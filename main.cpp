#include <iostream>
#include <cstdlib>   // srand, rand
#include <ctime>     // time
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

    srand(time(0));

    createBoard(rows, columns);
    fillRandom();

    cout<<endl;

    for (int f = 0; f < tableRows; f++) {
        for (int c = 0; c < tableColumns; c++) {
            cout<<getPiece(f, c)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


    removePiece(0,2);

    cout<<endl;


    for (int f = 0; f < tableRows; f++) {
        for (int c = 0; c < tableColumns; c++) {
            cout<<getPiece(f, c)<<" ";
        }
        cout<<endl;
    }

    freeBoard();

    return 0;
}
