#include <stdio.h>
#include "varGlobais.h"
#include "menu.h"


void menu() //IMPRESSÃO DO MENU
{
    system("cls");
    printf("---------------------Menu Principal--------------------\n");
    printf("\n");
    printf("1 - inserir\n");
    printf("2 - Buscar\n");
    printf("3 - excluir\n");
    printf("4 - listar\n");
    printf("5 - listar invertido\n");
    printf("6 - sair\n");
    printf("\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opcao);

}

int decidir(char opcao)
{
    int valor;

   if(opcao == 'S' || opcao == 's')
        valor = 1;
        gl_sair = 1;
    if(opcao == 'N' || opcao == 'n')
        valor = 0;
        gl_sair = 1;

    return valor;
}
