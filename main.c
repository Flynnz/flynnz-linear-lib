#include "matrix.h"

int main(void)
{
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
	kerMatrix(m);
	
	freeMatrix(m);
	freeMatrix(inv);
	freeMatrix(RREF);
	return 0;
}
