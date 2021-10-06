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
    h->dados = (list *) malloc(tamanho * sizeof(list));
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
        if(h->dados[i].first!=NULL){
            printf("\nIndice:%d", i);
            printList(&(h->dados[i]), print);//Passa a lista do índice e juntamente passa o ponteiro para a função de printar aluno.
        }
    }
}

void excluiHashFechada(hashFechada* h){
    int i;
    for(i=0;i<h->tamanho;i++){
        printf("\nIndice:%d", i);
        pop(&(h->dados[i]),h->dados[i].first);
        free(&(h->dados[i]));
    }
}

void excluiAlunoHashFechada(hashFechada *h, int matricula, int(*cmpMatricula)(int, void *, char)){
    int indice = hashFunction(h, matricula);
    node * n = listSearch(&(h->dados[indice]), matricula, cmpMatricula);;
    pop(&(h->dados[indice]), n);
}

void pesquisaNaHash(hashFechada *h, int matricula, int(*cmpMatricula)(int, void *, char), void(*print)(char, void *)){
    int indice= hashFunction(h, matricula);
    printf("\nIndice:%d", indice);
    node * n = listSearch(&(h->dados[indice]), matricula, cmpMatricula);
    if(n==NULL){
        printf("\n ALUNO NAO ENCONTRADO! ");
    }
    else{
        print(n->id, n->elemen);
    }
}

void exibeEstatisticas(hashFechada *h1, hashFechada *h2){
    printf("\nEstas sao as estatisticas da Hash: 1");
    todasEstatisticas(h1);

    printf("\nEstas sao as estatisticas da Hash: 2");
    todasEstatisticas(h2);
}

void totalElementos(hashFechada *h){
    printf("\nO total de elementos da Hash eh: %d", h->tamanho);
}

float mediaElementosIndice(hashFechada * h){
    int i;
    int totalNos=0;
    float media;
    for(i=0; i<h->tamanho; i++){
        totalNos = totalNos + h->dados[i].tam;
    }
    media=(float)(totalNos/h->tamanho);
    return media;
}

void descobreIndiceMaiorMenor(hashFechada * h){
    int i;
    int maior=0;
    int menor = 0;
    int elementosMaior = -1;
    int elementosMenor = 99999999;
    for(i=0; i<h->tamanho; i++){
        if(h->dados[i].tam>elementosMaior){
            maior=i;
            elementosMaior=h->dados[i].tam;
        }
        if(h->dados[i].tam<elementosMenor){
            menor=i;
            elementosMenor=h->dados[i].tam;
        }
    }

    printf("\nO indice com o maior numero de elementos eh: %d, e ele possui %d elementos", maior, elementosMaior);
    printf("\nO indice com o menor numero de elementos eh: %d, e ele possui %d elementos", menor, elementosMenor);
}

float calculaDesvioPadrao(hashFechada *h){
    int i;
    float media = mediaElementosIndice(h);
    float soma = 0;
    float desvioPadrao=0;
    for(i=0; i<h->tamanho; i++){
        soma=soma + pow((h->dados[i].tam - media), 2);
    }
    desvioPadrao=soma/h->tamanho;
    return desvioPadrao;
}

int indicesNoIntervalo(hashFechada *h){
    int i;
    int quantidadeIndicesIntervalo = 0;
    for(i=0; i<h->tamanho; i++){
        if(h->dados[i].tam >= (mediaElementosIndice(h) - calculaDesvioPadrao(h)) && h->dados[i].tam <= (mediaElementosIndice(h) - calculaDesvioPadrao(h))){
            quantidadeIndicesIntervalo++;
        }
    }
    return quantidadeIndicesIntervalo;
}

void todasEstatisticas(hashFechada *h){
    totalElementos(h);
    printf("\nA media de elementos em cada indice eh: %.1f", mediaElementosIndice(h));
    descobreIndiceMaiorMenor(h);
    printf("\nO desvio padrao da hash eh: %.1f", calculaDesvioPadrao(h));
    printf("\n A quantidade de indices no intervalo eh: %d", indicesNoIntervalo(h));
}