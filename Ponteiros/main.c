#include <stdio.h>
#include <stdlib.h>

int contcaracter(char *s, char c);

int main()
{
   char s[100], c;

   printf("Digite um texto: \n");
   gets(s);
   fflush(stdin);
   printf("Digite uma letra: \n");
   c = getchar();
   printf("Qtd de letras encontradas: %d\n", contcaracter(s, c));

   return 0;
}
int contcaracter(char *s, char c)
{
    char *ptr=s;
    int total = 0;
    while(*ptr != '\0'){
        if(*ptr++==c) total++;
    }
  return total;
}
