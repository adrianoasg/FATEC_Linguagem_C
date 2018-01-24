#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "varGlobais.h"
#include "lista_d.h"
#include "lista_dl.h"
#include "arv_b.h"

struct noLDL
{
    struct noLDL *ldl_anterior;
    char ldl_nome[50];
    int ldl_posicao;
    struct noLDL *ldl_proximo;
};


void inicializar_ldl()
{
    ldl_inicio = 0;
}

struct noLDL *novo_no_ldl(char *nome, int posicao)  //aloca um novo nó paralista duplamente ligada
{
    struct noLDL *n;
    n = malloc(sizeof(struct noLDL));   //aloca uma posição para ser ligada com os outros nos
    if(!n)
    {
        printf("Nao consegui alocar memoria!\n");
        exit(-1);
    }

    n->ldl_anterior = 0;
    strcpy(n->ldl_nome, nome);
    n->ldl_posicao = posicao;
    n->ldl_proximo = 0;

    return n;
}

void adicionar_no_ldl(char *nome, int pos)
{
    ldl_novo = novo_no_ldl(nome, pos);

    if(ldl_inicio == 0) //lista esta vazia
    {
        ldl_inicio = ldl_novo;  //defini o nó como inicio
    }
    else
    {
        // decidir aonde inserir
        if((strcmp(ldl_inicio->ldl_nome, nome) == 1)) //caso dado esteja no nó inicial
            adicionar_no_inicio_ldl();
        else    //caso não seja nó inicial
        {
            ldl_aux = ldl_inicio;   //define busca a partir do inicio
            while((ldl_aux->ldl_proximo != 0)   //faça enquanto nome for alfabeticamente menor ao especificado
                  && ((strcmp(ldl_aux->ldl_nome, nome) == -1) || (strcmp(ldl_aux->ldl_nome, nome) == 0)))
            {
                ldl_aux = ldl_aux->ldl_proximo;
            }//dado encontrado ou nao encontrado
            if((ldl_aux->ldl_proximo == 0) && ((strcmp(nome, ldl_aux->ldl_nome) == 1) || (strcmp(nome, ldl_aux->ldl_nome) == 0)))
                adicionar_no_final_ldl();   //dado encontrado na ultima posição
            else
                adicionar_no_meio_ldl();    //dado encontrado na penultima ou em posição central
        }
    }
}

void adicionar_no_final_ldl()   //caso fim
{
    ldl_aux->ldl_proximo = ldl_novo;
    ldl_novo->ldl_anterior = ldl_aux;
}

void adicionar_no_inicio_ldl()  //caso inicio
{
    ldl_novo->ldl_proximo = ldl_inicio;
    ldl_inicio->ldl_anterior = ldl_novo;
    ldl_inicio = ldl_novo;
}

void adicionar_no_meio_ldl()    //caso meio
{
    ldl_anterior = ldl_aux->ldl_anterior;
    ldl_novo->ldl_proximo = ldl_aux;
    ldl_anterior->ldl_proximo = ldl_novo;
    ldl_aux->ldl_anterior = ldl_novo;
    ldl_novo->ldl_anterior = ldl_anterior;
}

void excluir_no_ldl(char *cpf, int posicao)
{
    if(ldl_inicio == 0)
    {
        printf("Impossivel excluir! Nenhum registro cadastrado!\n");
    }

        else{
                   // decidir aonde excluir
          if((ldl_inicio->ldl_posicao == posicao) && strcmp(lista_d[ldl_inicio->ldl_posicao].ld_cpf, cpf) == 0) //se o dado encontrado estiver no nó inicial
                excluir_no_inicio_ldl();
           else
                { //senão procure a partir do inicio
            ldl_aux = ldl_inicio;
            while(ldl_aux->ldl_proximo != 0 &&  //percorra a lista a partir do inicio ate encontrar o nome
                  ldl_aux->ldl_posicao != posicao)
            {
                ldl_aux = ldl_aux->ldl_proximo;
            }
            if((ldl_aux->ldl_posicao == posicao && strcmp(lista_d[ldl_aux->ldl_posicao].ld_cpf, cpf) == 0)) //dado encontrado ou não encontrado
                if(ldl_aux->ldl_proximo == 0)
                    excluir_no_final_ldl();     //se o dado estiver no final exclui
                else
                    excluir_no_meio_ldl();  //se o dado estiver no meio exclui
            else
                printf("Impossivel excluir! Nao encontrei o CPF.\n");   //dado não encontrado
        }
    }
}

