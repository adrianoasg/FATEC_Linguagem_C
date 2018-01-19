///Manipulando string, troca uma letra 'a' por uma letra 'b' em uma frase e busca letras pelo indice na frase digitada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "capturaletra.h"
#include "trocaletra.h"

void menu();

char frase[100];
int opcao = 0;

int main(){

    int posicao;

    printf("Entre com um frase -> ");
    gets(frase);

    do{
        menu();

        switch(opcao){
	        case 1:
	            trocaletra(frase);
                break;
            case 2:
                printf("\n Qual Indice vc quer buscar -> ");
                scanf("%d", &posicao);
                if (capturaletra(frase, posicao) == 0){
                        printf("\n ESSE INDICE NAO EXISTE\n\n");
                }
                else{
                        printf("\n LETRA ENCONTRADA -> %c\n", capturaletra(frase, posicao));
            }
        }
	}while (opcao != 3);

	return 0;
}


void menu(){

    printf("\n 1 - Alterar letras da frase");
    printf("\n 2- Procurar letra por indice");
    printf("\n 3 - Sair\n");
    printf("\nEscolha -> ");
    scanf("%d", &opcao);

}



