/*
Matriz de inteiros 5x4 recebe e mostra o RA, notas e a media de 5 alunos
*/

#define DIML 5
#define DIMC 4
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int aluno[DIML][DIMC];
    int i, j;

    printf("Recebe e mostra o RA, notas e a media de 5 alunos\n");
    for(i=0; i<DIML; i++){
        for(j=0; j<DIMC-3; j++){
       printf("Digite o RA do Aluno: \n");
        scanf("%d", &aluno[i][j]);
     }
    for(j=1; j<DIMC-2; j++){
        printf("Digite a nota 1 do Aluno: \n");
        scanf("%d", &aluno[i][j]);
        }
    for(j=2; j<DIMC-1; j++){
        printf("Digite a nota 2 do Aluno: \n");
        scanf("%d", &aluno[i][j]);
     }
}

for(i=0; i<DIML; i++){
   aluno[i][3]=(aluno[i][1]+aluno[i][2])/2;
}

for(i=0; i<DIML; i++){

        printf("RA: %d | Nota 1: %d | Nota 2: %d| Media: %d\n", aluno[i][0], aluno[i][1], aluno[i][2], aluno[i][3]);

        }

    return 0;
}
