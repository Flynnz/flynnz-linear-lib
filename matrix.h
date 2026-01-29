#ifndef MATRIX_H
#define MATRIX_H

#include "mylib.h"

Matrix emptyMatrix(int rows, int columns);

int printMatrix(Matrix m);

void matrixAddRow(Matrix* empty, row rowToInsert, int rowToChange);

void inputMatrix(Matrix* empty);

Matrix matrixSum(Matrix m1, Matrix m2);

Matrix matrixSub(Matrix m1, Matrix m2);

int freeMatrix(Matrix m);

Vect emptyVect(int dim);

int defineVect(Vect empty, float arr[]);

void freeVect(Vect v);

int printVect(Vect v);

Vect linearApp(Vect v, Matrix m);

Matrix matrixProd(Matrix m1, Matrix m2);

matrix_el scalarProd(Vect v1, Vect v2);

Vect columnToVect(Matrix m, int column);

Vect rowToVect(Matrix m, int row);

void sub_matrixAdd(Matrix* m, matrix_el el, int* row, int* column);

Matrix subMatrix(Matrix m, int r, int c);

float naiveDetMatrix(Matrix m);

#endif
