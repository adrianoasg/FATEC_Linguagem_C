///Trabalho de Estrutura de Dados
///Professor: Nava
///Alunos: Adriano Souza Guimarães   RA: 1630481611003
        ///Alisson Augusto Alves RA: 1630481621053


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.c"
#include "menu.h"
#include "varGlobais.h"     //declaração de variáveis globais
#include "lista_d.c"    //funções listas dinamicas
#include "lista_d.h"    //definições lista dinamica
#include "lista_dl.c"   //funções duplamente ligada
#include "lista_dl.h"   //biblioteca de definições da lista duplamente ligada
#include "arv_b.c"  //funções da arvore binária
#include "arv_b.h"  //biblioteca de definições da arvore binária

int main()
{
    //Inicializando variáveis
    opcao = 0;
    gl_posicao = 0;
    ld_tamanho = 5;

    inicializar_ld();
    inicializar_ldl();
    inicializar_ab();
    //Inicializando variáveis

    while(opcao !=6)    //condicional do menu
    {
        menu();
        switch(opcao)
        {
        case 1:     //NOVO CADASTRO
            system("cls");
            printf("-----------------------CADASTRO-----------------------\n");
            printf("=>Digite o CPF: ");
            fflush(stdin);
            gets(gl_cpf);

            printf("=>Digite o Nome: ");
            fflush(stdin);
            gets(gl_nome);

            printf("=>Digite o Telefone: ");
            fflush(stdin);
            gets(gl_tel);

           ab_aux = localizar_ab(ab_inicio, gl_cpf, gl_posicao);    //localiza para verificar se ja existe esse cpf

           if(ab_aux != 0 && (strcmp(lista_d[ab_aux->arvb_posicao].ld_cpf, gl_cpf) == 0)){  //caso existir
               printf("CPF ja cadastrado!!!\n");
               system("pause");
            }
            else {  //se estiver livre
            adicionar_ld(gl_cpf, gl_nome, gl_tel);
            adicionar_no_ldl(gl_nome, gl_posicao-1);
            adicionar_ab(ab_inicio, novo_no_ab(gl_cpf, gl_posicao-1));

            printf("\n");
            printf("**********Cadastrado com Sucesso!!!!*************\n");
            printf("\n");

            system("pause");
            }
            break;

         case 2:    //BUSCA
            system("cls");
            printf("-----------------------BUSCA--------------------------\n");
            printf("Digite O CPF: ");
            fflush(stdin);
            gets(gl_cpf);

            ab_aux = localizar_ab(ab_inicio, gl_cpf, gl_posicao);   //localiza na arvore para ver se existe o registro

            if(ab_aux == 0){    //se não existir
                printf("Nao encontrei o CPF!\n");
                printf("\n");
                    }
                else{   //se existir

                 printf("CPF-> %s\n", ab_aux->ab_cpf);   //imprime cpf na tela
                 printf("Nome-> %s\n", lista_d[ab_aux->arvb_posicao].ld_nome);   //imprime nome na tela
                 printf("Telefone-> %s\n", lista_d[ab_aux->arvb_posicao].ld_tel);    //imprime telefone na tela
                 printf("\n");
                }
                system("pause");
                break;

        case 3: //EXCLUIR
            system("cls");
            printf("----------------------EXCLUIR-------------------------\n");
            printf("Digite o CPF para excluir: ");
            fflush(stdin);
            gets(gl_cpf);

            int resp;
            char decisao;

            int local_pos;  //var que armazenara posição encontrada do dado
            struct noAB *pesquisa;
            pesquisa = localizar_ab(ab_inicio, gl_cpf, gl_posicao); //localiza estrutura especificada

            if(pesquisa == 0){  //se o dado não existir aborta operação
            printf("Impossivel excluir, registro nao existe!\n");
            printf("\n");
                }
               else    //se existir prossiga
                   {
                     printf("\nTem certeza que deseja excluir?\n");
                     printf("Digite (S)im ou (N)ao=>");
                     fflush(stdin);
                     scanf("%c", &decisao);

                     do{
                        resp = decidir(decisao);

                        if(resp == 1){
                        local_pos = pesquisa->arvb_posicao; //passando resultado da pesquisa para variável
                        excluir_no_ldl(gl_cpf, local_pos);  //chamada exclusão duplamente ligada
                        excluir_ab(gl_cpf, gl_posicao); //chamada exclusão arvore binária
                        printf("\nExcluido com sucesso!\n");

                        }
                         else

                            printf("\nRegistro nao excluido!\n");

                      }while(gl_sair != 1);

                      gl_sair = 0;
            }
            system("pause");
            break;

        case 4: //LISTAR
            system("cls");
            printf("-----------------------LISTAR-------------------------\n");
            listar_ldl();   //função de listar
            system("pause");
            break;

        case 5:     //LISTAR INVERTIDO
               system("cls");
               printf("----------------LISTAR INVERTIDO-----------------------\n");
               listar_invertido_ldl();  //função de listar ao contrário
               system("pause");

                break;
               }
    }

            //Desalocando memória alocada
                finalizar_ld();
                finalizar_ldl();
                finalizar_ab(ab_inicio);
            //Desalocando memória alocada

    return 0;
}
