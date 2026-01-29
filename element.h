#ifndef ELEMENT_H
#define ELEMENT_H

typedef struct my_time
{
	int hour;
	int minute;
}Time;

typedef enum {
	False, True
} boolean;

//matrices
typedef float matrix_el;

typedef matrix_el* row;

typedef matrix_el* column;

typedef struct vector
{
	int dim;
	matrix_el* data;
}Vect;

typedef row* rowArr;

typedef struct matrix
{
	int rows, columns;
	rowArr data;

}Matrix;

//lists
typedef int element;

//other
typedef int type;

typedef int Structure1;

typedef int Structure2;

//int compare(element e1, element e2);

#endif 