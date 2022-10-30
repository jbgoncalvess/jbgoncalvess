/*1. Escreva programa que leia um vetor de 500 elementos inteiros. A seguir, o programa deve
construir 3 novos vetores, o primeiro contendo os elementos do vetor lido que ao serem
divididos por 3 apresentem resto igual a 2, o segundo contendo os elementos do vetor lido que
ao serem divididos por 3 apresentem resto igual a 1, e o terceiro contendo os elementos do
vetor lido que ao serem divididos por 3 apresentem resto igual a 0. Os três vetores devem ser
criados dinamicamente, e seus tamanhos devem estar de acordo com os inteiros que irão
conter.*/


#include<stdio.h>
#include<stdlib.h>
#define NUM 10

int resto(int *vet, int *vetor){

    int j, cont0,cont1,cont2;
    cont0 = cont1 = cont2 = 0;

    for(j = 0; j < NUM; j++){
        if(vet[j] % 3 == 0){
            cont0++;
        }
        else if(vet[j] % 3 == 1){
            cont1++;
        }
        else{
            cont2++;
        }
    }
    *(vetor+1) = cont1;
    *(vetor+2) = cont2;
    return cont0;
}

main(){

    int vet[NUM],*pone,*ptwo,*pthree, vetor[3];
    int i, ione, itwo, ithree;

    ione = itwo = ithree = 0;

    puts("Digite os valores para o vetor: ");
    for(i = 0; i < NUM; i++)
        scanf("%d", &vet[i]);

    vetor[0] = resto(vet, vetor);

    pone = (int *)malloc(sizeof(int) * vetor[0]);
    ptwo = (int *)malloc(sizeof(int) * vetor[1]);
    pthree = (int *)malloc(sizeof(int) * vetor[2]);

    for(i = 0; i < NUM; i++){
        if(vet[i] % 3 == 0){
            pone[ione] = vet[i];
            ione++;
        }
        else if(vet[i] % 3 == 1){
            ptwo[itwo] = vet[i];
            itwo++;
        }
        else{
            pthree[ithree] = vet[i];
            ithree++;
        }
    }

    for(ione = 0; ione < vetor[0]; ione++)
        printf("\nVALORES NO VETOR DE RESTO 0: %d\n", pone[ione]);

    for(itwo = 0; itwo < vetor[1]; itwo++)
        printf("\nVALORES NO VETOR DE RESTO 1: %d\n", ptwo[itwo]);

    for(ithree = 0; ithree < vetor[2]; ithree++)
        printf("\nVALORES NO VETOR DE RESTO 2: %d\n", pthree[ithree]);

    free(pone);
    free(ptwo);
    free(pthree);

}
