#ifndef MYLIB_H
#define MYLIB_H

#define _CRT_SECURE_NO_WARNINGS 0

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>

#include "element.h" 
#include "list.h"

Structure1 readOneArray(FILE* fp);

Structure2 readOneList(FILE* fp);

void printOneArray(Structure1 s);

void printOneList(Structure2 s);

int howManyLines(FILE* fp);

Structure1* readAllArray(char* fileName, int* dim);

void printAllArray(Structure1* s, int dim);

list readAllList(char* fileName);

void showListStruct(list l);

Structure2* listToArray(list l, int* dimArray); //pointer to dynamic array, NULL if fails

list arrayToList(Structure2* v, int dimArray); //pointer to new list or emptyList()

int freadUntil(FILE* fp, char string[], int dim, char stop);


//...
int timeDifference(Time t1, Time t2);

Time getTranslatedTime(Time t, int min);

//binary
void printBinary(FILE* file);

//arrays
int myArray(int v[], int max);

int printArray(int toPrint[], int dimLogic);

int factorial(int n);

#endif