/*Escrever um programa que chama uma função que retorna a soma dos número inteiros que
existem entre os números n1 e n2 (inclusive ambos) passados como parâmetros. A função
deve funcionar inclusive se o valor de n2 for menor que n1. Ler n1 e n2 na função main e
retornar para a main o valor resultante. Ex:
n=somaintervalo(3, 6); /* n recebe 18 (3 + 4 + 5 + 6)
/*n=somaintervalo(5,5); /* n recebe 10 (5 + 5)
n=somaintervalo(-2,3); /* n recebe 3 (-2 + -1 + 0 + 1 + 2 + 3)
n=somaintervalo(4, 0); /* n recebe 10 (4 + 3 + 2 + 1 + 0) */

#include<stdio.h>
#include<locale.h>

int func1(int n1, int n2){
    int i;
    if(n1 > n2){
        i = n1;
        for(i--; i>=n2; i--)
            n1 = n1 + i;
        return n1;

    }
    else if(n1 < n2){
        i = n2;
        for(i--; i>=n1; i--)
            n2 = n2 + i;
        return n2;
    }
    else if (n1 == n2)
        return n1 + n1;

}



main(){
    setlocale(LC_ALL, "portuguese");
    int n1, n2, soma;

    printf(" Digite dois valores em qualquer ordem: ");
    scanf("%d", &n1);   // 5
    scanf("%d", &n2);   //3
    soma = func1(n1,n2);
    printf(" A soma é %d", soma);






}
