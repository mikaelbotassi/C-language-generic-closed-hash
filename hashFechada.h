#ifndef hashFechada_h
#define hashFechada_h

#include <stdio.h>
#include "lista.h"

typedef struct hashFechada{
    list *dados;
    int tamanho;
}THashFechada;

//Aloca uma lista e a inicializa.
THashFechada* criarHashFechada(int tamanho);

int hashFunction (THashFechada* h, int chave);

void inserirNaHashFechada(THashFechada* h, TAluno *a);

void imprimirHashFechada(THashFechada* h);


#endif /* hashFechada_h */