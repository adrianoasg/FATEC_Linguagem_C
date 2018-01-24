#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5

int fila[TAMANHO];
int opcao;
int numero;
int fim;
int inicio;
int vazia = 1;

void menu();
void adicionar(int numero);
int retirar();
void imprimir();

int main()
{
    opcao = 0;
    inicio = 0;
    fim = 0;
    while(opcao != 4)
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
            imprimir();
        case 4:
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
    printf("3 - imprimir\n");
    printf("4 - sair\n");
    printf("Digite a opcao: ");
    scanf("%d", &opcao);
}

void adicionar(int numero)
{
    if(vazia==1)
    {
        fila[fim] = numero;
        fim++;
        if(fim == TAMANHO)
            fim = 0;
        vazia = 0;
    }
    else
    {
        if(inicio == fim)
        {
            printf("Fila cheia!\n");
        }
        else
        {
            fila[fim] = numero;
            fim++;
            if(fim == TAMANHO)
                fim = 0;
        }
    }
}

int retirar()
{
    int valorParaRetornar = -1;

    if(vazia == 1)
    {
        printf("Fila vazia!\n");
    }
    else
    {
        valorParaRetornar = fila[inicio];
        inicio++;
        if(inicio == TAMANHO)
            inicio = 0;
        if(inicio == fim)
            vazia = 1;
    }

    return valorParaRetornar;
}

void imprimir()
{
    int i;
    int a = 0;
    i = inicio;
    if(vazia == 0)
    {
        while(a==0)
        {
            printf("%d - ",fila[i]);
            i++;
            if(i==TAMANHO)
                i=0;
            if(i==fim)
                a=1;
        }
        printf("\n");
    }
}
