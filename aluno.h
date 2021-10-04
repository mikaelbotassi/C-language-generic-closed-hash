#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashFechada.h"
#ifndef _ALUNO_H
#define _ALUNO_H

typedef struct Aluno{
    int matricula;
    char nome[31];
    int nota;
}aluno;

void start(hashFechada *h);
aluno * allocAluno();
void insertAluno(hashFechada * h);
int descobreTipo(char id);
int cmp(char id, node * n1, node *n2);
void alunoSearch(hashFechada *h);
int matriculaCompare(int matricula, void * elem, char id);
void printAluno(char id, void *elem);
void printAllHash(hashFechada *h);
int returnChave(void * elem, char id);

#endif