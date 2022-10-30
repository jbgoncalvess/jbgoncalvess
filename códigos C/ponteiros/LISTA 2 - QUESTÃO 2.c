/*Escreva um programa que leia um vetor de 50 elementos inteiros em ordem crescente e passe este vetor
para uma função que verifica se é constante a diferença existente entre cada elemento e seu sucessor no
vetor. Na função main, exiba a diferença, se esta for constante, ou uma mensagem informando que não há
diferença constante. A função deve receber o vetor através de um ponteiro para o primeiro elemento, e não
devem ser usados índices na manipulação.
Exemplo: na sequencia 2 4 6 8 10, a diferença entre os elementos é constante; já em 2 4 5 7 10, a diferença
não é constante.*/

#include<stdio.h>
#include<locale.h>
#define NUM 10

int *func1(int *p, int *pf){
    int n,cont = 0;
    n = *(p+1) - *p;

    for( ;p < pf; p++){
        if(*(p+1) - *p == n){               // 2 , 4 ,6 ,8 ,10 ,12 ,14 ,16 ,18 ,20  = cont 1 2 3 4 5 6 7 8 9
           cont++;
           if(cont == 9)
                break;
        }
    }
    return cont;
}

main(){
setlocale(LC_ALL, "portuguese");

    int vet[NUM], i;

    printf("Digite os valores para o vetor: ");
    for(i = 0; i < 10; i++){
        scanf("%d", &vet[i]);
    }

    i = func1(vet,&vet[i]);  // 50  //
    if(i == NUM-1)
        printf("A diferença no vetor é constante");
    if(i < NUM-1)
        printf("A diferença no vetor não é constante");



}
