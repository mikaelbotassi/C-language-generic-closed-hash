#include "aluno.h"
#include "controleArquivo.h"

int main(){
    hashFechada *h1=criarHashFechada(997);
    hashFechada *h2=criarHashFechada(1000);
    readHashAlunoFromFile(h1, h2);
    writeHashOnFile(h1);
    writeHashOnFile(h2);
    //start(h1,h2);
    /*printAllHash(h1);
    printAllHash(h2);*/

    return 0;
}