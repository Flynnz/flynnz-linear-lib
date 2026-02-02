#ifndef MATRIX_H
#define MATRIX_H

#include "stdlib.h"
#include "stdio.h"
#include "math.h"

typedef enum {
	false, true
}Boolean;

typedef float Melem; //matrix element

typedef Melem* Row;

typedef Melem* Column;

typedef struct vector
{
	int dim;
	Melem* data;
}Vect;

typedef Row* rowArr;

typedef struct matrix
{
	int rows, columns;
	rowArr data;
}Matrix;

Matrix emptyMatrix(int rows, int columns);

int printMatrix(Matrix m);

void matrixAddRow(Matrix* empty, Row rowToInsert, int rowToChange);

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

Melem scalarProd(Vect v1, Vect v2);

Vect columnToVect(Matrix m, int column);

Vect rowToVect(Matrix m, int Row);

void sub_matrixAdd(Matrix* m, Melem el, int* Row, int* column);

Matrix subMatrix(Matrix m, int r, int c);

float laplaceDetMatrix(Matrix m);

int compareRow(Row e1, Row e2, int dim);

void Mexchange(Row* a, Row* b);

int MbubbleSort(Matrix v[]);

int matrixSort(Matrix a[]);

Boolean isTriangular(Matrix m);

Boolean isRowEchelon(Matrix m);

Boolean zeroRow(Row r, int dim);

int rankMatrix(Matrix m);

Matrix bruteGaussJordan(Matrix m);

Matrix gaussJordan(Matrix m);

Matrix gaussJordanDet(Matrix m, int* exchanges);

void fillMatrix(Matrix* m, Melem n);

Matrix copyMatrix(Matrix m);

float detMatrix(Matrix m);

#endif
