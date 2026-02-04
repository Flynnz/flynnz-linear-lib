#include "matrix.h"

Matrix emptyMatrix(int rows, int columns)
{
	int i;
	Matrix final;
	final.data = (rowArr)malloc(sizeof(Row) * rows);
	if (final.data == NULL) { printf("\nRows creation error\n"); final.rows = 0; final.columns = 0; }
	else
	{
		final.rows = rows;
		final.columns = columns;
		for (i = 0; final.data != NULL && i < rows; i++)
		{
			final.data[i] = (Row)malloc(sizeof(Mel) * columns);
			if (final.data[i] == NULL) { printf("\nRow n.%d creation error\n", i); }
		}
	}
	return final;
}

void matrixAddRow(Matrix* empty, Row rowToInsert, int rowToChange)
{
	int i;
	for (i = 0; i < empty->columns; i++)
		empty->data[rowToChange][i] = rowToInsert[i];
}

void inputMatrix(Matrix* empty)
{
	int i = 0, j;
	printf("Max number of rows: %d\n", empty->rows);
	while (i < empty->rows)
	{
		printf("Insert row n.%d\n", i + 1);
		for (j = 0; j < empty->columns; j++)
			scanf_s("%f", &(empty->data[i][j]));
		i++;
	}
}

int printMatrix(Matrix m)
{
	int i, j, k = 0;
	if (m.data == NULL || m.rows == 0 || m.columns == 0)
		printf("NULL\n");
	else
	{
		for (i = 0; i < m.rows; i++)
		{
			printf("|");
			for (j = 0; j < m.columns; j++)
			{
				if (m.data[i][j] >= 10.0 || (m.data[i][j] < 0.0 && m.data[i][j] > -10.0))
					printf("  %.2f", m.data[i][j]);
				else
				{
					if (m.data[i][j] >= 100.0 || m.data[i][j] <= -10.0)
						printf(" %.2f", m.data[i][j]);
					else
						printf("   %.2f", m.data[i][j]);
				}
				k++;
			}
			printf("   |\n");
		}
	}
	return k;
}

int freeMatrix(Matrix m)
{
	int i;
	for (i = 0; i < m.rows; i++)
		free(m.data[i]);
	free(m.data);
	return i;
}

Matrix matrixSum(Matrix m1, Matrix m2)
{
	Matrix result;
	int i, j;
	result.rows = 0;
	result.columns = 0;
	result.data = NULL;
	if ((m1.rows != m2.rows) || (m1.columns != m2.columns))
		printf("\n!Incompatible matrices!\n");
	else
	{
		result = emptyMatrix(m1.rows, m1.columns);
		if (result.data == NULL) { printf("\nMatrix creation error\n"); }
		else
			for (i = 0; i < m1.rows; i++)
				for (j = 0; j < m1.columns; j++)
					result.data[i][j] = m1.data[i][j] + m2.data[i][j];
	}
	return result;
}

Matrix matrixSub(Matrix m1, Matrix m2)
{
	Matrix result;
	int i, j;
	result.rows = 0;
	result.columns = 0;
	result.data = NULL;
	if ((m1.rows != m2.rows) || (m1.columns != m2.columns))
		printf("\n!Incompatible matrices!\n");
	else
	{
		result = emptyMatrix(m1.rows, m1.columns);
		if (result.data == NULL) { printf("\nMatrix creation error\n"); }
		else
			for (i = 0; i < m1.rows; i++)
				for (j = 0; j < m1.columns; j++)
					result.data[i][j] = m1.data[i][j] - m2.data[i][j];
	}
	return result;
}

Vect emptyVect(int dim)
{
	Vect result;
	result.dim = 0;
	result.data = (Mel*)malloc(sizeof(Mel) * dim);
	if (result.data == NULL) { printf("\nVector creation error\n"); }
	else
		result.dim = dim;
	return result;
}

int defineVect(Vect empty, float arr[], int dimArr)
{
	int i = 0;
	if (dimArr != empty.dim) { printf("\nArray size doesn't match vector size\n"); }
	else
		for (i; i < empty.dim; i++)
			empty.data[i] = arr[i];
	return i;
}

