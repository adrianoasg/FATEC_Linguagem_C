#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5

int fila[TAMANHO];
int opcao;
int numero;
int fim;
int inicio;

void menu();
void adicionar(int numero);
int retirar();

int main()
{
    opcao = 0;
    inicio = 0;
    fim = 0;
    while(opcao != 3)
    {
        menu();
        switch(opcao)
        {
        case 1:
            printf("Digite o numero: ");
            scanf("%d",&numero);
            adicionar(numero);
            break;
        case 2:
            numero = retirar();
            if(numero != -1)
                printf("Retirado o numero %d da fila\n", numero);
            break;
        case 3:
            break;
        default:
            printf("Opcao invalida!\n");
        }
    }
    return 0;
}

void menu()
{
    printf("1 - adicionar\n");
    printf("2 - retirar\n");
    printf("3 - sair\n");
    printf("Digite a opcao: ");
    scanf("%d", &opcao);
}

void adicionar(int numero)
{
    if(fim==TAMANHO)
    {
        printf("A fila esta cheia!\n");
    }
    else
    {
        fila[fim] = numero;
        fim++;
    }
}

int retirar()
{
    int valorParaRetorno = -1;

    if(inicio == fim)
    {
        printf("Fila vazia!\n");
    }
    else
    {
        valorParaRetorno = fila[inicio];
        inicio++;
    }
    return valorParaRetorno;
}
