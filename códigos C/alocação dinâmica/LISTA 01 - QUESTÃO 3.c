/*3. Escreva um programa que leia uma string e copie o conteúdo da string lida para outra
eliminando uma letra para cada par de letras adjacentes iguais.
Por exemplo, lida a string “assassino”, a nova deve ser “asasino”.
A string de destino deve ter exatamente o tamanho necessário para armazenar o conteúdo que
será copiado para ela.*/


#include<stdio.h>
#include<stdlib.h>

char *asasino(char *str){       //assassino
    int i = 0, j= 0;
    char *nmexer;               //endereço q retorna e do free
    char *pi, *p;
    p = str;

    for( ;*p;p++);              //endereço do '\0'

    while(str != p){
        if(*str != *(str+1)){
            i++;
        }
        str++;
        j++;
    }
    str -= j;

    pi = (char *)malloc(sizeof(char) * i);
    nmexer = pi;

    while(str != p){
        if(*str != *(str+1)){
            *pi = *str;
             pi++;
        }
        str++;

    }
    return nmexer;
}




main(){

    char str[50], *p;

    printf("Digite uma string: ");
    gets(str);

    p = asasino(str);

    printf("A nova string e: %s.", p);
    free(p);




}