void freeVect(Vect v)
{
	free(v.data);
}

int printVect(Vect v)
{
	int i;
	printf("| ");
	for (i = 0; i < v.dim; i++)
	{
		printf("%.2f ", v.data[i]);
		if (i < v.dim - 1)
			printf(", ");
	}
	printf("|");
	return i;
}

Vect linearApp(Vect v, Matrix m)
{
	Vect result;
	int i, j;
	result.data = NULL;
	result.dim = 0;

	if (v.dim != m.columns) { printf("\nIncompatible application\n"); }
	else
	{
		result = emptyVect(v.dim);
		for (i = 0; i < m.rows; i++)
		{
			result.data[i] = 0;
			for (j = 0; j < m.columns; j++)
				result.data[i] += (v.data[j] * m.data[i][j]);
		}
	}
	return result;
}

Matrix matrixProd(Matrix m1, Matrix m2)
{
	Matrix product;
	int i, j, k;
	product.data = NULL;
	product.rows = 0;
	product.columns = 0;
	if ((m1.columns != m2.rows) || (m2.columns != m1.rows)) { printf("\n!Incompatible matrices!\n"); }
	else
	{
		product = emptyMatrix(m1.rows, m2.columns);
		for (i = 0; i < m1.rows; i++)
		{
			for (j = 0; j < m1.columns; j++)
			{
				product.data[i][j] = 0;
				for (k = 0; k < m1.rows; k++)
					product.data[i][j] += m1.data[i][k] * m2.data[k][j];
			}
		}
	}
	return product;
}

Vect columnToVect(Matrix m, int columnNumber)
{
	Vect result;
	result = emptyVect(m.rows);
	int i;
	for (i = 0; i < m.rows; i++)
		result.data[i] = m.data[i][columnNumber];
	return result;
}

Vect rowToVect(Matrix m, int rowNumber)
{
	Vect result;
	result = emptyVect(m.columns);
	int i;
	for (i = 0; i < m.columns; i++)
		result.data[i] = m.data[rowNumber][i];
	return result;
}

Mel scalarProd(Vect v1, Vect v2)
{
	int i;
	Mel result = -1000;

	if (v1.dim != v2.dim) { printf("\nIncompatible vectors\n"); }
	else
	{
		for (i = 0; i < v1.dim; i++)
			result += v1.data[i] * v2.data[i];
	}
	return result;
}

Matrix subMatrix(Matrix m, int r, int c)
{
	int i, j, k = 0, t = 0;
	Mel elem;
	Matrix result;
	result.data = NULL;
	result.rows = 0;
	result.columns = 0;

	if (m.rows != m.columns) { printf("\nSubmatrix not allowed\n"); }
	else
	{
		result = emptyMatrix(m.rows - 1, m.columns - 1);
		for (i = 0; i < m.rows; i++)
		{
			for (j = 0; j < m.rows; j++)
			{
				if (i != r && j != c)
				{
					elem = m.data[i][j];
					sub_matrixAdd(&result, elem, &k, &t);
				}
			}
		}
	}
	return result;
}

void sub_matrixAdd(Matrix* m, Mel el, int* row, int* column)
{
	m->data[*row][*column] = el;
	if (*column < m->columns - 1)
		(*column)++;
	else
	{
		if (*column == m->columns - 1 && *row < m->rows - 1)
		{
			(*row)++;
			*column = 0;
		}
	}
}

float laplaceDetMatrix(Matrix m)
{
	int i = m.columns - 1;
	float determinant = 0;
	if (rankMatrix(m) != m.rows) { printf("\nDeterminant not allowed\n"); }
	else
	{
		if (m.rows == 1)
			return m.data[0][0];
		else
		{
			while (i >= 0)
			{
				determinant += m.data[m.rows - 1][i] * (float)pow(-1, m.rows - 1 + i) * laplaceDetMatrix(subMatrix(m, m.rows - 1, i));
				i--;
			}
		}
	}
	return determinant;
}

