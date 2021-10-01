#ifndef hashFechada_h
#define hashFechada_h
#include <stdio.h>
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

void pesquisaNaHash(hashFechada *h, int matricula);


#endif /* hashFechada_h */