#include <stdio.h>
int main()
{
  char texto[10] = {""};
  int i = 10;
  
  printf("\n Entre com o texto: ");
  scanf("%[^\n]s", texto);
  setbuf(stdin, NULL);
  printf("\n Invertido: ");
  
  while(i--){
    printf("%c", texto[i]);
  }

  printf("\n");
  return 0;
}