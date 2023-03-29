// Definição da estrutura Aluno
typedef struct aluno{
 int matricula;
 char nome[30];
 float nota1, nota2;
} TAluno;

// Definição da estrutura Nó da fila
typedef struct no{
 TAluno dado;
 struct no *prox;
}No;

// Definição da estrutura Início da fila
typedef struct lista{
 No *inicio;
}TListaAluno;


void cria(TListaAluno *la); // Cria a lista vazia

int tamanho(TListaAluno *la); // Retorna o tamanho da lista

int vazia(TListaAluno *la); // Retorna se a lista está vazia (Retorna 1 caso a lista esteja vazia, 0 caso não esteja)

int buscaPosMat(TListaAluno *la, int mat, int *pos); // Pesquisa posição pela matrícula (Retorna 0 se a lista estiver vazia, -1 se a matrícula for inválida, 1 caso tudo ocorra corretamente.)

int buscaAlunoPos(TListaAluno *la, int pos, TAluno *al); // Pesquisa aluno pela pela posição (Retorna 0 se a lista estiver vazia, -1 se a posição for inválida, 1 caso tudo ocorra corretamente.)

int insereFinal(TListaAluno *la, TAluno al); // Insere aluno no final da lista

int removeAlunoMat(TListaAluno *la, int mat); // Remove aluno da lista passando a matricula

void exibirAlunos(TListaAluno *la); // Exibe a Lista de alunos

int insereInicio(TListaAluno *la, TAluno al); //Insere aluno no início da lista

int inserePos(TListaAluno *la,int pos, TAluno al); //Insere aluno da lista passando uma posição.

int removeAlunoPos(TListaAluno *la, int pos);//Remove aluno da lista passando uma posição.

void PesquisarPor(TListaAluno *la, char C,char MouN[30]); //Busca por Nome ou Matrícula, 'N' ou 'n' para busca por nome,'M' ou 'm' para busca por matrícula. (Obs: colocar número da matrícula ou nome como string, por exemplo: "1". )