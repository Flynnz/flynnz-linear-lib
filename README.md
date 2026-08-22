# simple linear algebra library

## features

- matrix (and Vector) ADT
- matrix linear algebra functions
- complex matrix operations (determinant, REF, etc..)

## example of use

```c
#include "matrix.h"

int main()
{
    /* heap-allocate */
    Matrix m1 = emptyMatrix(1, 3);

    /* 
     * use an array of matrix elements `mel`
     * to change a specified row 
     */
    mel arr1[] = {1, 0, -1};
    matrixChangeRow(&m1, arr1, 0);

    /* or */

    /*
     * create a `Matrix` from a flat array
     */
    mel arr2[] = {2, 0, -3, 5, 6, 0, 1, 2, 0};
    Matrix m2 = defineMatrix(arr2, 3, 3);

    printMatrix(m1);
    printf("\n");
    printMatrix(m2);

    /* deallocate */
    freeMatrix(m1);
    freeMatrix(m2);

    return 0;
}

```

expected print output:

```c
{   1.00   0.00  -1.00   }

{   2.00   0.00  -3.00   }
{   5.00   6.00   0.00   }
{   1.00   2.00   0.00   }
```

## notes

- My first side project while learning C as my first programming language.
- This is mainly a learning project, the library is not battle tested and not really
  intended for real use.
