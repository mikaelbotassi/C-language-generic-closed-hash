#include "aluno.h"

void start(hashFechada *h1, hashFechada *h2){
    int res=5;
    while(res !=4){
        printf("\n 1 - EXIBIR ESTATISTICAS;");
        printf("\n 2 - EFETUAR BUSCA POR MATRÍCULA;");
        printf("\n 3 - INCLUIR ALUNO;");
        printf("\n 4 - SAIR");

        printf("Digite o numero correspondente a funcao que deseja utilizar: ");
        scanf(" %d", &res);
        
        if(res==1){
            exibeEstatisticas(h1, h2);
        }
        if(res==2){
            printf("\nProcurando aluno na Hash de tamanho '%d'...", h1->tamanho);
            alunoSearch(h1);
            printf("\nProcurando aluno na Hash de tamanho '%d'...", h2->tamanho);
            alunoSearch(h2);
        }

        if(res==3){
            printf("\nIncluindo aluno na Hash de tamanho '%d'...", h1->tamanho);
            newAluno(h1);
            printf("\nIncluindo aluno na Hash de tamanho '%d'...", h2->tamanho);
            newAluno(h2);
        }
    }
}

aluno * allocAluno(){
    aluno * p=(aluno *)malloc(sizeof(aluno));
    p->matricula=0;
    p->nota=0;
    strcpy(p->nome, "\0");
    return p;
}

void newAluno(hashFechada * h){
    aluno * p = allocAluno();
    printf("\nDigite a matricula do aluno: ");
    scanf("%d", &p->matricula);
    printf("Digite o nome do aluno: ");
    scanf(" %31[^\n]", &p->nome);
    printf("Digite a nota do aluno: ");
    scanf("%d", &p->nota);
    insertAluno(h, p);
}

void insertAluno(hashFechada *h, aluno * a){
    inserirNaHashFechada('A', h, a, returnChave, cmp);
}

int descobreTipo(char id){
    if(id=='A' || id=='a'){
        return 1;
    }
    else{
        return 0;
    }
}

int cmp(char id, node * n1, node *n2){
    if(descobreTipo(id)){
        if(n2!=NULL){
            aluno *p1=n1->elemen;
            aluno *p2=n2->elemen;
            if(p1->matricula>p2->matricula){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
    else{
        printf("Insira outras verificações dos tipos de varáveis possíveis! ");
        return -1;
    }
}

void alunoSearch(hashFechada *h){
    int age;
    printf("\nQual a matricula da pessoa que voce quer procurar? ");
    scanf("%d", &age);
    pesquisaNaHash(h, age, matriculaCompare, printAluno);
}

int matriculaCompare(int matricula, void * elem, char id){
    if(descobreTipo(id)){
        aluno *p=elem;
        if(p->matricula==matricula){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        printf("\nDigite outras sentenças aqui!");
        return 0;
    }
}

void printAluno(char id, void *elem){
    if(descobreTipo(id)){
        aluno *p = elem;
        printf("\nMatricula: %d", p->matricula);
        printf("\nNome: %s", p->nome);
        printf("\nNota: %d", p->nota);
        printf("\n");

    }
    else{
        printf("\nDigite mais sentenças! ");
    }
}

void printAllHash(hashFechada *h){
    if(h->tamanho==0){
        printf("Hash vazia!\n");
    }
    else{
        imprimirHashFechada(h, printAluno);
    }
}

int returnChave(void * elem, char id){
    if(descobreTipo(id)){
        aluno * a = elem;
        return a->matricula;
    }
    else{
        printf("\nDigite mais setenças de tipos de chaves! \n");
        return 0;
    }
}