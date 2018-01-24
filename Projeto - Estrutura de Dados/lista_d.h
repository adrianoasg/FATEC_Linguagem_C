#ifndef LISTA_D_H_INCLUDED
#define LISTA_D_H_INCLUDED

struct noLD *lista_d;

void adicionar_ld(char *cpf, char *nome, char *tel);
void expandir_ld();
void inicializar_ld();
void finalizar_ld();

int ld_tamanho;


#endif // LISTA_D_H_INCLUDED
