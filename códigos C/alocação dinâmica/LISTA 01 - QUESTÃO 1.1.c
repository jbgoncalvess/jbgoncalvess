/*1. Escreva um programa que leia uma string e dois valores numéricos a e b, chame uma
função que copie para uma segunda string as letras colocadas entre os índices a e b (inclusive)
na primeira string. A segunda string deve ser criada de forma dinâmica e ter o tamanho exato
para conter a string com os caracteres que receberá. Se um ou os dois índices forem
inadequados para a string lida (muito grandes, por exemplo), esta deve ser copiada inteira.*/

#include<stdio.h>
#include<locale.h>

char *palavra(char *str, int a, int b){

    char *p;
    int i;
    int aux;

    if(a > b){
        aux = a;
        a = b;
        b = aux;
    }

    for(i = 0; str[i]; i++);

    if(a < 0 || b >= i){
       a = 0;
       b = i;
       i++;
    }
    else{
        i = b-a+2;
    }

    p = (char *) malloc(sizeof(char) *i);

    for(i = 0 ; a <= b; a++,i++){
        p[i] = str[a];
    }
    p[i] = '\0';
    return p;

}



main(){
setlocale(LC_ALL, "portuguese");

    char str[50];
    char *p;
    int a, b;

    printf("Digite uma string: ");
    gets(str);

    printf("Digite dois valores: ");
    scanf("%d", &a);
    scanf("%d", &b);

    p = palavra(str, a, b);

    printf("Palavra nova é: %s. ", p);


}
