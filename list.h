#ifndef LIST_H
#define LIST_H

#include"data.h"
#include<stdio.h>

typedef struct Node
{
	Data data;
  struct Node * next;
  struct Node * prev;
} Node;

typedef struct List
{
  Node * head;
  Node * tail;
  void (*insert)();
  Data * (*read)();
  void (*remove)();
  void (*delete)();
} List;

List * newList();

void insertList(List * list, int index, Data value);
void removeData(List * list, int index);
Data * readData(List * list, int index);
void deleteList(List *l);

#include "list.c"
#endif