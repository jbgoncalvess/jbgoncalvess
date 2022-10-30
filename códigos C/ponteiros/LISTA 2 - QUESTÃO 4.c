/*Escreva um programa que leia um valor inteiro n e um vetor de 400 elementos inteiros. A seguir, passe
os dados lidos para uma função em que o elemento da posição n é retirado, todos elementos da sua direita
(de endereços maiores) deslocados uma posição para a esquerda, e o elemento originalmente na posição n
recolocado no final do vetor. Como exemplo, imagine um vetor de 5 elementos como o da figura:*/

#include<stdio.h>
#include<locale.h>
#define NUM 6

void *elementosai(int n, int *vet){
    int *paux, aux;
    paux = (vet + (NUM-1));      // aqui passa // posição inicial 0 - 5 = 6 posições//
    aux = *(vet+n);
    //printf("%d\n", aux);
    *(vet+n) = '\0';
    for( ;vet < paux; vet++){
        if(*vet == '\0'){
            *vet = *(vet+1);
            *(vet+1) = '\0';            // 10//20//40//50//60//\0
        }
    }
    *vet = aux;
    //printf("%d\n", *vet);

}

main(){
setlocale(LC_ALL, "portuguese");
    int n,i, vet[NUM];

    printf("Digite o valor de n: ");
    scanf("%d", &n);
    printf("Digite os valores para para o vetor: ");
    for(i = 0; i < NUM; i++){
        scanf("%d", &vet[i]);
    }
    elementosai(n,vet);
    printf("Resultado final do vetor: ");
    for(i = 0; i < NUM; i++){
        printf("|%d", vet[i]);
    }

}
