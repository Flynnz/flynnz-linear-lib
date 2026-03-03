#include "matrix.h"
#define MATRIX_CREATION_ERROR -1
#define INVERSE_CREATION_ERROR -2

int main(void)
{
	//For a rapid showcase of the library's functionalities:

	Matrix input = inputMatrix();
	if (input.data == NULL)
	{
		return MATRIX_CREATION_ERROR;
	}
	printf("\nMatrix created successfully:\n");
	printMatrix(input);

	int rank = rankMatrix(input);
	printf("\nRank: %d\n", rank);

	Boolean isREF = false;
	isREF = isRowEchelon(input);
	if (isREF)
		printf("\nThe matrix is already in REF\n");
	else
	{
		Matrix REF = rowEchelon(input);
		printf("\nREF:\n");
		printMatrix(REF);
		freeMatrix(REF);
	}

	Matrix RREF = reducedRowEch(input);
	printf("\nRREF:\n");
	printMatrix(RREF);

	float det = detMatrix(input);
	printf("\nDeterminant: %.3f\n", detMatrix(input));

	Matrix inv = inverseMatrix(input);
	if (inv.data != NULL)
	{
		printf("\nInverse:\n");
		printMatrix(inv);
	}
	
	printf("\nNull space:\n");
	printKerMatrix(input);

	freeMatrix(input);
	freeMatrix(inv);
	freeMatrix(RREF);

	return 0;
}
