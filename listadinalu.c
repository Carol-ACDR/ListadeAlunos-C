#include " listadinalu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cria(TListaAluno *la){
  la->inicio = NULL;
  printf("Lista Criada\n");
  return;
}
int vazia(TListaAluno *la) {
  if (la->inicio == NULL) return 1;
  return 0;
}
int tamanho(TListaAluno *la){
  No*aux = la->inicio;
  int tamanho = 0;
  if (vazia(la)== 1) return 0;
  else{
  while (aux!=NULL) {
    aux= aux->prox;
    tamanho++;
    }
  }
  return tamanho;
}
int insereFinal(TListaAluno *la, TAluno al){
 if (vazia(la)== 1) {insereInicio(la, al); return 1;}
 No *novo;
 No *aux = la->inicio;
 novo = (No*)malloc( 1* sizeof (No));
 if (novo == NULL) {printf ("Memória Cheia!\n"); return -1;}
 else{
 novo->prox = NULL;
 novo->dado = al;
 while (aux->prox != NULL) aux = aux->prox;
 aux->prox = novo;
 }
 return 1;
 }
 
int removeAlunoMat(TListaAluno *la, int mat){
  No *aux = la->inicio;
  No *aux2 = NULL;
  if (vazia(la)== 1) {printf("Lista vazia\n");return -1;}
  if (aux->dado.matricula == mat){
    la->inicio = aux->prox;
    free(aux);
    return 0;
  }
  else{
  while(aux != NULL && aux->dado.matricula != mat ){
    aux2 = aux;
    aux = aux->prox;}
    if (aux == NULL) {printf("Matrícula inválida!\n"); return -1;}
    aux2->prox = aux->prox;
    free(aux);
  }
  return 1;
}
void exibirAlunos(TListaAluno *la){
  No *aux = la->inicio;
  if (vazia(la)== 1) printf("Lista Vazia\n");
  while (aux != NULL){
   printf("Matrícula: %d \n Nome: %s \n Nota 1: %.2f \n Nota 2: %.2f \n\n",aux->dado.matricula,aux->dado.nome,aux->dado.nota1,aux->dado.nota2);
   aux = aux->prox;
  }
return;
}
int buscaPosMat(TListaAluno *la, int mat, int *pos){
  No *aux = la->inicio;
  int posi = 1;
  if (vazia(la)== 1) {printf("Lista vazia\n"); return 0;}
  if (vazia(la)== 0) {
  while(aux != NULL && aux->dado.matricula != mat){
    aux = aux->prox;
    posi++;}
  if (aux == NULL) {printf("Matrícula inválida!\n");return -1;}
  *pos = posi;
  }
  return 1;
  }
int buscaAlunoPos(TListaAluno *la, int pos, TAluno *al){
  No *aux = la->inicio;
  if (vazia(la)== 1) {printf("Lista vazia!\n"); return 0;}
  if ((tamanho(la)<pos) || (1>pos)) {printf("Posição inválida!\n");return -1;}
  for (int i = 1;i < pos;i++){
    aux = aux->prox;
  }
  al->matricula = aux->dado.matricula;
  strncpy(al->nome,aux->dado.nome, 30);
  al->nota1 = aux->dado.nota1;
  al->nota2 = aux->dado.nota2;
  return 1;
  }
int insereInicio(TListaAluno *la, TAluno al){
 No *novo;
 novo = (No*)malloc( 1* sizeof (No));
 if (novo == NULL) {printf ("Memória Cheia!\n"); return -1;}
 else{
 novo->prox = la->inicio;
 novo->dado = al;
 la->inicio = novo;
 }
 return 1;
}
int inserePos(TListaAluno *la,int pos, TAluno al){
  if ((vazia(la)== 1 && pos != 1) ||(((tamanho(la)+1)<pos)|| (1>pos))) {printf("Posição inválida!\n");return -1;}
  if (pos == 1){insereInicio(la,al); return 1;}
  if(tamanho(la)+1 == pos){insereFinal(la,al);return 1;}
  else{
    No *novo;
    novo = (No*)malloc( 1* sizeof (No));
    if (novo == NULL) {printf ("Memória Cheia!\n"); return -1;}
    else{
      No * aux = la->inicio;
      No * aux2 = NULL;
       for (int i = 1;i < pos;i++){
       aux2 = aux;
       aux = aux->prox;
      }
      aux2->prox = novo;
      novo->prox = aux;
      novo->dado = al;
    }
  }
  return 1;
}
int removeAlunoPos(TListaAluno *la, int pos){
if (vazia(la)== 1) {printf("Lista vazia\n");return -1;}
if ((tamanho(la)<pos) || (1>pos)) {printf("Posição inválida!\n");return -1;}
No *aux = la->inicio;
No *aux2 = NULL;
if (pos == 1){
  la->inicio = aux->prox;
    free(aux);
    return 0;}
else{
  for (int i = 1;i < pos;i++){
       aux2 = aux;
       aux = aux->prox;
      }
      aux2->prox = aux->prox;
      free(aux);
  }
  return 0;
}
void PesquisarPor(TListaAluno *la, char Escolha,char MouN[30]){
  No *aux = la->inicio;
  if (Escolha == 'M' ||Escolha == 'm'){
    int M = 0;
    if(sscanf(MouN, "%d", &M) ==1){
    if (vazia(la)== 1) {printf("Lista vazia\n");return;}
    if (vazia(la)== 0) {
    while(aux != NULL && aux->dado.matricula != M){
    aux = aux->prox;}
    if (aux == NULL) {printf("Matrícula inválida!\n");return;}
    printf("Matricula: %d \n Nome: %s \n Nota 1: %.2f \n Nota 2: %.2f \n\n",aux->dado.matricula,aux->dado.nome,aux->dado.nota1,aux->dado.nota2);
    return;}
    }
    else {printf("Matrícula inválida!\n");return;}
  }
  if ((Escolha == 'N' ||Escolha == 'n')){
    int N = 0,T = 0;
    T = strlen(MouN);
    if (vazia(la)== 1) {printf("Lista vazia\n");return;}
    while(aux != NULL){
    if (strncmp(MouN,aux->dado.nome,T) == 0){printf("Matrícula: %d \n Nome: %s \n Nota 1: %.2f \n Nota 2: %.2f \n\n",aux->dado.matricula,aux->dado.nome,aux->dado.nota1,aux->dado.nota2); N++;}
    aux = aux->prox;
    }
    if ((aux == NULL) && (N == 0)) {printf("Nome não encontrado!\n");return;}
  }
  else{
    printf("Comando inválido.\n");
    return;
    }
}