float detMatrix(Matrix m)
{
	int i, mult = 1;
	float det = 1;
	if (rankMatrix(m) != m.rows) { printf("\nDeterminant not allowed\n"); }
	else
	{
		Matrix reduced = rowEchDet(m, &mult);
		if (nonZeroRows(reduced) == m.columns)
		{
			for (i = 0; i < m.columns; i++)
				det *= reduced.data[i][i];
		}
		freeMatrix(reduced);
	}
	if (det != 0)
		det = mult * det;
	return det;
}

int rankMatrix(Matrix m)
{
	int rank = 0;
	Matrix c = emptyMatrix(m.rows, m.columns);
	c = rowEchelon(m);
	rank = nonZeroRows(c);
	return rank;
}

int nonZeroRows(Matrix m)
{
	int i, j = 0;
	for (i = 0; i < m.rows; i++)
		if (!zeroRow(m.data[i], m.columns))
			j++;
	return j;
}

/*
Matrix bruteRowEch(Matrix m)
{
	int i = 1, j, k, pivot, pivotRow = 1;
	float multiplier = 1;
	Matrix copy = copyMatrix(m);
	
	matrixSort(&copy);
	while (i < m.rows && !isRowEchelon(copy))
	{
		for (k = 0; k < copy.columns && copy.data[i][k] == 0; k++); //find pivot index
		pivot = k;
		pivotRow = i;
		while (pivot != copy.columns && i < copy.rows)
		{
			if (copy.data[i][pivot] != 0)
			{
				//float pivot;
				multiplier = copy.data[i][pivot] / copy.data[pivotRow - 1][pivot];
				//pivot = (copy.data[pivotRow - 1][pivot]);
				for (j = 0; j < copy.columns; j++)
				{
					copy.data[i][j] -= multiplier * copy.data[pivotRow - 1][j];
					//if (copy.data[pivotRow - 1][j] != 0)
					//	copy.data[pivotRow - 1][j] = copy.data[pivotRow - 1][j] / pivot; !! For RREF
				}
			}
			i++;
		}
		i = pivotRow;
		i++;
		matrixSort(&copy);
		//printf("\n...\n");
		//printMatrix(copy);
	}
	return copy;
}
*/

Matrix rowEchelon(Matrix m)
{
	Matrix c = copyMatrix(m);
	int pivot, pivotR;
	int i, j, k;
	float factor = 0;
	if (isRowEchelon(c)) { return c; }
	else
	{
		for (k = 0; k < c.rows - 1 && findPivot(k, c, &pivot, &pivotR); k++)
		{
			if (pivotR != k) //if not in "top" row, exchange
				Mexchange(&c.data[pivotR], &c.data[k]);
			pivotR = k; //now it is in "top" row
			for (i = k + 1; i < c.rows; i++)
			{
				if (c.data[pivotR][pivot] != 0)
					factor = c.data[i][pivot] / c.data[pivotR][pivot];
				else
					factor = 0;

				for (j = pivot; j < c.columns; j++)
					c.data[i][j] -= factor * c.data[k][j];
			}
		}
	}
	return c;
}

void identityCreate(Matrix* empty)
{
	int i, j;
	if (empty->rows!= empty->columns) { printf("\nIncompatible empty matrix format\n"); }
	else
	{
		for (i = 0; i < empty->rows; i++)
		{
			for (j = 0; j < empty->columns; j++)
			{
				if (i != j)
					empty->data[i][j] = 0;
				else
					empty->data[i][j] = 1;
			}
		}
	}
}

Matrix identityMatrix(int rows, int columns)
{
	Matrix identity = emptyMatrix(rows, columns);
	int i, j;
	if (identity.rows != identity.columns) { printf("\nIncompatible empty matrix format\n"); }
	else
	{
		for (i = 0; i < identity.rows; i++)
		{
			for (j = 0; j < identity.columns; j++)
			{
				if (i != j)
					identity.data[i][j] = 0;
				else
					identity.data[i][j] = 1;
			}
		}
	}
	return identity;
}

