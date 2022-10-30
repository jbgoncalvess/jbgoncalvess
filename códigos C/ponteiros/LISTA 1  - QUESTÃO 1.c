/*1. Escreva um programa em cuja função main sejam lidos valores para duas variáveis inteiras.
 A seguir, deve ser chamada uma função, passando as variáveis lidas como parâmetros, onde é calculada a média aritmética dos valores lidos e,
se a média for um valor inteiro, ela é atribuída às variáveis. Se a média não for um valor inteiro,
uma das variáveis deve receber o maior valor inteiro menor que a média e a outra variável deve receber o menor valor inteiro maior que a média,
ou seja, os dois valores inteiros entre os quais está a média (por exemplo, lidos os valores 4 e 7, a média é 5.5,
e as variáveis devem assumir os valores 5 e 6). Ao final do programa, a função main deve mostrar os valores resultantes das variáveis na tela.
 Não use variáveis globais!*/

 #include<stdio.h>
 #include<locale.h>

 void *func1(int *a, int *b){
        int n;

        n = *a + *b;

        if(n % 2 == 0){
            *a = n / 2;
            *b = n /2;
        }
        else{
            *a = n/2;
            *b = n/2+1;
        }
 }

 main(){
setlocale(LC_ALL, "portuguese");
     int a,b;

     printf("Digite dois valores: ");
     scanf("%d", &a);
     scanf("%d", &b);
     func1(&a,&b);
     printf("Os valores são %d e %d", a, b);















 }
