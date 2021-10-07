

Trabalho Feito por Mikael Botassi de Oliveira do curso S.I do IFES Campus Colatina
A fins de testes:
O caminho para pegar o arquivo de entrada é uma pasta "entrada/entrada.txt"
O caminho de saída é "saida".






TRABALHO:

Objetivos:

Implementar bibliotecas de hash fechada;
Praticar o reuso de bibliotecas;
Avaliar a complexidade dos algoritmos de busca em hash, bem como a distribuição das chaves pelos índices da hash
Especificações do programa

1. Arquivos de entrada

Seu programa deverá receber como entrada um arquivo texto com o seguinte formato:

A primeira linha terá apenas um número inteiro que indicará a quantidade de registros de aluno que há no arquivo;
Da segunda linha em diante, cada linha trará a matrícula, o nome e a nota de um aluno, nesta ordem, separado por ponto-e-vírgula(;)
Estão disponíveis no ava exemplos desses arquivos.
2. Biblioteca de Hash

Sua biblioteca deve ter os seguintes métodos:

um método de iniciar a hash que receba como parâmetro o tamanho desejado para a hash e a aloque dinamicamente de acordo com o parâmetro passado.

inserir um aluno na estrutura;

consultar aluno por matrícula (dada a matrícula retorne o aluno caso ele exista)

excluir aluno por matrícula (dada a matrícula exclua o aluno caso ele exista)

exibir estatísticas: quantidade total de elementos e quantidade média de elementos por índice, índice com a maior quantidade de elementos e a quantidade de elementos desse índice, índice com a menor quantidade de elementos e a quantidade de elementos desse índice, desvio padrão da quantidade de elementos pelos índices, quantos índices tem quantidade dentro do intervalo da média +/- o desvio padrão. 
3. Leitura do arquivo e geração das tabelas hash em memória

Seu programa deve ler o arquivo, gerando, em memória, duas hashs fechadas: uma com 997 índices e outra com 1000 índices.

4. Execução do programa

Após a leitura e construção das tabelas hash em memória seu programa deve exibir um menu dando as seguintes opções:

Exibir estatísticas – Deve exibir as estatísticas da hash (chamada ao método de estatísticas da bibloteca) 
Efetuar busca por matrícula: o programa solicitará a matrícula, buscará o aluno em cada uma das hashs e imprimirá na tela os dados do aluno (se encontrado) e a quantidade de elementos que foram comparados em cada hash.  
Excluir por matrícula: o programa solicitará uma matrícula e excluíra o aluno das duas hashs, imprimindo na tela os dados do aluno excluído ou uma mensagem falando que não o encontrou.
Incluir aluno: o programa solicitará matrícula, nome e nota do aluno e o incluirá nas duas tabelas hash.
Sair: o programa gera dois arquivos, um para cada hash. Cada linha dos arquivos arquivo deve ter o índice no qual o aluno está armazenado, seguidos pela matrícula, nome e nota, sempre separados por ;. Por exemplo, suponha que no índice 0 está armazenado o João que tem matricula 12334 e nota 65 e no índice 1 está José que tem matrícula 454151 e nota 72. Nesse caso a primeira linha do arquivo seria 0; 12334;João;65 e a segunda linha 1; 454151;José;72. Note que para as hash fechadas teremos vários elementos no mesmo índice.