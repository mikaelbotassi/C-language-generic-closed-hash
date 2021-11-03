#ifndef hashFechada_h
#define hashFechada_h
#include <stdio.h>
#include <math.h>
#include "lista.h"

//CONSTANTES----------------------------------------

//******* PONTEIROS DE FUNÇÃO DA BIBLIOTECA ALUNO *******

#define RETURN_CHAVE int (*returnChave)(void *, char) //int returnChave(void * elem, char id)
#define CMP int (*comp)(char, node *, node *) //int cmp(char id, node * n1, node *n2)
#define PRINT_ALUNO void (*print)(char, void *) //void printAluno(char id, void *elem)
#define COMPARA_MATRICULAS_IGUAIS int(*cmpMatricula)(int, void *, char) //int matriculaCompare(int matricula, void * elem, char id)

//--------------------------------------------------

typedef struct HashFechada{
    list *dados;
    int tamanho;
}hashFechada;

//Aloca uma lista e a inicializa.
hashFechada* criarHashFechada(int tamanho);

int hashFunction (hashFechada* h, int chave);

void inserirNaHashFechada(char id, hashFechada* h, void * a,  RETURN_CHAVE, CMP);

void imprimirHashFechada(hashFechada* h, PRINT_ALUNO);

void excluiHashFechada(hashFechada* h);

void excluiAlunoHashFechada(hashFechada *h, int matricula, COMPARA_MATRICULAS_IGUAIS);

void pesquisaNaHash(hashFechada *h, int matricula, COMPARA_MATRICULAS_IGUAIS, PRINT_ALUNO);

void exibeEstatisticas(hashFechada *h1, hashFechada *h2);

void totalElementos(hashFechada *h);

float mediaElementosIndice(hashFechada * h);

void descobreIndiceMaiorMenor(hashFechada * h);

float calculaDesvioPadrao(hashFechada *h);

int indicesNoIntervalo(hashFechada *h);

void todasEstatisticas(hashFechada *h);

#endif /* hashFechada_h */