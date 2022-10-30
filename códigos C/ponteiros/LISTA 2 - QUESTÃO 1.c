/*Escreva um programa que chame uma função onde uma string recebe como conteúdo as 26 letras do
alfabeto, em ordem. A string deve ser exibida na tela após o retorno para a função main, e apresentar o
conteúdo “ABCDEFGHIJKLMNOPQRSTUVWXYZ”. A manipulação na função deve ser feita através de
ponteiros, sendo evitado o uso de índices, e a string deve ser mostrada após o retorno para a função main.*/


#include<stdio.h>
#include<locale.h>

void *alfabeto(char *p){
    char a;
    for(a = 'A'; a <= 'Z'; a++){
        *p = a;
        p++;
    }
    *p = '\0';

}

main(){
setlocale(LC_ALL, "portuguese");

    char str1[30];
    alfabeto(str1);     //&80
    printf("O conteudo da string  é %s", str1);






}


