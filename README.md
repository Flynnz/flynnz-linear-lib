```
███████╗██╗  ██╗   ██╗███╗   ██╗███╗   ██╗███████╗
██╔════╝██║  ╚██╗ ██╔╝████╗  ██║████╗  ██║╚══███╔╝
█████╗  ██║   ╚████╔╝ ██╔██╗ ██║██╔██╗ ██║  ███╔╝
██╔══╝  ██║    ╚██╔╝  ██║╚██╗██║██║╚██╗██║ ███╔╝
██║     ███████╗██║   ██║ ╚████║██║ ╚████║███████╗
╚═╝     ╚══════╝╚═╝   ╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝
         L I N E A R   A L G E B R A   L I B
```

> *I decided to write this library for the sole reason of challenging myself and getting better at coding.*
> *Use it for your projects at your own risk — please don't.*
> *There are many much better, more efficient, and much safer linear algebra libraries available.*

---

## ⚠️ Disclaimer

This is a **personal learning project**. It is not optimized, not battle-tested, and not production-ready. You have been warned.

---

## 📐 Types

| Type | Description |
|------|-------------|
| `mel` | Matrix element (`float`) |
| `Row` | Pointer to a row (`mel*`) |
| `Column` | Pointer to a column (`mel*`) |
| `Vect` | Vector struct — `dim` + `mel* data` |
| `Matrix` | Matrix struct — `rows`, `cols` + `rowArr data` |
| `L_EQ` | Linear equation struct — `id`, `Vect value`, `Boolean varIsolated` |

---

## 🧮 Matrices

### Memory & I/O

```c
Matrix emptyMatrix(int rows, int columns);
```
Allocate the necessary space for a matrix.

```c
Matrix nullMatrix();
```
Return a matrix with `NULL` data, `0` rows and `0` columns.

```c
void freeMatrix(Matrix m);
```
Deallocate matrix memory from the heap.

```c
int printMatrix(Matrix m);
```
Print the contents of a matrix.

```c
Matrix defineMatrix(mel arr[], int rows, int columns);
```
Create a `Matrix` from a flat array defined on the stack.

```c
void matrixChangeRow(Matrix* m, Row rowToInsert, int rowToChange);
```
Use arrays to add or modify rows of a matrix.

```c
Matrix inputMatrix();
```
Interactively create a matrix from `stdin`.

---

### Construction

```c
Matrix identityMatrix(int rows, int columns);
```
Return an identity matrix of chosen size.

```c
Matrix zeroMatrix(int rows, int columns);
```
Return a zero matrix of chosen size.

```c
void fillMatrix(Matrix* m, mel n);
```
Fill an entire matrix with a single chosen element.

```c
Matrix copyMatrix(Matrix m);
```
Return a deep copy of matrix `m`.

---

### Predicates

```c
Boolean sameMatrices(Matrix m1, Matrix m2);
```
Check whether two matrices are element-wise equal.

```c
Boolean isZeroMatrix(Matrix m);
```
Check whether a matrix contains only zeros.

```c
Boolean fullRank(Matrix m);
```
Check whether a matrix has full rank.

```c
Boolean isSorted(Matrix m);
```
Check whether a matrix is sorted.

---

### Arithmetic

```c
Matrix matrixSum(Matrix m1, Matrix m2);
```
Return `m1 + m2`.

```c
Matrix matrixSub(Matrix m1, Matrix m2);
```
Return `m1 - m2`.

```c
Matrix matrixProd(Matrix m1, Matrix m2);
```
Return the matrix product `m1 × m2`.

---

### Advanced Operations

```c
int rankMatrix(Matrix m);
```
Determine the rank of a matrix.

```c
float detMatrix(Matrix m);
```
Return the determinant using Row Echelon Form.

```c
float laplaceDetMatrix(Matrix m);
```
Return the determinant via recursive Laplace expansion *(less efficient)*.

```c
Matrix rowEchelon(Matrix m);
```
Return a copy of `m` in Row Echelon Form (REF).

```c
Matrix reducedRowEch(Matrix m);
```
Return a copy of `m` in Reduced Row Echelon Form (RREF).

```c
Matrix inverseMatrix(Matrix m);
```
Compute the inverse of `m` using Gauss–Jordan elimination.

```c
Matrix subMatrix(Matrix m, int rowToElim, int colToElim);
```
Return the submatrix obtained by removing a given row and column.

```c
Matrix baseChange(Matrix A, Matrix C);
```
Perform a change of basis from basis `A` to basis `C`.

```c
void printKerMatrix(Matrix m);
```
Compute and print the equations defining the kernel of `m`.

```c
int matrixSort(Matrix a[]);
```
Sort a matrix's rows in decreasing order.

---

## 📏 Vectors

### Memory & I/O

```c
Vect emptyVect(int dim);
```
Allocate the necessary space for a vector.

```c
Vect nullVect();
```
Return a null vector with `dim = 0` and `data = NULL`.

```c
Vect zeroVect(int dim);
```
Return a zero vector of given dimension.

```c
void freeVect(Vect v);
```
Deallocate vector memory from the heap.

```c
int defineVect(Vect empty, float arr[], int dimArr);
```
Populate a vector using a float array.

```c
Vect copyVect(Vect v);
```
Return a deep copy of vector `v`.

```c
int printVect(Vect v);
```
Print the contents of a vector.

---

### Arithmetic

```c
Vect vectSum(Vect v1, Vect v2);
```
Return `v1 + v2`.

```c
Vect scaleVect(Vect vector, mel k);
```
Return `v` multiplied by scalar `k`.

```c
mel scalarProd(Vect v1, Vect v2);
```
Return the scalar (dot) product `v1 · v2`.

```c
Vect linearApp(Vect v, Matrix m);
```
Return the matrix–vector product `m × v`.

---

### Conversion

```c
Vect rowToVect(Matrix m, int row);
```
Convert a row of `m` into a vector.

```c
Vect columnToVect(Matrix m, int column);
```
Convert a column of `m` into a vector.

---

## 🔧 Misc / Utilities

```c
Boolean isRowEchelon(Matrix m);
```
Check whether `m` is in Row Echelon Form.

```c
Boolean isTriangular(Matrix m);
```
Check whether `m` is triangular (upper or lower).

```c
Boolean isZeroRow(Row r, int dim);
```
Check whether a row contains only zeros.

```c
int nonZeroRows(Matrix m);
```
Return the number of non-zero rows in `m`.

```c
void exchangeRows(Row* a, Row* b);
```
Swap two rows in-place.

---

## 📁 Project Structure

```
.
├── matrix.h          # Type definitions & function prototypes
└── matrix.c          # Library implementation
```

---

*Made by Flynnz — a learning project, nothing more.*
