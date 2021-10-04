#include "aluno.h"

void start(hashFechada *h){
    char res='s';
    while(res =='s'){
        insertAluno(h);
        printf("Deseja Inserir mais um aluno?Digite 's' para sim e 'n' para nao: ");
        scanf(" %c", &res);
    }
}

aluno * allocAluno(){
    aluno * p=(aluno *)malloc(sizeof(aluno));
    p->matricula=0;
    p->nota=0;
    strcpy(p->nome, "\0");
    return p;
}

void insertAluno(hashFechada *h){
    aluno * p = allocAluno();
    printf("\nDigite a matricula do aluno: ");
    scanf("%d", &p->matricula);
    printf("Digite o nome do aluno: ");
    scanf(" %31[^\n]", &p->nome);
    printf("Digite a nota do aluno: ");
    scanf("%d", &p->nota);
    inserirNaHashFechada('A', h, p, returnChave, cmp);
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