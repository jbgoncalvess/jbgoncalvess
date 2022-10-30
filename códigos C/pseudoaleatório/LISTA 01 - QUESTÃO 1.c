/*Escreva um programa que gere um valor inteiro aleatório, identificado por m,
entre 100 e 1000. A seguir, deve ser gerado um segundo valor, também de forma
aleatória e identificado por n, entre -m/2 e +m/2. O programa deve ser feito de
modo que a função para geração de números aleatórios seja chamada apenas
duas vezes, uma para gerar m e outra para gerar n. Ao final, os valores de m e n
devem ser exibidos na tela.*/


#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<locale.h>             //TESTE ENTRE 10 e 20.



main(){
setlocale(LC_ALL, "portuguese");

    int m, n, i;

    srand((unsigned)time(NULL));

        m = rand() % 11 + 9;

        n = rand() % (2*m+1) - (m+1);          //15

        printf("O valor de m é %d e o valor de n é %d", m,n);







}
