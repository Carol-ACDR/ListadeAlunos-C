#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
 int matricula;
 char nome[30];
 float nota1, nota2;
} TAluno;

typedef struct no{
 TAluno dado;
 struct no *prox;
}No;
typedef struct lista{
 No *inicio;
}TListaAluno;

void cria(TListaAluno *la); // Cria a lista vazia
int tamanho(TListaAluno *la); // Retorna o tamanho da lista
int vazia(TListaAluno *la); // Retorna se a lista está vazia
int buscaPosMat(TListaAluno *la, int mat, int *pos); // Pesquisa posição pela matricula
int buscaAlunoPos(TListaAluno *la, int pos, TAluno *al); // Pesquisa aluno pela pela posição
int insereFinal(TListaAluno *la, TAluno al); // Insere aluno no final da lista
int removeAlunoMat(TListaAluno *la, int mat); // Remove aluno da lista passando a matricula
void exibirAlunos(TListaAluno *la); // Exibe a Lista de alunos
void clear(void);//Limpar buffer


int main(){
  TListaAluno la;
  TAluno al;
  int pos = 0,mat = 0,busca= 0;
  cria(&la);
  if (vazia(&la)) printf("Lista vazia\n");
  insereFinal(&la,al);
  printf("Tamanho da lista: %d\n",tamanho(&la));
  printf("Matricula: \t");
  scanf("%d",&mat);
  busca = buscaPosMat(&la,mat, &pos);
  if ( busca == 1) printf("posição: %d\t",pos);
  else{if(busca == 0) printf("Lista Vazia!");else{printf("Matricula inválida");}}
  free(la.inicio);
  return 0;
}


void cria(TListaAluno *la){
  la->inicio = NULL;
}
int vazia(TListaAluno *la) {
  if (la->inicio == NULL) return 1;
  return 0;
}
int tamanho(TListaAluno *la){
  No*aux = la->inicio;
  int tamanho = 0;
  if (vazia(la)== 1) return 0;
  while (aux!=NULL) {
    aux= aux->prox;
    tamanho++;}
  return tamanho;
}
int insereFinal(TListaAluno *la, TAluno al){
 No *novo;
 No *aux = la->inicio;
 novo = (No*)malloc( 1* sizeof (No));
 novo->prox = NULL;
 novo->dado = al;
 printf("Matricula:\t");
 scanf("%d",&novo->dado.matricula);
 printf("Nome:\t");
 clear();
 scanf("%29[^\n]", novo->dado.nome);
 printf("Nota 1:\t");
 scanf("%f",&novo->dado.nota1);
 printf("Nota 2:\t");
 scanf("%f",&novo->dado.nota2);
 if (vazia(la)== 1) la->inicio = novo;
 else{
  while (aux != NULL) aux = aux->prox;
  aux->prox = novo;
  }
 return 1;
}
int buscaPosMat(TListaAluno *la, int mat, int *pos){
  No *aux = la->inicio;
  if (vazia(la)== 1)  return 0;
  *pos = 1;
  while(aux->dado.matricula != mat &&  aux != NULL){
    aux = aux->prox;
    *pos++;
    }
  if (aux == NULL) return -1;
  return 1;
  }
int buscaAlunoPos(TListaAluno *la, int pos, TAluno *al){
  No *aux = la->inicio;
  if (vazia(la)== 1) return 0;
  if (tamanho(la)<pos) return -1;
  for (int i = 1;pos;i++){
    aux = aux->prox;
  }
  al = &aux->dado;
  return 1;
  }
int removeAlunoMat(TListaAluno *la, int mat){
  No *aux = la->inicio;
  int x = 1;
  int *pos = &x;
  if (buscaPosMat(la,mat,pos) > 0){
    if (x == 1){
      la->inicio = aux->prox;
      free(aux);
    }
    for(int i = 2;i == x;i++) aux = aux->prox;
    No *aux2 = aux->prox;
    aux = aux->prox->prox;
    free(aux2);
    return 1;}
  else{
  if(x == 0) return 0;
  return -1;
  }
}
void exibirAlunos(TListaAluno *la){
  No *aux = la->inicio;
  if (vazia(la)== 1) printf("Lista Vazia");
  while (aux != NULL){
   printf("Matricula: %d \n Nome: %s \n Nota 1 %f: \n Nota 2 : %f \n\n",aux->dado.matricula,aux->dado.nome,aux->dado.nota1,aux->dado.nota2);
   aux = aux->prox;
  }

}
void clear(void){
  int c;
  while ((c = getchar()) != '\n') {}
}