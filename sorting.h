#ifndef SORTING_H
#define SORTING

void exchange(int* a, int* b);

int findMaxPos(int v[], int n);

void naiveSort(int v[], int n);

void bubbleSort(int v[], int n);

void insOrd(int v[], int pos);

void insertSort(int v[], int n);

void merge(int v[], int i1, int i2,
	int end, int vout[]);

void mergeSort(int v[], int first, int last,
	int vout[]);

void quickSortR(int a[], int start, int end);

void quickSort(int a[], int dim);

#endif