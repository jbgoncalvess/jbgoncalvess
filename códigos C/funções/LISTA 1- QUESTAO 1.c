/*1. Escreva um programa que leia um número inteiro e passe o número para uma função em
que é calculado o valor do seu fatorial. O resultado deve ser mostrado na função main.*/

#include<stdio.h>
#include<locale.h>
                                                // 5 * 4 *3 *2* 1*
int func(int n){
    int i;
    i = n-1;
    for(i ; i > 0; i--){
        n = n * i;
    }
    return n;
}



main(){
setlocale(LC_ALL, "Portuguese");

    int n, res;

    printf("Digite um numero para descobrir seu fatorial: ");
    scanf("%d", &n);
    res = func(n);
    printf("Resultado do fatorial é %d", res);


}
