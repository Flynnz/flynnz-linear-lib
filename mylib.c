#include "mylib.h"

Structure1 readOneArray(FILE* fp)
{
	Structure1 oneLine = -1;
	//EOF condition
	if (fscanf_s(fp, "%d", &oneLine) <= 0) { oneLine = -1; }
	else
	{
		//fscanf_s(fp, "% % % % % ", );
	}
	return oneLine;
}

Structure2 readOneList(FILE* fp)
{
	Structure2 oneLine = -1;
	//EOF condition
	if (fscanf_s(fp, "%d", &oneLine) <= 0) { oneLine = -1; }
	else
	{
		//fscanf_s(fp, "% % % % % ", );
	}
	return oneLine;
}

void printOneArray(Structure1 s)
{
	//printf("% % % % % ", );
}

void printOneList(Structure2 s)
{
	//printf("% % % % % ", );
}

//determines dim for dynamic arrays
int howManyLines(FILE* fp)
{
	int i = 0;
	while (readOneArray(fp) > 0)
		i++;
	rewind(fp);
	return i;
}

//save inside a dynamic array
Structure1* readAllArray(char* fileName, int* dim)
{
	Structure1 temp, * result = NULL;
	int i = 0;

	FILE* fp; //delete if file is passed as parameter
	fp = fopen(fileName, "r");

	if (fp == NULL) { printf("\nFile opening error\n"); }
	else
	{
		*dim = howManyLines(fp);
		result = (Structure1*)malloc(sizeof(Structure1) * (*dim));
		if (result == NULL) { printf("\nMemory allocation error\n"); }
		else
		{
			temp = readOneArray(fp);
			while (temp > 0 && i < *dim)
			{
				result[i] = temp;
				i++;
				temp = readOneArray(fp);
			}
		}
		fclose(fp); //delete if file is passed as parameter
	}
	return result;
}

void printAllArray(Structure1* s, int dim)
{
	int i = 0;
	for (i; i < dim; i++)
	{
		printOneArray(s[i]);
		printf("\n");
	}
}

//save inside a list
list readAllList(char* fileName)
{
	Structure2 temp;
	list result = emptyList();

	FILE* fp;
	fp = fopen(fileName, "r");
	if (fp == NULL) { printf("\nFile opening error\n"); }
	else
	{
		temp = readOneList(fp);
		while (temp > 0)
		{
			result = cons(temp, result);
			temp = readOneList(fp);
		}
		fclose(fp);
	}
	return result;
}

void showListStruct(list l) {
	printf("[");
	while (!empty(l)) {
		printOneList(head(l));
		l = tail(l);
		if (!empty(l)) printf("\n");
	} printf("]\n");
}

//others
Structure2* listToArray(list l, int* dimArray)
{
	int i = 0;
	list marker = l;
	Structure2* result = NULL;

	*dimArray = length(l);
	result = (Structure2*)malloc(sizeof(Structure2) * (*dimArray));
	if (result == NULL) { printf("\nMemory allocation error\n"); }
	else
	{
		while (!empty(marker) && i < *dimArray)
		{
			result[i] = head(marker);
			marker = tail(marker);
			i++;
		}
	}
	return result;
}

list arrayToList(Structure2* v, int dimArray)
{
	int i = 0;
	list result = emptyList();

	while (i < dimArray)
	{
		result = cons(v[i], result);
		i++;
	}
	return result;
}

//readfield
int freadUntil(FILE* fp, char string[], int dim, char stop) {
	int i = 0, c;

	if (dim <= 0) { return 0; }
	c = fgetc(fp);
	while (i < dim && c != stop && c != EOF && c != '\0') {
		if (c != '\n') //avoid registering \newlines
		{
			string[i] = (char)c;
			i++;
		}
		c = fgetc(fp);
	}
	string[i] = '\0';
	if (c == EOF) { return -1; }
	else { return i; }
}

//stampa singoli elementi da file binario
void printBinary(FILE* file) {
	type n;
	while (fread(&n, sizeof(type), 1, file) == 1) {
		printf("%d ", n); //...
	}
}


//...
//useless
int myArray(int v[], int max) {
	int input, i = 0;
	printf("\n-->Creazione array... \n");
	printf("  (Inserisci 0 per terminare)\n\n");
	printf("-->Inserisci elementi: ");
	scanf_s("%d", &input);
	while (input != 0 && i < max) {
		v[i] = input;
		i++;
		if (input != 0 && i < max)
			scanf_s("%d", &input);
	}
	return i;
}

int printArray(int toPrint[], int dimLogic)
{
	int i = 0;
	printf("\nArray: [ ");
	while (i < dimLogic)
	{
		printf("%d ", toPrint[i]);
		i++;
	}
	printf("]");
	return i;
}

//differenza fra orari
int timeDifference(Time t1, Time t2) {
	int result;
	result = ((t1.hour) * 60 + t1.minute) - ((t2.hour) * 60 + t2.minute);
	if (result > 0)
		return result;
	else
		return -result;
}

//orario + minuti = nuovo orario
Time getTranslatedTime(Time t, int min) {
	int i = 0;
	t.minute += min;
	while (t.minute > 60) {
		(t.hour)++;
		(t.minute) -= 60;
	}
	return t;
}

int factorial(int n) {
	if (n <= 1)
		return 1;
	else
		return n * (factorial(n - 1));
}