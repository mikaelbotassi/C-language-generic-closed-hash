//
//  hashFechada.c
//  LibLista 
//
//  Created by Victorio Carvalho on 29/09/21.
//

#include "hashFechada.h"

hashFechada* criarHashFechada(int tamanho){
    int i;
    hashFechada *h = (hashFechada *)malloc(sizeof(hashFechada));
    h->tamanho = tamanho;
    h->dados = (list *) malloc(tamanho*sizeof(list));
    for(i=0;i<tamanho;i++){
        listInitialized(&h->dados[i]);
    }
    return h;
}

int hashFunction (hashFechada* h, int chave){
    return chave % h->tamanho;
}

void inserirNaHashFechada(char id, hashFechada* h, void * a, int (*returnChave)(void *, char), int (*comp)(char, node *, node *)){
    int hashCode = hashFunction(h, returnChave(a, id)); //Vai passar o elemento void e a chave para a função e a função vai retornar a chave de inserção na tabela hash
    push(id, &(h->dados[hashCode]), a, comp); //Chama a função para inserção na lista
}

void imprimirHashFechada(hashFechada* h, void (*print)(char, void *)){
    int i;
    for(i=0;i<h->tamanho;i++){
        printf("\nIndice:%d", i);
        printList(&(h->dados[i]), print);//Passa a lista do índice e juntamente passa o ponteiro para a função de printar aluno.
    }
}

void excluiHashFechada(hashFechada* h){
    int i;
    for(i=0;i<h->tamanho;i++){
        printf("\nIndice:%d", i);
        pop(&(h->dados[i]),h->dados[i].first);
    }
}

void pesquisaNaHash(hashFechada *h, int matricula, int(*cmpMatricula)(int, void *, char), void(*print)(char, void *)){
    int i;
    for(i=0;i<h->tamanho;i++){
        printf("\nIndice:%d", i);
        listSearch(&(h->dados[i]), matricula, )
    }
}