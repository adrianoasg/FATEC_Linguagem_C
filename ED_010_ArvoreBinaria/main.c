#include <stdio.h>
#include <stdlib.h>

struct no
{
    struct no *esquerda;
    int dado;
    struct no *direita;
};

struct no *inicio;
struct no *anterior;
struct no *aux;
char ultimo_movimento = ' ';

void adicionar(struct no *posicao, struct no *novo);
struct no *novo_no(int dado);
void inicializar();
void finalizar(struct no *posicao);
struct no *localizar(struct no *posicao, int dado);
void excluir(int dado);
void menu();

int opcao;
int numero;

int main()
{
    inicializar();

    while(opcao != 4)
    {
        menu();
        switch(opcao)
        {
            case 1:
                printf("Digite um numero: ");
                scanf("%d", &numero);
                adicionar(inicio, novo_no(numero));
                break;
            case 2:
                printf("Digite um numero: ");
                scanf("%d", &numero);
                excluir(numero);
                break;
            case 3:
                printf("Digite um numero: ");
                scanf("%d", &numero);
                aux = localizar(inicio, numero);
                if(aux == 0)
                    printf("Nao encontrei o dado!\n");
                else
                    printf("Encontrei %d!\n", aux->dado);
                break;
        }
    }

    finalizar(inicio);
    return 0;
}

void menu()
{
    printf("Menu\n");
    printf("1 - inserir\n");
    printf("2 - excluir\n");
    printf("3 - localizar\n");
    printf("4 - sair\n");

    printf("Digite sua opcao: ");
    scanf("%d", &opcao);
}

void inicializar()
{
    inicio = 0;
}

void adicionar(struct no *posicao, struct no *novo)
{
    if(inicio == 0)
    {
        printf("Adicionando %d no inicio!\n", novo->dado);
        inicio = novo;
    }
    else
    {
        if(novo->dado > posicao->dado)
        {
            if(posicao->direita == 0)
            {
                printf("Adicionando %d a direita de %d!\n", novo->dado, posicao->dado);
                posicao->direita = novo;
            }
            else
            {
                printf("Indo para a direita de %d!\n", posicao->dado);
                adicionar(posicao->direita, novo);
            }
        }
        else
        {
            if(posicao->esquerda == 0)
            {
                printf("Adicionando %d a esquerda de %d!\n", novo->dado, posicao->dado);
                posicao->esquerda = novo;
            }
            else
            {
                printf("Indo para a esquerda de %d!\n", posicao->dado);
                adicionar(posicao->esquerda, novo);
            }
        }
    }
}

struct no *novo_no(int dado)
{
    struct no *novo;

    novo = malloc(sizeof(struct no));
    if(!novo)
    {
        printf("Nao consegui alocar memoria!\n");
        exit(-1);
    }
    novo->esquerda = 0;
    novo->dado = dado;
    novo->direita = 0;

    return novo;
}

void finalizar(struct no *posicao)
{
    if(posicao!=0)
    {
        printf("Processando esquerda de %d\n", posicao->dado);
        if(posicao->esquerda != 0)
            finalizar(posicao->esquerda);
        printf("Processando direita de %d\n", posicao->dado);
        if(posicao->direita != 0)
            finalizar(posicao->direita);
        printf("Liberando %d\n", posicao->dado);
        free(posicao);
    }
}

struct no *localizar(struct no *posicao, int dado)
{
    if(posicao == 0)
        return 0;
    if(posicao == inicio)
        anterior = inicio;
    if(posicao->dado == dado)
        return posicao;
    else
    {
        anterior = posicao;
        if(dado > posicao->dado && posicao->direita != 0)
        {
            ultimo_movimento = 'D';
            return localizar(posicao->direita, dado);
        }
        if(dado < posicao->dado && posicao->esquerda != 0)
        {
            ultimo_movimento = 'E';
            return localizar(posicao->esquerda, dado);
        }
        return 0;
    }
}

void excluir(int dado)
{
    aux = localizar(inicio, dado);
    if(aux == 0)
        printf("Impossivel excluir, registro nao existe!\n");
    else
    {
        if(aux == inicio)
        {
            inicio = 0;
            if(aux->esquerda != 0)
                adicionar(inicio, aux->esquerda);
            if(aux->direita != 0)
                adicionar(inicio, aux->direita);
            free(aux);
        }
        else
        {
            if(ultimo_movimento == 'D')
                anterior->direita = 0;
            else
                anterior->esquerda = 0;
            if(aux->esquerda != 0)
                adicionar(inicio, aux->esquerda);
            if(aux->direita != 0)
                adicionar(inicio, aux->direita);
            free(aux);
        }
    }
}
