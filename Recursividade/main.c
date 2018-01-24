#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int fatorial(int x);
void menu();
int fibo(int n);


int opcao = 0;

int main()
{
    int n, fat, m;

do{
    menu();

    switch(opcao){

      case 1:
          printf("Calculo fatorial...");
          printf("\nDigite um numero: ");
          scanf("%d", &n);
          fat = fatorial(n);
          printf("\n%d! = %d", n, fat);
          getch();
          printf("\n");
          break;
      case 2:
          printf("Sequencia Fibonacci....");
          printf("\nDigite um numero: ");
          scanf("%d", &m);
          printf("\nO %d. termo da seq. de Fibonacci eh: %d", m, fibo(m));
          getch();
          printf("\n");
          break;
      case 3:
           printf("Saindo!!!\n");
           break;

      default:
          printf("Digite uma opcao valida\n");

 }
}  while(opcao != 3);
    system("PAUSE");
    return 0;
}

void menu()
{
    system("cls||clear");
    printf("                                 MENU\n");
    printf(" 1 - Fatorial\n");
    printf(" 2 - Sequencia de Fibonacci\n");
    printf(" 3 - Sair\n");
    printf("=>");
    scanf("%d", &opcao);

}

int fatorial(int x)
{
    int i, fat;
    i=x;
    for(fat=1; i>1; i--)
        fat= (fat*i);
    return (fat);
}

int fibo(int n)
{
    if(n==1)
        return 1;
    if(n==2)
        return 1;
    else
    return fibo(n-1) + fibo(n-2);
}
