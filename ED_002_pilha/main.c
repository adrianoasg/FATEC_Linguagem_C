#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5

void menu();
void imprimir();

void push(int dado);
int pop();

int pilha[TAMANHO];
int posicao = 0;
int opcao;
int numero;

int main()
{
    opcao = 0;
    while(opcao!=3)
    {
        menu();
        if(opcao == 1)
        {
            printf("Digite o numero: ");
            scanf("%d", &numero);
            push(numero);
            imprimir();
        }
        if(opcao == 2)
        {
            numero = pop();
            if(numero != -1)
            {
                printf("Retirado %d da pilha.\n", numero);
                imprimir();
            }
        }
    }
    return 0;
}

void menu()
{
    printf("1 - push\n");
    printf("2 - pop\n");
    printf("3 - sair\n");
    printf("Digite a opcao: ");
    scanf("%d", &opcao);
}

void imprimir()
{
    int i;
    for(i = posicao - 1; i >=0; i--)
    {
        printf("+---+----+\n");
        printf("| %d | %2d |\n", i, pilha[i]);
    }
    if(posicao > 0)
        printf("+---+----+\n");
}

void push(int dado)
{
    if(posicao == TAMANHO)
        printf("Estouro de pilha!\n");
    else
    {
        pilha[posicao] = dado;
        posicao++;
    }
}

int pop()
{
    if(posicao == 0)
    {
        printf("Pilha vazia!!!\n");
        return -1;
    }
    posicao--;
    return pilha[posicao];
}
