#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

typedef struct listElementStruct{
	void* data;
	size_t size;
	struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size){
	listElement* e = malloc(sizeof(listElement));
	if (e == NULL){
		//malloc has had an error
		return NULL; //return NULL to indicate an error.
	}
	void* dataPointer = malloc(sizeof(char)*size);
	if (dataPointer == NULL){
		//malloc has had an error
		free(e); //release the previously allocated memory
		return NULL; //return NULL to indicate an error.
	}
	strcpy(dataPointer, data);
	e->data = dataPointer;
	e->size = size;
	e->next = NULL;
	return e;
}

//Prints out each element in the list
void traverse(listElement* start){
	listElement* current = start;
	while (current != NULL){
		printf("%s\n", current->data);
		current = current->next;
	}
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, size_t size){
	listElement* newEl = createEl(data, size);
	listElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
	listElement* delete = after->next;
	listElement* newNext = delete->next;
	after->next = newNext;
	//need to free the memory because we used malloc
	free(delete->data);
	free(delete);
}

void printChar(void* data){
	printf("%c\n", *(char*)data);
}


int length(listElement* list){

	listElement* current = list;
	int i = 0;

	while (current != NULL){

		i++;
		current = current->next;
	}

	return i;
}

void push(listElement** list, void* data, size_t size){

	listElement* newEl = createEl(data, size);
	newEl->next = *list;
	*list = newEl;
}

listElement* pop(listElement** list){

	listElement* newEl = *list;
	*list = (*list)->next;

	return newEl;
}

void enqueue(listElement** list, void* data, size_t size){

	listElement* newEl = createEl(data, size);
	newEl->next = *list;
	*list = newEl;
}

listElement* dequeue(listElement* list){

	listElement* cur = list;

	while (cur != NULL){

		listElement* newEl = createEl(cur->next->data, cur->next->size);
	}

	return cur;
}


