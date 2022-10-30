/*Escreva um programa que leia três valores inteiros, A, B e N ( assuma que | A –
B | > 3N ). O programa deve gerar dois valores aleatórios x e y, ambos entre A e B
e com diferença entre eles maior que N ( ou seja, | x – y | > N ). Uma forma de
garantir a diferença mínima entre os valores da geração aleatória é gerar primeiro
x e depois gerar tantos valores para y quantos necessários até que tal restrição
seja obedecida. Mas é desejável que vocês codifiquem uma solução que garanta
que o primeiro valor de y já será satisfatório, ou seja, uma solução em que a
função de geração de números aleatórios seja chamada apenas duas vezes.*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>


main(){
setlocale(LC_ALL, "portuguese");


    int a,b,n,x,y;
    printf("Digite três valores inteiros");         // ex: a = 20 b = 10 n = 10 //
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &n);
    x = rand() % (a-b) + b;     // x = 12
        if(x )
        y = rand() %(a-b) + b;  // y = 14











}
