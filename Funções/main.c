#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int primo(int n);
void equacao(int a, int b, int c);

int main()
{
    int n, n1, n2, n3;
    int op;

    do{
        printf("\n-----------------MENU------------------");
        printf("\nNumero Primo          (1): ");
        printf("\nEquacao do Segundo Grau    (2): ");
        printf("\nSAIR                  (3): ");
        printf("\nDIGITE UMA OPCAO: : ");
        scanf("%d", &op);

    switch(op){
        case 1:
            printf("\nDigite um numero para saber se ele eh primo: ");
            scanf("%d", &n);
            if(primo(n) == 1){
                    printf("\nO numero %d eh primo!", n);
            } else {
                printf("\nO numero %d nao eh primo!", n);
                printf("\n");
                }
                break;
        case 2:
            printf("Equacao do Segundo Grau");
            printf("\n Digite a: ");
            scanf("%d", &n1);
            printf("\n Digite b: ");
            scanf("%d", &n2);
            printf("\n Digite c: ");
            scanf("%d", &n3);
            equacao(n1, n2, n3);
            break;
        case 3:
            printf("Saindo....");
            break;

            default:
            printf("\nOpcao invalida!!!");
            break;
        };

    }while(op!=3);


return 0;

}

int primo(int num){
    int i;
	int primo = 1;

	for (i = 2; i < num; i++){
        if (num % i == 0){
            primo = 0;
		}
	}

	return primo;
}

void equacao(int a, int b, int c){
    float delta, x1, x2;
    delta=pow(b,2)-4*a*c;

    if (a == 0){
        printf("\nNao eh equacao de 2 grau!");
        return;
    }else if (delta<0){
        printf ("\nDelta e igual a %.2f", delta);
        printf ("\n\nDelta Negativo, impossivel calcular.\n\n");
        } else {
            printf ("\nDelta e igual a %.2f\n", delta);
            x1=((-b)+sqrt(delta))/(2*a);
            x2=((-b)-sqrt(delta))/(2*a);
            printf ("\nO x1=%.2f e o x2=%.2f\n\n", x1, x2);
            printf("\n");
        }
}
