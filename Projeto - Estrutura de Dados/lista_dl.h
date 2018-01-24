#ifndef LISTA_DL_H_INCLUDED
#define LISTA_DL_H_INCLUDED

struct noLDL *ldl_inicio;
struct noLDL *ldl_novo;
struct noLDL *ldl_aux;
struct noLDL *ldl_anterior;

void inicializar_ldl();
void finalizar_ldl();
void finalizar_elemento_ldl(struct noLDL *elemento);
void adicionar_no_ldl(char *nome, int pos);
void adicionar_no_final_ldl();
void adicionar_no_inicio_ldl();
void adicionar_no_meio_ldl();
struct noAB *localizar_ldl(struct noLDL *posicao, char *cpf, int pos);
void excluir_no_ldl(char *cpf, int posicao);
void excluir_no_inicio_ldl();
void excluir_no_final_ldl();
void excluir_no_meio_ldl();
void listar_ldl();
void listar_invertido_ldl();
struct noLDL *novo_no_ldl(char *nome, int posicao);


#endif // LISTA_DL_H_INCLUDED
