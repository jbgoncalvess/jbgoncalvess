/*2. Leia um vetor de 100 números reais (ponto flutuante). A partir deste vetor, crie outros dois,
um para conter os números maiores ou iguais à média, e outro para os números menores que
a média dos valores do vetor original. Estes dois vetores devem ser alocados dinamicamente e
ter o menor tamanho possível.*/

#include<stdio.h>
#include<stdlib.h>
#define NUM 10


main(){

    float vet[NUM],*pma, *pme, *ima, *ime;
    int cont =0, i, menor;
    float n = 0;

    printf("Digite 100 valores: ");

    for(i = 0; i < NUM; i++){
        scanf("%f", &vet[i]);
        n +=vet[i];
    }

    n /= NUM;

    printf("\n\nValor da media %.2f\n\n", n);

    for(i = 0; i < NUM; i++){
        if(vet[i] >= n)
            cont++;     //cont maior ou igual a média
    }

    menor = NUM - cont;     //n menor que a média

    pma = (float *) malloc(sizeof(float) * cont);
    pme = (float *) malloc(sizeof(float) * menor);

    ima = pma;
    ime = pme;

    for(i = 0; i < NUM; i++){
        if(vet[i] >= n){
            *pma = vet[i];
             pma++;
        }
        else{
            *pme = vet[i];
             pme++;
        }
    }

    printf("Vetor de numeros maiores e iguais a media: ");
    for(i = 0; i < cont; i++){
        printf("%.2f   ", ima[i]);
    }
    printf("\nVetor de numeros menores que a media: ");
    for(i = 0; i < menor; i++){
        printf("%.2f   ", ime[i]);
    }
    free(ima);
    free(ime);


}
