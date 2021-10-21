#include "aluno.h"
#include "controleArquivo.h"

/*
AVISO: A estrutura está encapsulada, somente a biblioteca de aluno tem acesso a bibloteca de Hash Fechada,
somente a bibloteca de Hash tem acesso a bibloteca de lista.
Todas as estruturas armazenam void, contudo como o bojetivo do trabalho é armazenar alunos,
eu coloquei o cast somente para aluno.
*/

int main(){
    hashFechada *h1=criarHashFechada(997);
    hashFechada *h2=criarHashFechada(1000);
    readHashAlunoFromFile(h1, h2);
    start(h1,h2);
    writeHashOnFile(h1);
    writeHashOnFile(h2);

    return 0;
}