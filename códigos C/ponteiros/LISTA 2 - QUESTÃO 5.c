/* Escrever um programa que leia valores para um vetor de 50 elementos inteiros e chame uma função para
copiar os elementos do vetor para outro, de mesmo tamanho, colocando-os em ordem crescente, ou seja,
ao final do programa o segundo vetor deve conter os mesmos valores lidos para o primeiro, porém em
ordem crescente. Antes de encerrar o programa, na função main, exiba os dois vetores na tela. A
manipulação dos vetores deve ser feita sem o uso de índices, apenas com ponteiros.*/

#include<stdio.h>
#include<locale.h>
#define TAM 10

void *colocaordem(int *vet0, int *vet1){
    int *posvet0, *vet0cp;
    vet0cp = vet0+1;
    posvet0 = vet0 + 9;

    for( ;vet0 < posvet0; ){
        if(*vet0 >= *vet0cp){           //comparando valor do vet com os outros
            vet0cp++;

        }
        else{
            vet0 = vet0cp;              // achei um valor maior, assumo ele e comparo com os proximos do vetor;
            vet0cp = vet0+2;            //  2 3 4 1 5 6 8 7 10 6
        }
    }
         /*  *vet1 = *vet0;
        vet0cp = posvet0; */

}


main(){
setlocale(LC_ALL, "portuguese");
    int vet0[TAM], vet1[TAM];
    int i;

    printf("Digite valores para um vetor: ");

    for(i = 0; i < TAM; i++){
        scanf("%d", &vet0[i]);
    }
    colocaordem(vet0, vet1);

    printf("Os valores dos vetores são: ");
    for(i = 0; i < TAM; i++)
        printf("|%d|", vet0[i]);
    for(i = 0; i < TAM; i++)
        printf("|%d|", vet1[i]);



}
