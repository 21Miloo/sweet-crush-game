#include <iostream>

using namespace std;

const short int TamanoFicha = 3;

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

    int bits = TamanoFicha*rows*columns;
    int bytes = (bits % 8 == 0) ? bits / 8 : bits / 8 + 1;

    unsigned char* table = nullptr;

    table = new unsigned char[bytes]();


    delete[] table;
    table = nullptr;

    return 0;
}