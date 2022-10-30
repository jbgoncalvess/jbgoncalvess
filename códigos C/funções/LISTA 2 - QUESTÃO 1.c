/*Escreva um programa que leia um valor inteiro (e natural) e passe este valor para uma função. A função deve
calcular a soma de todos os múltiplos do valor lido menores que 1000, e retornar este valor para ser exibido na
função main.*/

#include<stdio.h>
#include<locale.h>
#define NUM 1000


int func1(int n){

    int i,res = 0;

    for(i = 0; i < NUM; i++){

            if(i % n == 0){
                res = res + i;
            }
    }
    return res;


}


main(){
setlocale(LC_ALL, "portuguese");

    int n;

    printf("Digite um número: ");
    scanf("%d", &n);
    n = func1(n);
    printf("A soma dos multiplos do valor lido é %d", n);

}
