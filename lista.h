#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _LISTA_H
#define _LISTA_H

typedef struct Node{
    struct Node * prox;
    void * elemen;
    char id;
}node;

typedef struct List{
    node *first;
    node *last;
    int tam;
}list;

list * createList();
void listInitialized(list *l);
node * nodeInitialized();
void push(char id,list * l, void * elem, int(*comp)(char, node *, node *));
node * listSearch(list * l, int age, int(*cmpMatricula)(int, void *, char));
void insereNoInicio(list *l, void *a);
void pop(list *l, node * n);
void freeList(list *l);
void printList(list *l, void(*print)(char, void *));

#endif