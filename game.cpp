#include "game.h"
#include "board.h"
#include <cstdlib>

unsigned char* marks = nullptr;
int marksBytes = 0;

void ensureMarks()
{
    int needed = (tableRows * tableColumns + 7) / 8;

    if (needed != marksBytes)
    {
        delete[] marks;
        marks = new unsigned char[needed]();
        marksBytes = needed;
    }
    else
    {
        for (int i = 0; i < marksBytes; i++) marks[i] = 0;
    }
}

void freeMarks()
{
    delete[] marks;
    marks = nullptr;
    marksBytes = 0;
}

void markCell(int index)
{
    marks[index / 8] = marks[index / 8] | (1 << (index % 8));
}

int isMarked(int index)
{
    return (marks[index / 8] >> (index % 8)) & 1;
}

int detectCombinations()
{
    ensureMarks();
    int found = 0;

    // ---- horizontal: ventana de 3 que se desliza por cada fila ----
    for (int row = 0; row < tableRows; row++)
    {
        for (int column = 0; column + 2 < tableColumns; column++)
        {
            int value = getPiece(row, column);

            if (value == 6) continue;
            if (getPiece(row, column + 1) != value) continue;
            if (getPiece(row, column + 2) != value) continue;

            markCell(row * tableColumns + column);
            markCell(row * tableColumns + column + 1);
            markCell(row * tableColumns + column + 2);

            // solo cuenta si aqui EMPIEZA la racha
            if (column == 0 || getPiece(row, column - 1) != value) found++;
        }
    }

    // ---- vertical: la misma ventana, pero hacia abajo ----
    for (int column = 0; column < tableColumns; column++)
    {
        for (int row = 0; row + 2 < tableRows; row++)
        {
            int value = getPiece(row, column);

            if (value == 6) continue;
            if (getPiece(row + 1, column) != value) continue;
            if (getPiece(row + 2, column) != value) continue;

            markCell(row * tableColumns + column);
            markCell((row + 1) * tableColumns + column);
            markCell((row + 2) * tableColumns + column);

            if (row == 0 || getPiece(row - 1, column) != value) found++;
        }
    }

    return found;
}


int removeMarkedPieces()
{
    int removed = 0;
    for (int row = 0; row < tableRows; row++)
    {
        for (int column = 0; column < tableColumns; column++)
        {
            if (isMarked(row * tableColumns + column))
            {
                removePiece(row, column);
                removed++;
            }
        }
    }
    return removed;
}

int processCascades(int& piecesRemoved, int& matches, int& score)
{
    int cascades = 0;

    while (true)
    {
        int found = detectCombinations();
        if (found == 0) break;              // el tablero se estabilizo

        int removed = removeMarkedPieces();

        matches = matches + found;
        piecesRemoved = piecesRemoved + removed;
        score = score + removed * 10 * (cascades + 1);

        applyGravity();
        cascades++;
    }

    return cascades;
}