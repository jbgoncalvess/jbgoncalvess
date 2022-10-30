/*Escreva um programa que leia uma string e passe esta string para uma função na qual são trocadas de lugar a primeira e a última letras.
A função deve receber a string através de um ponteiro, e fazer a manipulação sem usar índices.
Exiba a string original e a string resultante através de um printf na função main.*/

#include<stdio.h>
#include<locale.h>

void *trocaletra(char *p){      //to passando endereço
    char aux,*paux;
    paux = p;                   //1° endereço;
    aux = *p;
    for( ;*p != '\0'; p++);
    p--;
    *paux = *p;
    *p = aux;
                                      //cavalo
}
main(){

    char str1[30];

    printf("Digite uma palavra ou frase: ");
    gets(str1);
    trocaletra(str1);
    printf("String resultante %s", str1);           //endereço &88

}
