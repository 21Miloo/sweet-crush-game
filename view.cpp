#include <iostream>
#include "view.h"


// El tablero guarda un chorro de bits (unsigned char* table, 3 bits por ficha)

// ¿Porque creamos el tablero con parametros y no simplemente usando los valores que retornan las funciones de board?
// R: porque de esta manera se puede trabajar en paralelo construyendo el tablero con datos ficticios sin necesidad de esperar la implementacion de las funciones del board
void showBoard(const unsigned char* table, int rows, int columns){


    // La lógica es dos bucles anidados: recorres filas, y dentro columnas; por cada casilla obtienes el valor de la ficha y lo imprimes; al terminar cada fila, un salto de línea.


}