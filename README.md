# Flynnz's Library for Linear Algebra

> I decided to write this library for the sole reason of challenging myself and getting better at coding. Use it for your projects at your own risk (please don't).
> There are many much better, more efficient, and much safer linear algebra libraries available.

---

## FUNCTIONS

- `Matrix emptyMatrix(int rows, int columns):` allocate the necessary space for a matrix 

- `Matrix nullMatrix():` matrix with NULL value, 0 rows and 0 columns

- `void freeMatrix(Matrix m):` deallocate matrix memory from heap

- `int printMatrix(Matrix m):` print matrix contents

- `Matrix defineMatrix(mel arr[], int rows, int columns):` create a Matrix using an array defined on the stack

- `void matrixChangeRow(Matrix* empty, Row rowToInsert, int rowToChange):` use arrays to add or modify rows of a matrix

- `Matrix inputMatrix():` allow user to create a matrix from stdin

- `Boolean sameMatrices(Matrix m1, Matrix m2):` 

- `Matrix copyMatrix(Matrix m):` return a copy of matrix `m`

- `Matrix identityMatrix(int rows, int columns):` return an identity matrix of a chosen size

- `Matrix zeroMatrix(int rows, int columns):` zero matrix of chosen size

- `Boolean isZeroMatrix(Matrix m):` check whether a matrix is a zero matrix

- `Matrix matrixSum(Matrix m1, Matrix m2):` matrix sum  
- `Matrix matrixSub(Matrix m1, Matrix m2):` matrix subtraction

- `Matrix matrixProd(Matrix m1, Matrix m2):` matrix–matrix multiplication

- `Matrix baseChange(Matrix A, Matrix C):` change basis

- `int rankMatrix(Matrix m):` determine the rank of a matrix

- `Boolean isSorted(Matrix m):` check whether matrix is sorted

- `void printKerMatrix(Matrix m):` compute and print the equations defining the kernel

- `void fillMatrix(Matrix* m, Mel n):` fill an entire matrix with a chosen element

- `Matrix subMatrix(Matrix m, int rowToElim, int colToElim):` create a submatrix

- `float detMatrix(Matrix m):` return the determinant using REF

- `float laplaceDetMatrix(Matrix m):` determinant using recursive Laplace expansion (less efficient)

- `Matrix rowEchelon(Matrix m):` return a copy of `m` in REF

- `Matrix reducedRowEch(Matrix m):` return a copy of `m` in normalized REF

- `Matrix inverseMatrix(Matrix m):` compute the inverse using Gauss–Jordan elimination

- `int matrixSort(Matrix a[]):` sort matrices in decreasing order

- `Boolean fullRank(Matrix m):` check whether matrix has full rank

---

## VECTORS

- `Vect emptyVect(int dim):` allocate the necessary space for a vector

- `Vect nullVect():` null vector with size 0 and NULL value

- `Vect zeroVect(int dim):` zero vector of given dimension

- `void freeVect(Vect v):` deallocate vector memory from heap

- `int defineVect(Vect empty, float arr[], int dimArr):` use an array to define a vector

- `Vect copyVect(Vect v):` return a copy of vector `v`

- `Vect vectSum(Vect v1, Vect v2):` vector sum

- `Vect scaleVect(Vect vector, Mel k):` multiply a vector by a scalar value

- `int printVect(Vect v):` print vector contents

- `Vect linearApp(Vect v, Matrix m):` matrix–vector multiplication

- `Mel scalarProd(Vect v1, Vect v2):` scalar product between two vectors

- `Vect rowToVect(Matrix m, int row):` convert a row of a matrix into a vector

- `Vect columnToVect(Matrix m, int column):` convert a column of a matrix into a vector

---

## MISC

- `Boolean isRowEchelon(Matrix m):` check whether matrix is in row echelon form

- `void exchangeRows(Row* a, Row* b):` exchange two rows

- `Boolean isTriangular(Matrix m):` check whether matrix is triangular

- `Boolean isZeroRow(Row r, int dim):` check whether a row contains only zeros

- `int nonZeroRows(Matrix m):` return the number of non-zero rows