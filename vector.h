#ifndef VECTOR_H
#define VECTOR_H

#include"data.h"
#include<stdio.h>

typedef struct Vector {
  Data * data;
	int current_size;
  int max_size;
	void (*insert)();
  Data * (*read)();
	void (*remove)();
	void (*delete)();
} Vector;

Vector * newVector();

Data * readVector(Vector * v, int index);
void insertVector(Vector * v, int index, Data data);
void removeVector(Vector * v, int index);
void * deleteVector(Vector * v);

#include "vector.c"
#endif