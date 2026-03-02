#include "matrix.h"
#include "assert.h"

#define ROWS 3
#define COLS 3
#define N_ELEMENTS ROWS*COLS

int main(void)
{

	//debug

	//sameMatrices
	const int rows = 3;
	const int cols = 3;

	mel randomMatrixArray[N_ELEMENTS] = { 1,2,3,4,5,6,7,8,9 };
	mel identityArray[N_ELEMENTS] = { 1,0,0,0,1,0,0,0,1 };

	Matrix randomMatrix = defineMatrix(randomMatrixArray, ROWS, COLS);
	Matrix otherMatrix = defineMatrix(randomMatrixArray, ROWS, COLS);

	assert(sameMatrices(randomMatrix, otherMatrix));
	
	freeMatrix(randomMatrix);
	freeMatrix(otherMatrix);

	//identityMatrix
	Matrix identity = identityMatrix(rows, cols);
	Matrix manualIdentity = defineMatrix(identityArray, ROWS, COLS);
	
	assert(sameMatrices(identity, manualIdentity));

	freeMatrix(identity);
	freeMatrix(manualIdentity);

	//nullMatrix
	Matrix null = nullMatrix();
	
	assert(null.rows == 0 && null.cols == 0 && null.data == NULL);

	//zeroMatrix

	mel allzeros[N_ELEMENTS] = { 0,0,0,0,0,0,0,0,0 };

	Matrix allZerosMatrix = defineMatrix(allzeros, ROWS, COLS);
	Matrix allZerosMatrix_function = zeroMatrix(ROWS, COLS);

	assert(sameMatrices(allZerosMatrix, allZerosMatrix_function));

	freeMatrix(allZerosMatrix_function);

	//copyMatrix

	Matrix original = defineMatrix(randomMatrixArray, ROWS, COLS);
	Matrix copy = copyMatrix(original);

	assert(sameMatrices(original, copy));

	freeMatrix(original);
	freeMatrix(copy);

	//rankMatrix

	mel arr_calcR1[4 * 2] = {1, 2, 3, 0 , 0 , 0 ,2, -1};

	Matrix calcR1 = defineMatrix(arr_calcR1, 4, 2);
	printf("Rank calc: (2)\n");
	printMatrix(calcR1);
	mel one[1] = { 1 };
	mel zero[1] = { 0 };
	Matrix scalar = defineMatrix(one, 1, 1);
	Matrix zeroScalar = defineMatrix(zero, 1, 1);

	assert(rankMatrix(calcR1) == 2);

	assert(rankMatrix(null) == 0);

	assert(rankMatrix(allZerosMatrix) == 0);

	assert(rankMatrix(scalar) == 1);

	assert(rankMatrix(zeroScalar) == 0);

	freeMatrix(allZerosMatrix);
	freeMatrix(calcR1);

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
