#include "matrix.h"

Matrix emptyMatrix(int rows, int columns)
{
	int i;
	Matrix final;
	final.data = NULL;
	final.data = (rowArr)malloc(sizeof(Row) * rows);
	if (final.data == NULL) { printf("\nColumns creation error\n"); final.rows = 0; final.columns = 0; }
	else
	{
		final.rows = rows;
		final.columns = columns;
		for (i = 0; final.data != NULL && i < rows; i++)
		{
			final.data[i] = (Row)malloc(sizeof(Melem) * columns);
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
				if ((m.data[i])[j] > 10.0 || (m.data[i])[j] < 0.0)
					printf("  %.2f", (m.data[i])[j]);
				else
					printf("   %.2f", (m.data[i])[j]);

				k++;
			}
			printf("   |");
			printf("\n");
		}
	}
	return k;
}

int freeMatrix(Matrix m)
{
	int i, k = 0;
	for (i = 0; i < m.rows; i++)
	{
		free(m.data[i]);
		k++;
	}
	free(m.data);
	return k;
}

Matrix matrixSum(Matrix m1, Matrix m2)
{
	Matrix result;
	int i, j;

	if ((m1.rows != m2.rows) || (m1.columns != m2.columns))
	{
		result.data = NULL;
		printf("\n!Incompatible matrices!\n");
	}
	else
	{
		result = emptyMatrix(m1.rows, m1.columns);
		if (result.data == NULL) { printf("\nMatrix creation error\n"); }
		else
		{
			for (i = 0; i < m1.rows; i++)
			{
				for (j = 0; j < m1.columns; j++)
				{
					result.data[i][j] = m1.data[i][j] + m2.data[i][j];
				}
			}
		}
	}
	return result;
}

Matrix matrixSub(Matrix m1, Matrix m2)
{
	Matrix result;
	int i, j;

	if ((m1.rows != m2.rows) || (m1.columns != m2.columns))
	{
		result.data = NULL;
		printf("\n!Incompatible matrices!\n");
	}
	else
	{
		result = emptyMatrix(m1.rows, m1.columns);
		if (result.data == NULL) { printf("\nMatrix creation error\n"); }
		else
		{
			for (i = 0; i < m1.rows; i++)
			{
				for (j = 0; j < m1.columns; j++)
				{
					result.data[i][j] = m1.data[i][j] - m2.data[i][j];
				}
			}
		}
	}
	return result;
}

Vect emptyVect(int dim)
{
	Vect result;
	result.data = NULL;
	result.dim = 0;
	result.data = (Melem*)malloc(sizeof(Melem) * dim);
	if (result.data == NULL) { printf("\nVector creation error\n"); }
	else
		result.dim = dim;
	return result;
}

int defineVect(Vect empty, float arr[])
{
	int i;
	for (i = 0; i < empty.dim; i++)
	{
		float test = empty.data[i];
		empty.data[i] = arr[i];
	}
	return i;
}

void freeVect(Vect v)
{
	free(v.data);
}

int printVect(Vect v)
{
	int i;
	printf("( ");
	for (i = 0; i < v.dim; i++)
	{
		printf("%.2f ", v.data[i]);
		if (i < v.dim - 1)
			printf(", ");
	}
	printf(")");
	return i;
}

Vect linearApp(Vect v, Matrix m)
{
	Vect result;
	int i, j;
	result.data = NULL;
	result.dim = 0;

	if (v.dim != m.columns) { printf("\nImpossible application\n"); }
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
	int i, j , k;
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

Vect columnToVect(Matrix m, int column)
{
	Vect result;
	result = emptyVect(m.rows);
	int i;
	for (i = 0; i < m.rows; i++)
		result.data[i] = m.data[i][column];
	return result;
}

Vect rowToVect(Matrix m, int Row)
{
	Vect result;
	result = emptyVect(m.columns);
	int i;
	for (i = 0; i < m.columns; i++)
		result.data[i] = m.data[Row][i];
	return result;
}

Melem scalarProd(Vect v1, Vect v2)
{
	int i;
	Melem result = 0;

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
	Melem elem;
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

void sub_matrixAdd(Matrix* m, Melem el, int* Row, int* column)
{
	m->data[*Row][*column] = el;
	if (*column < m->columns - 1)
		(*column)++;
	else
	{
		if (*Row < m->rows - 1)
		{
			(*Row)++;
			*column = 0;
		}
	}
}

float laplaceDetMatrix(Matrix m)
{
	int i = m.columns - 1;
	float determinante = 0;
	if (m.rows != m.columns) { printf("\nDeterminant not allowed\n"); }
	else
	{
		if (m.rows == 1)
			return m.data[0][0];
		else
		{
			while (i >= 0)
			{
				determinante += m.data[m.rows - 1][i] * (float)pow(-1, m.rows - 1 + i) * laplaceDetMatrix(subMatrix(m, m.rows - 1, i));
				i--;
			}
		}
	}
	return determinante;
}

float detMatrix(Matrix m)
{
	int i, mult = 1;
	float det = 1;
	if (m.rows != m.columns || m.data == NULL || m.rows == 0 || m.columns == 0)
		printf("\nDeterminant not allowed\n");
	else
	{
		Matrix reduced = gaussJordanDet(m, &mult);
		if (rankMatrix(reduced) == m.columns)
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
	int i, j = 0;
	for (i = 0; i < m.rows; i++)
		if (!zeroRow(m.data[i], m.columns))
			j++;
	return j;
}

Matrix bruteGaussJordan(Matrix m)
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

Matrix gaussJordan(Matrix m)
{
	Matrix c = copyMatrix(m);
	int pivot, pivotR;
	int i, j, k;
	float factor = 0;
	for (k = 0; k < c.rows - 1; k++)
	{
		pivotR = k;
		pivot = c.columns - 1;
		for (i = k; i < c.rows; i++)
		{
			for (j = 0; j < c.columns && c.data[i][j] == 0; j++);
			if (j < pivot) //pivot found
			{
				pivot = j;
				pivotR = i;
			}
		}
		if (pivotR != k) //if not in "top" row, exchange
			Mexchange(&c.data[pivotR], &c.data[k]);
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

Matrix gaussJordanDet(Matrix m, int* exchanges)
{
	Matrix c = copyMatrix(m);
	int pivot, pivotR;
	int i, j, k;
	float factor = 0;
	*exchanges = 1;
	for (k = 0; k < c.rows - 1; k++)
	{
		pivotR = k;
		pivot = c.columns - 1;
		for (i = k; i < c.rows; i++)
		{
			for (j = 0; j < c.columns && c.data[i][j] == 0; j++);
			if (j < pivot) //pivot found
			{
				pivot = j;
				pivotR = i;
			}
		}
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

void fillMatrix(Matrix* m, Melem n)
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