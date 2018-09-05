#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vector * newVector() {
	Vector * new_v = malloc(sizeof(Vector));

	new_v->current_size = 0;
  new_v->max_size = 0;
	new_v->data = NULL;
	new_v->read = readVector;
	new_v->insert = insertVector;
	new_v->remove = removeVector;
	new_v->delete = deleteVector;
	return new_v;
}

void insertVector(Vector * v, int index, Data data) {
	if (index >= v->max_size) {
		v->max_size = index * 2 + 1;
		Data * new_data = calloc(v->max_size,sizeof(data));
		memcpy(new_data, v->data, v->current_size * sizeof(int));
		free(v->data);
		v->data = new_data;
	}
	
	if (v->current_size <= index) {
		v->current_size = index + 1;
	}
	v->data[index] = data;
}

void * deleteVector(Vector * v) {
	free(v->data);
	free(v);
}

void removeVector(Vector * v, int index) {
  int size = sizeof(v->data)/sizeof(int);
  for (int i = index ; i < size - 1; i++) {
	    v->data[i] = v->data[i+1];	
	}
  v->current_size = index;
}

Data * readVector(Vector * v, int index) {
    if (index > v->max_size) {
        return NULL;
    } else if ((&v->data[index])->value==0) {	
	      (&v->data[index])->value=-1;
	      return &v->data[index];
    } else {
        return &v->data[index];
    }  
}