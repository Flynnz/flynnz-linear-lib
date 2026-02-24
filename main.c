#include "matrix.h"
#include "assert.h"

#define N_ELEMENTS 9
int main(void)
{

	//debug

	//sameMatrices
	const int rows = 3;
	const int cols = 3;

	Matrix randomMatrix, m2;
	randomMatrix = emptyMatrix(rows, cols);
	m2 = emptyMatrix(rows, cols);

	mel randomMatrixArray[N_ELEMENTS] = { 1,2,3,4,5,6,7,8,9 };
	mel identityArray[N_ELEMENTS] = { 1,0,0,0,1,0,0,0,1 };

	defineMatrix(&randomMatrix, randomMatrixArray, N_ELEMENTS);
	defineMatrix(&m2, randomMatrixArray, N_ELEMENTS);

	assert(sameMatrices(randomMatrix, m2));
	
	Matrix identity = identityMatrix(rows, cols);

	//change defineMatrix so it returns a matrix directly
	Matrix manualIdentity = emptyMatrix(rows, cols);
	defineMatrix(&manualIdentity, identityArray, N_ELEMENTS);

	assert(sameMatrices(identity, manualIdentity));












	// vvv For a rapid showcase of the library's functionalities vvv

	/*
	Matrix m = inputMatrix();
	printf("\nMatrix created successfully:\n");
	printMatrix(m);

	int rank = rankMatrix(m);
	printf("\nRank: %d\n", rank);

	Boolean isREF = false;
	isREF = isRowEchelon(m);
	if (isREF)
		printf("\nThe matrix is already in REF\n");
	else
	{
		Matrix REF = rowEchelon(m);
		printf("\nREF:\n");
		printMatrix(REF);
		freeMatrix(REF);
	}

	Matrix RREF = reducedRowEch(m);
	printf("\nRREF:\n");
	printMatrix(RREF);

	float det = detMatrix(m);
	if (det != -1000)
		printf("\nDeterminant: %f\n", detMatrix(m));

	Matrix inv = inverseMatrix(m);
	if (inv.data != NULL)
	{
		printf("\nInverse:\n");
		printMatrix(inv);
	}
	
	printf("\nker:\n");
	printKerMatrix(m);

	freeMatrix(m);
	freeMatrix(inv);
	freeMatrix(RREF);

	*/
	return 0;
}
