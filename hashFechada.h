#ifndef hashFechada_h
#define hashFechada_h
#include <stdio.h>
#include <math.h>
#include "lista.h"

typedef struct HashFechada{
    list *dados;
    int tamanho;
}hashFechada;

//Aloca uma lista e a inicializa.
hashFechada* criarHashFechada(int tamanho);

int hashFunction (hashFechada* h, int chave);

void inserirNaHashFechada(char id, hashFechada* h, void * a,  int (*returnChave)(void *, char), int (*comp)(char, node *, node *));

void imprimirHashFechada(hashFechada* h, void (*print)(char, void *));

void excluiHashFechada(hashFechada* h);

void excluiAlunoHashFechada(hashFechada *h, int matricula, int(*cmpMatricula)(int, void *, char));

void pesquisaNaHash(hashFechada *h, int matricula, int(*cmpMatricula)(int, void *, char), void(*print)(char, void *));

void exibeEstatisticas(hashFechada *h1, hashFechada *h2);

void totalElementos(hashFechada *h);

float mediaElementosIndice(hashFechada * h);

void descobreIndiceMaiorMenor(hashFechada * h);

float calculaDesvioPadrao(hashFechada *h);

int indicesNoIntervalo(hashFechada *h);

void todasEstatisticas(hashFechada *h);

#endif /* hashFechada_h */