void excluir_no_final_ldl() //caso fim
{
    ldl_anterior = ldl_aux->ldl_anterior;
    ldl_anterior->ldl_proximo = 0;
    free(ldl_aux);
}

void excluir_no_inicio_ldl()    //caso inicio
{
    ldl_aux = ldl_inicio;
    if(ldl_inicio->ldl_proximo != 0)
    {
        ldl_inicio = ldl_inicio->ldl_proximo;
        ldl_inicio->ldl_anterior = 0;
        free(ldl_aux);
    }
    else
    {
        free(ldl_aux);
        ldl_inicio = 0;
    }
}

void excluir_no_meio_ldl()  //caso meio
{
    struct noLDL *proximo;
    ldl_anterior = ldl_aux->ldl_anterior;
    proximo = ldl_aux->ldl_proximo;
    ldl_anterior->ldl_proximo = proximo;
    proximo->ldl_anterior = ldl_anterior;
    free(ldl_aux);
}

void finalizar_ldl()
{
    if(ldl_inicio != 0)     //a partir do inicio libera elemento por elemento da memória
    {
        finalizar_elemento_ldl(ldl_inicio);
        ldl_inicio = 0;
    }
}

void finalizar_elemento_ldl(struct noLDL *ldl_elemento) //finaliza um nó da lista
{
    if(ldl_elemento->ldl_proximo != 0)
        finalizar_elemento_ldl(ldl_elemento->ldl_proximo);
    free(ldl_elemento);
}


void listar_ldl()
{
    if(ldl_inicio != 0)
    {
        ldl_aux = ldl_inicio;
        while(ldl_aux->ldl_proximo != 0)    //percorre a lista duplamente a partir do inicio ate o fim imprimindo
        {
            printf("CPF-> %s\n", lista_d[ldl_aux->ldl_posicao].ld_cpf);
            printf("Nome-> %s\n", ldl_aux->ldl_nome);
            printf("Telefone-> %s\n", lista_d[ldl_aux->ldl_posicao].ld_tel);
            printf("\n");
            ldl_aux = ldl_aux->ldl_proximo;
        }
            printf("CPF-> %s\n", lista_d[ldl_aux->ldl_posicao].ld_cpf);
            printf("Nome-> %s\n", ldl_aux->ldl_nome);
            printf("Telefone-> %s\n", lista_d[ldl_aux->ldl_posicao].ld_tel);
            printf("\n");
    }
    else
         printf("\nNao existe cadastros!!!\n");
}

void listar_invertido_ldl()
{
    if(ldl_inicio != 0)
    {
        ldl_aux = ldl_inicio;
        while(ldl_aux->ldl_proximo != 0)
        {
            ldl_aux = ldl_aux->ldl_proximo;
        }
        while(ldl_aux->ldl_anterior != 0) //percorre a lista duplamente a partir do fim ate o inicio imprimindo
        {
            printf("CPF-> %s\n", lista_d[ldl_aux->ldl_posicao].ld_cpf);
            printf("Nome-> %s\n", ldl_aux->ldl_nome);
            printf("Telefone-> %s\n", lista_d[ldl_aux->ldl_posicao].ld_tel);
            printf("\n");
            ldl_aux = ldl_aux->ldl_anterior;

        }
            printf("CPF-> %s\n", lista_d[ldl_aux->ldl_posicao].ld_cpf);
            printf("Nome-> %s\n", ldl_aux->ldl_nome);
            printf("Telefone-> %s\n", lista_d[ldl_aux->ldl_posicao].ld_tel);
            printf("\n");
    }
    else
          printf("\nNao existe cadastros!!\n");
}


