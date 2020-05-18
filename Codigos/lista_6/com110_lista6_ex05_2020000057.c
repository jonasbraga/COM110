#include <stdio.h>
#include <string.h>

int isAlphanumeric(int asciiValue);
int main()
{
  char texto[100] = {""}; 
  int n = 0;
  printf("\n Entre com o texto: ");
  scanf("%[^\n]s", texto);
  printf(" Entre com o numero: ");
  scanf("%d", &n);
  setbuf(stdin, NULL);
  n = n % 26;
  for(int i = 0; i < strlen(texto); i++){
    if(((int)texto[i]) == 32){
      texto[i] = '#';
    }else{
      if(!isAlphanumeric((int)texto[i])) continue;
      if(isAlphanumeric(((int)texto[i]) + n)){
        texto[i] = ((int)texto[i]) + n; 
      }else{
        int a = ((int)texto[i]) + n;
        if(a >= 123){
          texto[i] = 97 + (a - 123);        
        }else if(a >= 91){
          texto[i] = 65 + (a - 91);   
        }
      }
    }
  }

  printf("\n\n Seu texto criptografado: %s\n",texto);
  return 0;
}

int isAlphanumeric(int asciiValue){
  return (int)((asciiValue >= 65 && asciiValue <= 90) ||  (asciiValue >= 97 && asciiValue <= 122));
}