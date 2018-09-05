#include "data.h"
#include<stdio.h>

List * newList() {
	List *l = malloc(sizeof(List));
	l-> head = l-> tail = NULL;
	l-> read = readData;
	l-> insert = insertList;
	l-> remove = removeData;
	l-> delete = deleteList;
	return l;	
}

Data * readData (List *l, int index) {
	if (l-> head == NULL) return NULL;
	Node *iter = l->head;
	int i = 0;
	while(iter->next != NULL){
		if (i == index){
			return &iter->data;
		}
		iter = iter->next;
		i++;
	}
	return NULL;
}

void insertList (List *l, int index, Data value){
	Node *n = malloc(sizeof(Node));
	n-> next = n-> prev = NULL;
	n-> data = value;
	if (l-> head == NULL){
		l-> head = l-> tail = n;
	}
	else{
		Node *iter = l-> head;
		int i = 0;
		while(iter-> next != NULL){
			if (i == (index-1)){
				n->next = iter->next;
				iter->next = n;
				n->prev = iter;
				(n->next)->prev = n;
				return;
			}
			iter = iter->next;
			i++;
		}
		iter->next = n;
		n->prev = iter;
		l-> tail = n;
		return;
	}
}

void removeData(List * l, int index)
{
	Node * iter = l->head;
 
  if (iter != NULL && iter->next == NULL && iter->prev == NULL){
		l-> head = l->tail = NULL;
		free(iter);
		return;
	} else {
  	for (int i = 1; iter != NULL && i < index; i++)
  		iter = iter->next;
  
  	if (iter == NULL)
  		return;
 
   	if (l->head == iter)
  		l->head = iter->next;
 
  	if (iter->next != NULL)
  		iter->next->prev = iter->prev;
 
  	if (iter->prev != NULL)
  		iter->prev->next = iter->next;
  
  	free(iter);
  }
  return;
}

void deleteList(List *l){
	Node *iter = l-> head;
	Node *temp = NULL;
	while (iter != NULL){
		temp = iter;
		iter = iter-> next;
		free(temp);
	}
	free(l);
}