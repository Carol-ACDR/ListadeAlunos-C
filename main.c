#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include " listadinalu.h"

int main(void){
  TAluno A1,A2,A3,A4,A5,A6;
  TListaAluno la;
  cria(&la);
 
 //  Dados dos lunos
  strncpy(A1.nome,"Maria", 30);
  A1.matricula = 0;
  A1.nota1 = 10;
  A1.nota2 = 9.5;
  strncpy(A2.nome,"João", 30);
  A2.matricula = 1;
  A2.nota1 = 9;
  A2.nota2 = 8.5;
  strncpy(A3.nome,"Ana", 30);
  A3.matricula = 2;
  A3.nota1 = 8;
  A3.nota2 = 7.5;
  strncpy(A4.nome,"Pedro", 30);
  A4.matricula = 3;
  A4.nota1 = 7;
  A4.nota2 = 6.5;
  strncpy(A5.nome,"Maria", 30);
  A5.matricula = 4;
  A5.nota1 = 6;
  A5.nota2 = 5.5;
  strncpy(A6.nome,"Ana", 30);
  A6.matricula = 58;
  A6.nota1 = 5;
  A6.nota2 = 4.5;

  printf("-----------------------------------\n");

  if (vazia(&la) ==1) printf ("Lista Vazia.\n");
  printf("Tamanho da lista: %d\n",tamanho(&la));

  printf("-----------------------------------\n");
  //comandos de inserção 
 insereFinal(&la, A3);
 exibirAlunos(&la);
 insereFinal(&la, A5);
 exibirAlunos(&la);
 insereInicio(&la, A2);
 exibirAlunos(&la);
 inserePos(&la, 1, A1);
 exibirAlunos(&la);
 inserePos(&la, 4, A4);
 exibirAlunos(&la);
 inserePos(&la, 6, A6);
 exibirAlunos(&la);

 printf("-----------------------------------\n");

 printf ("Tamanho da lista %d\n",tamanho(&la));

 printf("-----------------------------------\n");

 //BuscaPosMat
  int pos = 0;
 if (buscaPosMat(&la, -1, &pos) == 1) printf("\nPosição %d", pos);
 if (buscaPosMat(&la, 6, &pos) == 1) printf("\nPosição %d", pos); if (buscaPosMat(&la, 5, &pos) == 1) printf("\nPosição %d", pos); 
 if (buscaPosMat(&la, 4, &pos) == 1) printf("\nPosição %d", pos); 
 if (buscaPosMat(&la, 3, &pos) == 1) printf("\nPosição %d", pos); 
 if (buscaPosMat(&la, 2, &pos) == 1) printf("\nPosição %d", pos); 
 if (buscaPosMat(&la, 1, &pos) == 1) printf("\nPosição %d", pos);
 if (buscaPosMat(&la, 0, &pos) == 1) printf("\nPosição %d\n", pos); 

printf("-----------------------------------\n");

//BuscaAlunoPos

 TAluno A7;
 if (buscaAlunoPos(&la, 0, &A7) == 1) printf("Matrícula: %d \n Nome: %s \n Nota 1: %.2f \n Nota 2: %.2f \n\n",A7.matricula,A7.nome,A7.nota1,A7.nota2);

 if (buscaAlunoPos(&la, -1, &A7) == 1) printf("Matrícula: %d \n Nome: %s \n Nota 1: %.2f \n Nota 2: %.2f \n\n",A7.matricula,A7.nome,A7.nota1,A7.nota2);

 if (buscaAlunoPos(&la, 1, &A7) == 1) printf("Matrícula: %d \n Nome: %s \n Nota 1: %.2f \n Nota 2: %.2f \n\n",A7.matricula,A7.nome,A7.nota1,A7.nota2);

 if (buscaAlunoPos(&la, 2, &A7) == 1) printf("Matrícula: %d \n Nome: %s \n Nota 1: %.2f \n Nota 2: %.2f \n\n",A7.matricula,A7.nome,A7.nota1,A7.nota2);

 if (buscaAlunoPos(&la, 3, &A7) == 1) printf("Matrícula: %d \n Nome: %s \n Nota 1: %.2f \n Nota 2: %.2f \n\n",A7.matricula,A7.nome,A7.nota1,A7.nota2);

 if (buscaAlunoPos(&la, 4, &A7) == 1) printf("Matrícula: %d \n Nome: %s \n Nota 1: %.2f \n Nota 2: %.2f \n\n",A7.matricula,A7.nome,A7.nota1,A7.nota2);

 if (buscaAlunoPos(&la, 5, &A7) == 1) printf("Matrícula: %d \n Nome: %s \n Nota 1: %.2f \n Nota 2: %.2f \n\n",A7.matricula,A7.nome,A7.nota1,A7.nota2);

 if (buscaAlunoPos(&la, 6, &A7) == 1) printf("Matrícula: %d \n Nome: %s \n Nota 1: %.2f \n Nota 2: %.2f \n\n",A7.matricula,A7.nome,A7.nota1,A7.nota2);

printf("-----------------------------------\n");

//Buscas por Matrícula ou Nome

 PesquisarPor(&la, 'm',"0");
 PesquisarPor(&la, 'M',"1");
 PesquisarPor(&la, 'm',"2");
 PesquisarPor(&la, 'M',"3");
 PesquisarPor(&la, 'm',"4");
 PesquisarPor(&la, 'M',"58");
 PesquisarPor(&la, 'm',"6");
 PesquisarPor(&la, 'n',"Ana");
 PesquisarPor(&la, 'N',"João");
 PesquisarPor(&la, 'n',"Maria");
 PesquisarPor(&la, 'N',"Pedro");
 PesquisarPor(&la, 'n',"Lorenzo");
 PesquisarPor(&la, 's',"5");
 PesquisarPor(&la, 'm',"A");

printf("-----------------------------------\n");

 removeAlunoMat(&la, 0);
 exibirAlunos(&la);
 removeAlunoMat(&la, 3000);
 exibirAlunos(&la);
 removeAlunoPos(&la, 1);
 exibirAlunos(&la);
 removeAlunoPos(&la, 5);
 exibirAlunos(&la);
 removeAlunoPos(&la, 4);
 exibirAlunos(&la);
 removeAlunoPos(&la, 2);
 exibirAlunos(&la);
 removeAlunoMat(&la, 2);
 exibirAlunos(&la);
 removeAlunoMat(&la, 4);
 exibirAlunos(&la);
  return 0;
}