void op_gaussJordan(Matrix* c, Matrix* inverse)
{
	int k, i, j, pivot = 0, pivotR = 0;
	float factor = 0, norma = 1;
	for (k = 0; k < c->rows - 1 && findPivot(k, *c, &pivot, &pivotR); k++)
	{
		if (pivotR != k) //if not in "top" row, exchange
		{
			Mexchange(&(c->data[pivotR]), &(c->data[k]));
			Mexchange(&(inverse->data[pivotR]), &(inverse->data[k]));
		}
		pivotR = k; //now it is in "top" row
		for (i = k + 1; i < c->rows; i++)
		{
			norma = c->data[pivotR][pivot];
			if (norma != 0)
				factor = c->data[i][pivot] / norma;
			else { norma = 1; factor = 0; }
				
			for (j = 0; j < c->columns; j++)
			{
				//row sub
				c->data[i][j] -= factor * c->data[k][j];
				inverse->data[i][j] -= factor * inverse->data[k][j];

				normalizeMel(c, pivotR, j, norma);
				normalizeMel(inverse, pivotR, j, norma);
			}
		}
		//normalize last row
		if (pivotR + 1 == c->rows - 1 && c->data[pivotR + 1][c->rows - 1] != 1)
		{
			pivot = c->rows - 1;
			norma = c->data[pivotR + 1][pivot];

			for (j = 0; j < c->columns; j++)
			{
				normalizeMel(c, pivotR + 1, j, norma);
				normalizeMel(inverse, pivotR + 1, j, norma);
			}
		}
	}
}

void normalizeMel(Matrix* m, int pivotR, int j, float norma)
{
	if (m->data[pivotR][j] != 0)
		m->data[pivotR][j] = m->data[pivotR][j] / norma;
}

Matrix inverseMatrix(Matrix m)
{
	if (rankMatrix(m) != m.rows) { printf("\nInverse not allowed\n"); return emptyMatrix(0, 0); }
	else
	{
		Matrix c = copyMatrix(m);
		Matrix inverse = identityMatrix(m.rows, m.columns);
		int k, i, j;
		float multi;

		//Reduces "c" to RREF while repeating the operations on "inverse" (identity matrix)
		op_gaussJordan(&c, &inverse);

		//reduce c to Identity matrix to obtain inverse 
		for (k = c.columns - 1; k > 0; k--)
		{
			for (i = k; i > 0; i--)
			{
				multi = c.data[i - 1][k];
				if (multi != 0)
				{
					c.data[i - 1][k] -= c.data[k][k] * multi;
					for (j = 0; j < inverse.columns; j++)
						inverse.data[i - 1][j] -= inverse.data[k][j] * multi;
				}
			}
		}
		freeMatrix(c);
		return inverse;
	}
}

Matrix reducedRowEch(Matrix m)
{
	Matrix c = copyMatrix(m);
	int pivot, pivotR;
	int i, j, k;
	float factor = 0, norma = 1;
	for (k = 0; k < c.rows - 1 && findPivot(k, c, &pivot, &pivotR); k++)
	{
		if (pivotR != k) //if not in "top" row, exchange
			Mexchange(&c.data[pivotR], &c.data[k]);
		pivotR = k; //now it is in "top" row
		for (i = k + 1; i < c.rows; i++)
		{
			norma = c.data[pivotR][pivot];
			if (norma != 0)
				factor = c.data[i][pivot] / norma;
			else { norma = 1; factor = 0; }

			for (j = 0; j < c.columns; j++)
			{
				c.data[i][j] -= factor * c.data[k][j];
				normalizeMel(&c, pivotR, j, norma);
			}
		}

		//normalize last row
		if (pivotR + 1 == m.rows - 1)
		{
			for (j = 0; j < c.columns && c.data[pivotR + 1][j] == 0; j++);
			if (j > pivot) //last pivot
				pivot = j;

			if (c.data[pivotR + 1][pivot] != 0 && c.data[pivotR + 1][pivot] != 1)
			{
				norma = c.data[pivotR + 1][pivot];
				for (j = 0; j < c.columns; j++)
					normalizeMel(&c, pivotR + 1, j, norma);
			}
		}
	}
	return c;
}

