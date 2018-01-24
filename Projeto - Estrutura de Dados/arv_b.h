#ifndef ARV_B_H_INCLUDED
#define ARV_B_H_INCLUDED

struct noAB *ab_inicio;
struct noAB *ab_anterior;
struct noAB *ab_aux;

char ultimo_movimento = ' ';

void adicionar_ab(struct noAB *ab_posicao, struct noAB *ab_novo);
struct noAB *novo_no_ab(char *cpf, int pos);
void inicializar_ab();
void finalizar_ab(struct noAB *ab_posicao);
struct noAB *localizar_ab(struct noAB *posicao, char *cpf, int pos);
void excluir_ab(char *cpf, int pos);

#endif // ARV_B_H_INCLUDED
