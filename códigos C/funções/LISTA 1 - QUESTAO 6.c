/*Escreva um programa que leia um valor inteiro positivo n menor que 500 e um vetor de 500
elementos inteiros. A seguir, passe o inteiro e o vetor para uma função, que encontrará e
retornará o n-ésimo maior elemento. O vetor não deve ser duplicado e nem modificado (não
ordene). Por exemplo, lido o valor 3, deve ser mostrado o terceiro maior elemento do vetor.
Considere que o vetor não tem valores repetidos.*/

#include<stdio.h>
#include<locale.h>
#define NUM 10                                  // 2/1/3/10/8/5/7/11/15/9 //

int func1(int n, int vet[NUM]){
    int j,j1,ma,mai= -1;
    ma = vet[0];
    for(j1 = 0; j1 < n; j1++){
        vet[mai] = -10000;

    for(j = 0; j < NUM-2; j++){           // 1 MAIOR 2 MAIOR 3 MAIOR
        if(vet[j] < vet[j+1])
            ma = vet[j+1];
            mai = j;

    }
    }


}



main(){
setlocale(LC_ALL, "portuguese");

    int n, i, vet[NUM], res;

    printf("Digite um valor menor que 500:");
    scanf("%d", &n);    //3

    printf("Digite os valores do vetor: ");
    for(i = 0; i <NUM; i++)
        scanf("%d", &vet[i]);

    res = func1(n,vet[NUM]);




















    /*for(i = 0; i < NUM; i++)
        vet[i] = NUM - (i * 10);


    for(i = 0; i < NUM; i++)
        printf("%d--",vet[i]);*/






}
