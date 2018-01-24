#include <stdio.h>
#include <stdlib.h>

struct no
{
    struct no *anterior;
    int dado;
    struct no *proximo;
};

struct no *inicio;
struct no *novo;
struct no *aux;
struct no *anterior;

void inicializar();
void finalizar();
void finalizar_elemento(struct no *elemento);
void adicionar_no(int dado);
void adicionar_no_final();
void adicionar_no_inicio();
void adicionar_no_meio();
void excluir_no(int dado);
void excluir_no_inicio();
void excluir_no_final();
void excluir_no_meio();
void listar();
void listar_invertido();
struct no *novo_no(int dado);
void menu();

int opcao = 0;
int numero = 0;

int main()
{
    inicializar();

    while(opcao != 5)
    {
        menu();
        switch(opcao)
        {
            case 1:
                printf("Digite um numero: ");
                scanf("%d", &numero);
                adicionar_no(numero);
                break;
            case 2:
                printf("Digite um numero: ");
                scanf("%d", &numero);
                excluir_no(numero);
                break;
            case 3:
                listar();
                break;
            case 4:
                listar_invertido();
                break;
        }
    }

    finalizar();
    return 0;
}

void menu()
{
    printf("Menu\n");
    printf("1 - inserir\n");
    printf("2 - excluir\n");
    printf("3 - listar\n");
    printf("4 - listar invertido\n");
    printf("5 - sair\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opcao);
}

void inicializar()
{
    inicio = 0;
}

struct no *novo_no(int dado)
{
    struct no *n;
    n = malloc(sizeof(struct no));
    if(!n)
    {
        printf("Nao consegui alocar memoria!\n");
        exit(-1);
    }

    n->anterior = 0;
    n->dado = dado;
    n->proximo = 0;

    return n;
}

void adicionar_no(int dado)
{
    novo = novo_no(dado);

    if(inicio == 0)
    {
        inicio = novo;
    }
    else
    {
        // decidir aonde inserir
        if(inicio->dado > dado)
            adicionar_no_inicio();
        else
        {
            aux = inicio;
            while(aux->proximo != 0
                  && aux->dado <= dado)
            {
                aux = aux->proximo;
            }
            if(aux->proximo == 0 && dado >= aux->dado)
                adicionar_no_final();
            else
                adicionar_no_meio();
        }
    }
}

void adicionar_no_final()
{
    aux->proximo = novo;
    novo->anterior = aux;
}

void adicionar_no_inicio()
{
    novo->proximo = inicio;
    inicio->anterior = novo;
    inicio = novo;
}

void adicionar_no_meio()
{
    anterior = aux->anterior;
    novo->proximo = aux;
    anterior->proximo = novo;
    aux->anterior = novo;
    novo->anterior = anterior;
}

void excluir_no(int dado)
{
    if(inicio == 0)
    {
        printf("Impossivel excluir! Lista vazia!\n");
    }
    else
    {
        // decidir aonde excluir
        if(inicio->dado == dado)
            excluir_no_inicio();
        else
        {
            aux = inicio;
            while(aux->proximo != 0 &&
                  aux->dado != dado)
            {
                aux = aux->proximo;
            }
            if(aux->dado == dado)
                if(aux->proximo == 0)
                    excluir_no_final();
                else
                    excluir_no_meio();
            else
                printf("Impossivel excluir! Nao encontrei o elemento.\n");
        }
    }
}

void excluir_no_final()
{
    anterior = aux->anterior;
    anterior->proximo = 0;
    free(aux);
}

void excluir_no_inicio()
{
    aux = inicio;
    if(inicio->proximo != 0)
    {
        inicio = inicio->proximo;
        inicio->anterior = 0;
        free(aux);
    }
    else
    {
        free(aux);
        inicio = 0;
    }
}

void excluir_no_meio()
{
    struct no *proximo;
    anterior = aux->anterior;
    proximo = aux->proximo;
    anterior->proximo = proximo;
    proximo->anterior = anterior;
    free(aux);
}

void finalizar()
{
    if(inicio != 0)
    {
        finalizar_elemento(inicio);
        inicio = 0;
    }
}

void finalizar_elemento(struct no *elemento)
{
    if(elemento->proximo != 0)
        finalizar_elemento(elemento->proximo);
    free(elemento);
}

void listar()
{
    if(inicio != 0)
    {
        aux = inicio;
        while(aux->proximo != 0)
        {
            printf("%d -> ", aux->dado);
            aux = aux->proximo;
        }
        printf("%d\n", aux->dado);
    }
    else
        printf("Lista vazia!\n");
}

void listar_invertido()
{
    if(inicio != 0)
    {
        aux = inicio;
        while(aux->proximo != 0)
        {
            aux = aux->proximo;
        }
        while(aux->anterior != 0)
        {
            printf("%d -> ", aux->dado);
            aux = aux->anterior;
        }
        printf("%d\n", aux->dado);
    }
    else
        printf("Lista vazia!\n");
}
