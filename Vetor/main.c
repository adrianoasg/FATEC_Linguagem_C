/*
Ordena um vetor de 5 posicoes em ordem crescente digitados pelo usuario
*/

#define TAM 5
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetA[TAM];
    int i, j, aux;

    printf("Ordena vetor de 5 posicoes\n");

    for(i=0; i<5; i++){
      printf("Digite um valor: ");
      scanf("%d", &vetA[i]);
    }
    for(i=0; i<5; i++){
        for(j=i+1; j<5; j++){
        if(vetA[i]>vetA[j]){
            aux=vetA[i];
            vetA[i]=vetA[j];
            vetA[j]=aux;
        }

    }

}
printf("Ordenado com sucesso!!!\n");
for(i=0; i<5; i++){
    printf("%d\n", vetA[i]);
}
    return 0;
}
