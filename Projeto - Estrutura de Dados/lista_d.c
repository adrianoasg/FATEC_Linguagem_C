#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "varGlobais.h"
#include "lista_d.h"
#include "lista_dl.h"
#include "arv_b.h"

struct noLD{    //estrutura de um nó
    char ld_cpf[15];
    char ld_nome[50];
    char ld_tel[20];
};

void inicializar_ld()
{
    lista_d = malloc(ld_tamanho * sizeof(struct noLD)); //inicia com alocação de memória para lista
    if(!lista_d)
    {
        printf("Erro de alocacao!");
        exit(-1);
    }
}

void finalizar_ld()
{
    free(lista_d);  //desaloca a lista da memória
}

void adicionar_ld(char *cpf, char *nome, char *tel)
{
    if(gl_posicao == ld_tamanho)    //necessita de expansão
    {
        expandir_ld();      //expande lista
        adicionar_ld(cpf, nome, tel);   //tenta adicionarnovamente
    }
    else
    {

        strcpy(lista_d[gl_posicao].ld_cpf, cpf);
        strcpy(lista_d[gl_posicao].ld_nome, nome);
        strcpy(lista_d[gl_posicao].ld_tel, tel);
        gl_posicao++;
    }
}

void expandir_ld()
{
    //printf("Expandindo o array...\n");
    struct noLD *lista_d2;  //nova lista com tamanho novopara os dados

    int novoTamanho = ld_tamanho + (ld_tamanho / 2);    //aumenta tamanho da lista em 50%
    int i;

    lista_d2 = malloc(novoTamanho * sizeof(struct noLD));   //aloca memória na lista nova com novo tamanho
    if(!lista_d2)
    {
        printf("Erro na alocacao de memoria!");
        exit(-1);
    }

    for(i = 0; i < ld_tamanho; i++) //copiando todos os dados da lista antiga paralista nova
        lista_d2[i] = lista_d[i];

    free(lista_d);  //liberando memória alocada da lista antiga
    lista_d = lista_d2; //redirecionando ponteiro para nova lista
    ld_tamanho = novoTamanho;   //atualizando tamanho golbal da lista
}
