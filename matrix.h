#ifndef MATRIX_H
#define MATRIX_H

#include "stdlib.h"
#include "stdio.h"
#include "math.h"

typedef enum {
	false, true
}Boolean;

typedef float Mel; //matrix element

typedef Mel* Row;

typedef Mel* Column;

typedef struct vector
{
	int dim;
	Mel* data;
}Vect;

typedef Row* rowArr;

typedef struct matrix
{
	int rows, columns;
	rowArr data;
}Matrix;

//--------------------------------------------------------------------------------------------------------------------------------
//														 FUNCTIONS
//--------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------MATRICES-----------------------------------------------------------------

Matrix emptyMatrix(int rows, int columns); //allocate the necessary space for a matrix

void freeMatrix(Matrix m); //deallocate matrix memory from heap

int printMatrix(Matrix m); //yeah

void matrixAddRow(Matrix* empty, Row rowToInsert, int rowToChange); //use arrays to add/modify rows of a matrix

Matrix inputMatrix(); //allows user to create matrix from stdin
										
Matrix copyMatrix(Matrix m); //returns a copy of a matrix m

Matrix identityMatrix(int rows, int columns); //returns an identity matrix of a chosen size

Matrix matrixSum(Matrix m1, Matrix m2); 
										//matrix sum
Matrix matrixSub(Matrix m1, Matrix m2);

Matrix matrixProd(Matrix m1, Matrix m2); //matrix-matrix multiplication

Matrix baseChange(Matrix A, Matrix C); //change base

int rankMatrix(Matrix m); //determines the rank of a matrix

void fillMatrix(Matrix* m, Mel n); //fill an entire matrix with a chosen element
							
Matrix subMatrix(Matrix m, int rowToElim, int colToElim); //create a submatrix

float detMatrix(Matrix m); //returns the determinant of a matrix using REF

float laplaceDetMatrix(Matrix m); //determinant using recursion (less efficient)

Matrix rowEchelon(Matrix m); //returns a copy of m in REF

Matrix reducedRowEch(Matrix m); //fives a copy of m in normalized REF

Matrix inverseMatrix(Matrix m); //uses gauss-jordan elimination to find the inverse of a matrix

int matrixSort(Matrix a[]); //sort in decreasing order

//---------------------------------------------------------VECTORS----------------------------------------------------------------

Vect emptyVect(int dim); //allocate the necessary space for a vector

void freeVect(Vect v); //deallocate vector memory from heap

int defineVect(Vect empty, float arr[], int dimArr); //use an array to define a vector

int printVect(Vect v); //yup

Vect linearApp(Vect v, Matrix m); //matrix-vector multiplication

Mel scalarProd(Vect v1, Vect v2); //scalar product between two vectors

Vect rowToVect(Matrix m, int Row);
										//converts a row/column of a matrix into a vector
Vect columnToVect(Matrix m, int column);

//-----------------------------------------------------------MISC-----------------------------------------------------------------
Boolean isRowEchelon(Matrix m); //yup

void exchangeRows(Row* a, Row* b); //exchange two rows

Boolean isTriangular(Matrix m); //check if m is triangular

Boolean zeroRow(Row r, int dim); //check if a row is zeros-only

int nonZeroRows(Matrix m); //finds the number of non-zero rows

//--------------------------------------------------------------------------------------------------------------------------------
//													Not intended for use
//--------------------------------------------------------------------------------------------------------------------------------

Matrix rowEchDet(Matrix m, int* exchanges); //the same as rowEchelon() but it counts how many exchanges were made (for detMatrix())
											
Boolean findPivot(int start, Matrix c, int* pivot, int* pivotR); //used in REF functions to find pivot 
																 
void sub_matrixAdd(Matrix* m, Mel el, int* row, int* column); //adds into a matrix an element and moves forward into the matrix

int MbubbleSort(Matrix v[]); 

int compareRow(Row e1, Row e2, int dim); //for sorting, rows with smaller pivot indexes are "bigger"

void normalizeMel(Matrix* m, int pivotR, int j, float norma); //normalize a sigle element

void op_gaussJordan(Matrix* c, Matrix* inverse); //performs reducedRowEch() the first, performs the same operations on the second
												 //used for inverseMatrix()

#endif
