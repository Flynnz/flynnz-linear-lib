#include "sorting.h"

void exchange(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int findMaxPos(int v[], int n) {
	int i, posMax = 0;
	for (i = 1; i < n; i++)
			 //!!comparison to find posMax
		if (v[posMax] < v[i]) posMax = i;
	return posMax;
}

void naiveSort(int v[], int n) {
	int p;
	while (n > 1) {
		p = findMaxPos(v, n);
		if (p < n - 1) exchange(&v[p], &v[n - 1]);
		n--;
	}
}

void bubbleSort(int v[], int n) {
	int i, sorted = 0;
	while (n > 1 && !sorted) {
		sorted = 1;
		//smallest gets pushed to the left
		for (i = 0; i < n - 1; i++)
			//!!comparision 
			if (v[i] > v[i + 1]) {
				//remember to modify "exchange()"!!
				exchange(&v[i], &v[i + 1]);
				sorted = 0;
			}
		n--;
	}
}

void insOrd(int v[], int pos) {
	int i = pos - 1, x = v[pos];
				   //!!comparison
	while (i >= 0 && x < v[i]) {
		//shift array until it finds the slot
		v[i + 1] = v[i];
		i--;
	}
	//insert in the "new" slot
	v[i + 1] = x;
}

void insertSort(int v[], int n) {
	int k;
	//for every pos
	for (k = 1; k < n; k++)
		insOrd(v, k);
}

void merge(int v[], int i1, int i2,
	int end, int vout[]) {
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= end) {
		//!!comparison 
		if (v[i] < v[j])
			vout[k] = v[i++];
		else
			vout[k] = v[j++];
		k++;
	}
	//insert leftovers
	while (i <= i2 - 1) { vout[k] = v[i++]; k++; }
	while (j <= end) { vout[k] = v[j++]; k++; }
	//copy into initial array
	for (i = i1; i <= end; i++) v[i] = vout[i];
}

void mergeSort(int v[], int first, int last,
	int vout[]) {
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		//split down to single sized arrays
		mergeSort(v, first, mid, vout);
		mergeSort(v, mid + 1, last, vout);
		//order recursively
		merge(v, first, mid + 1, last, vout);
	}
}

void quickSortR(int a[], int start, int end)
{
	int i, j, iPivot, pivot;
	if (start < end)
	{
		i = start;
		j = end;
		iPivot = end;
		pivot = a[iPivot];
		do
		{
		//sort until it's divided in two parts one <pivot and one >pivot
							 //!!comparisons
			while (i < j && a[i] <= pivot) i++; //left side of pivot
			while (j > i && a[j] >= pivot) j--; //right side of pivot
			if (i < j) exchange(&a[i], &a[j]);
		} while (i < j);
		//put pivot in between the two parts
							//!!comparison
		if (i != iPivot && a[i] != a[iPivot])
		{
			exchange(&a[i], &a[iPivot]);
			iPivot = i;
		}
		//recursively sort the two parts
		if (start < iPivot - 1)
			quickSortR(a, start, iPivot - 1);
		if (iPivot + 1 < end)
			quickSortR(a, iPivot + 1, end);
	}
}

void quickSort(int a[], int dim)
{
	quickSortR(a, 0, dim - 1);
}