Boolean findPivot(int start, Matrix c, int* pivot, int* pivotR)
{
	int i, j;
	Boolean found = 0;
	for (j = start; j < c.columns; j++)
	{
		for (i = start; i < c.rows && !found; i++)
		{
			if (c.data[i][j] != 0) //pivot found
			{
				*pivot = j;
				*pivotR = i;
				found = 1;
			}
		}
	}
	return found;
}

Matrix rowEchDet(Matrix m, int* exchanges)
{
	Matrix c = copyMatrix(m);
	int pivot, pivotR;
	int i, j, k;
	float factor = 0;
	*exchanges = 1;
	for (k = 0; k < c.rows - 1 && findPivot(k, c, &pivot, &pivotR); k++)
	{
		if (pivotR != k) //if not in "top" row, exchange
		{
			Mexchange(&c.data[pivotR], &c.data[k]);
			*exchanges *= -1;
		}
		pivotR = k; //now it is in "top" row
		for (i = k + 1; i < c.rows; i++)
		{
			factor = (c.data[i][pivot] / c.data[pivotR][pivot]);
			for (j = 0; j < c.columns; j++)
				c.data[i][j] -= factor * c.data[k][j];
		}
	}
	return c;
}

Boolean zeroRow(Row r, int dim)
{
	int j;
	Boolean zero = true;
	for (j = 0; j < dim && zero; j++)
		if (r[j] != 0)
			zero = false;
	return zero;
}

void fillMatrix(Matrix* m, Mel n)
{
	int i, j;
	for (i = 0; i < m->rows; i++)
	{
		for (j = 0; j < m->columns; j++)
		{
			m->data[i][j] = n;
		}
	}
}

Matrix copyMatrix(Matrix m)
{
	Matrix r = emptyMatrix(m.rows, m.columns);
	int i, j;

	if (m.rows == 0 || m.columns == 0) { r.data = NULL; }
	else
	{
		for (i = 0; i < m.rows; i++)
		{
			for (j = 0; j < m.columns; j++)
				r.data[i][j] = m.data[i][j];
		}
	}
	return r;
}

int MbubbleSort(Matrix v[]) 
{
	int i, sorted = 0, n, exchanged = 1;;
	n = v->rows;
	while (n > 1 && !sorted) {
		sorted = 1;
		for (i = 0; i < n - 1; i++)
			if (compareRow(v->data[i], v->data[i + 1], v->columns) > 0) 
			{
				Mexchange(&v->data[i], &v->data[i + 1]);
				sorted = 0;
				exchanged *= -1;
			}
		n--;
	}
	return exchanged;
}

int matrixSort(Matrix a[])
{
	int exchanged = MbubbleSort(a);
	return exchanged;
}

void Mexchange(Row* a, Row* b)
{
	Row tmp = *a;
	*a = *b;
	*b = tmp;
}

int compareRow(Row e1, Row e2, int dim)
{
	int result = 0, i, j;

	for (i = 0; i < dim && e1[i] == 0; i++);
	for (j = 0; j < dim && e2[j] == 0; j++);
	
	result = i - j;
	return result;
}

Boolean isTriangular(Matrix m)
{
	Boolean notUpper = false;
	Boolean notLower = false;

	if (m.rows != m.columns)
		return false;
	else
	{
		// Check upper triangular
		for (int i = 1; i < m.rows && !notUpper; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (m.data[i][j] != 0)
					notUpper = true;
			}
		}

		if (!notUpper)
			return true;

		// Check lower triangular
		for (int i = 0; i < m.rows - 1 && !notLower; i++)
		{
			for (int j = i + 1; j < m.columns; j++)
			{
				if (m.data[i][j] != 0)
					notLower = true;
			}
		}
	}
	return !notLower;
}

Boolean isRowEchelon(Matrix m)
{
	Boolean itIs = true;
	int i, j, count = 0, max = -1;
	for (i = 0; i < m.rows && itIs; i++)
	{
		for (j = 0; j < m.columns; j++)
		{
			if (m.data[i][j] == 0)
				count++;
		}
		if (count > max)
		{
			max = count;
			count = 0;
		}
		else
			itIs = false;
	}
	return itIs;
}