/* Banco de Dados
Simulação de um Banco de Dados com lista dinamica, lista duplamente ligada e arvore binaria
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arv_b.h"
#include "varGlobais.h"
#include "lista_d.h"
#include "lista_dl.h"

struct noAB //estrutura de um nó da arvore binária
{
    struct noAB *ab_esquerda;   //ponteiro para nó menor
    char ab_cpf[15];
    int arvb_posicao;
    struct noAB *ab_direita;    //ponteiro para nó maior
};


void inicializar_ab()
{
    ab_inicio = 0;  //inicia deixando a arvore vazia
}

void adicionar_ab(struct noAB *ab_posicao, struct noAB *ab_novo)
{
    if(ab_inicio == 0) //verifica se a arvore tem algum dado
    {
        //Adiciona no inicio
        ab_inicio = ab_novo;    //inicia a arvore

    }
    else
    {
        if(strcmp(ab_novo->ab_cpf, ab_posicao->ab_cpf) == 1)

        {
            if(ab_posicao->ab_direita == 0) //posição direita livre
            {
                ab_posicao->ab_direita = ab_novo;
            }
            else    //posição ocupada chamada recursiva para pposição direita para proxima verificação
            {
                adicionar_ab(ab_posicao->ab_direita, ab_novo);
            }
        }
        else
        {
            if(ab_posicao->ab_esquerda == 0)    //posição esquerda livre
            {
               ab_posicao->ab_esquerda = ab_novo;
            }
            else     //posição ocupada chamada recursiva para pposição esquerda para proxima verificação
            {
               adicionar_ab(ab_posicao->ab_esquerda, ab_novo);
            }
        }
    }
}

struct noAB *novo_no_ab(char *cpf, int pos)
{
    struct noAB *ab_novo;

    ab_novo = malloc(sizeof(struct noAB));  //alocando um espaçõ na memória para novo nó
    if(!ab_novo)
    {   //caso não aloque os dados
        printf("Nao consegui alocar memoria!\n");
        exit(-1);
    }
    ab_novo->ab_esquerda = 0;   //posição vazia
    strcpy(ab_novo->ab_cpf, cpf);
    ab_novo->arvb_posicao = pos;
    ab_novo->ab_direita = 0;    //posição vazia

    return ab_novo;
}

void finalizar_ab(struct noAB *ab_posicao)
{
    if(ab_posicao!=0)
    {
       if(ab_posicao->ab_esquerda != 0)
            finalizar_ab(ab_posicao->ab_esquerda);  //chamada recursiva quando a posição esquerda estiver ocupada
        if(ab_posicao->ab_direita != 0)
            finalizar_ab(ab_posicao->ab_direita);       //chamada recursiva quando a posição direita estiver ocupada

        free(ab_posicao);
    }
}

struct noAB *localizar_ab(struct noAB *posicao, char *cpf, int pos) //localiza e retorna o nó encontrado da arvore
{
    if(posicao == 0)
        return 0;   //não ha dados
    if(posicao == ab_inicio)
        ab_anterior = ab_inicio;
    if((strcmp(posicao->ab_cpf, cpf) == 0))     //o dado encontrado esta na primeira posição
        return posicao;
    else
    {
        ab_anterior = posicao;  //caso não estiver na primeira posição............
        if((strcmp(cpf, posicao->ab_cpf) == 1) && posicao->ab_direita != 0) //caminhe entre direita e esquerda por nome menor ou
        {                                                                                                      //maior ate encontrar o nome
            ultimo_movimento = 'D';                                                                 //registra que o ultimo movimento foi para direita para
            return localizar_ab(posicao->ab_direita, cpf, pos);                         //depois excluir
        }
        if((strcmp(cpf, posicao->ab_cpf) == -1) && posicao->ab_esquerda != 0)
        {                                                                                                           //mesma coisa que o comentário acima so que inverso
            ultimo_movimento = 'E';
            return localizar_ab(posicao->ab_esquerda, cpf, pos);
        }
        return 0;
    }
}

void excluir_ab(char *cpf, int pos)         //libera um nó da memória
{
    ab_aux = localizar_ab(ab_inicio, cpf, pos);     //verifica se o dado especificado existe
    if(ab_aux == 0)
        printf("Impossivel excluir, registro nao existe!\n");
    else    //se existir
    {
        if(ab_aux == ab_inicio){    //caso dado for o nó inicial

            ab_inicio = 0;  //remove o inicio da arvore
            if(ab_aux->ab_esquerda != 0)
                adicionar_ab(ab_inicio, ab_aux->ab_esquerda);   //adiciona ramificação esquerda primeiro
            if(ab_aux->ab_direita != 0)
                adicionar_ab(ab_inicio, ab_aux->ab_direita);    //depois reinsere a ramificação direita
            free(ab_aux);   //desaloca nó atual da memória
        }
        else    //caso não for o inicio da arvore
        {
            if(ultimo_movimento == 'D') //verifica ordem de movimentos para ver qual lado ira reinserir
                ab_anterior->ab_direita = 0;
            else
                ab_anterior->ab_esquerda = 0;
            if(ab_aux->ab_esquerda != 0)    //posição esquerda
                adicionar_ab(ab_inicio, ab_aux->ab_esquerda);   //adiciona ramificação esquerda
            if(ab_aux->ab_direita != 0)     //posição direita ocupada
                adicionar_ab(ab_inicio, ab_aux->ab_direita);    //adiciona ramificação direita
            free(ab_aux);   //desaloca nó atual da memória
        }
    }
}
