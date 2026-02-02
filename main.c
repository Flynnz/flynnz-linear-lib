#include "functions.h"
#include "matrix.h"

int main(void)
{
	int dim = 3;
	int r = 3, c = 3;
	float vettore1[3] = {1, 0, -1};
	float vettore2[3] = {2, 1, 8};

	float r1[3] = {0, 7, -1};
	float r2[3] = {1, 3, 2};
	float r3[3] = {0, 0, 4};

	float r4[4] = {1, 1, 1, 1};
	float r5[4] = {1, 2, -1, 0};
	float r6[4] = {-1, 1, 2, 1};

	float r7[5] = { 1, 9, -3,-2, 4 };
	float r8[5] = {9, 67, 3, 9, 4};
	float r9[5] = {5, 0, -12, 2, 1};
	float r10[5] = {-2, 2, 0, 0, 0};
	float r11[5] = {1, 6, 3, 22, 9};
	Vect v, w;
	Matrix m1, m2, result, m1Sub, m1SubSub, m3;
	Melem n;
	float detM;

	m1 = emptyMatrix(r, c);
	m2 = emptyMatrix(r, c + 1);

	m3 = emptyMatrix(5, 5);
	matrixAddRow(&m1, r1, 0);
	matrixAddRow(&m1, r2, 1);
	matrixAddRow(&m1, r3, 2);

	v = emptyVect(dim);
	w = emptyVect(dim);

	matrixAddRow(&m3, r7, 0);
	matrixAddRow(&m3, r8, 1);
	matrixAddRow(&m3, r9, 2);
	matrixAddRow(&m3, r10, 3);
	matrixAddRow(&m3, r11, 4);

	matrixAddRow(&m2, r4, 0);
	matrixAddRow(&m2, r5, 1);
	matrixAddRow(&m2, r6, 2);

	m1Sub = subMatrix(m1, 1, 1);
	m1SubSub = subMatrix(m1Sub, 1, 1);

	defineVect(v, vettore1);
	defineVect(w, vettore2);

	printf("Matrice 1:\n");
	printMatrix(m1);
	printf("Matrice 2:\n");
	printMatrix(m2);
	printf("Matrice 3:\n");
	printMatrix(m3);

	//test sottomatrice
	printf("Submatrice 1:\n");
	printMatrix(m1Sub);
	printf("Submatrice della submatrice 1:\n");
	printMatrix(m1SubSub);
	matrixSort(&m2);

	//test ordinamento righe matrice
	printf("Matrice 2 ordinata:\n");
	printMatrix(m2);

	//è in scala?
	Boolean rowEch = isRowEchelon(m2);

	//stampa vettori
	printf("Vettore 1:\n");
	printVect(v);
	printf("\n");
	printf("Vettore 2:\n");
	printVect(w);
	printf("\n");
	//test prodotto scalare
	n = scalarProd(v, w);
	printf("Prodotto scalare: %.2f", n);
	printf("\n");

	//test determinante con sviluppo di Laplace
	detM = detMatrix(m3);
	printf("Determinante matrice 3: %.2f", detM);
	printf("\n");

	//test moltiplicazione tra matrici
	result = matrixProd(m1, m2);
	printMatrix(result);

	//test Gauss Jordan
	Matrix inScala;
	
	inScala = gaussJordan(m3);
	printMatrix(inScala);

	freeVect(v);
	freeVect(w);
	freeMatrix(m1);
	freeMatrix(m2);
	freeMatrix(m3);
	freeMatrix(inScala);
	return 0;
}