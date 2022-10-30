/*2. Faça um programa que passe um vetor de 50 elementos inteiros para uma
função na qual ele é preenchido com 50 valores inteiros informados pelo usuário.
A posição no vetor que cada elemento ocupará será definida aleatoriamente.
Quando o vetor já estiver com a maioria de suas posições ocupadas, é provável
que a função de geração de números pseudo-aleatórios indique posições já
ocupadas. Uma forma de lidar com este problema seria continuar gerando índices
possíveis até encontrar uma posição desocupada. Procure fazer um programa
que, garantidamente, precise de apenas 50 chamadas à função de geração de
números para definir as 50 posições.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#define TAM 10


void func1(int vet[]){              //função void pois alterei os endereções. E assim utilizei uma passagem por referência "discreta".
    int i, j, n;                    // Variáveis = n= valor que usuário quer por no vetor aleatóriamente. i = indice de qts posições ja
    for(i = 0; i < TAM; i++)        // foi preenchida. j= posição sorteada pelo rand.
        vet[i] = -10;
        printf("%d", &vet);
    for(i = 0; i < TAM; ){          // laço que faz o i avançar a cada vez que uma posição for preenchida aleatóriamente.
        j = rand() % 10;            // j = gera a posição aleatória.
        if(vet[j] == -10){          // verifico se é valida.
            printf("Informe um valor usuário: \n");
            scanf("%d", &n);        // user digita o numero.
            vet[j] = n;
            i++;
        }
    }

}



main(){
setlocale(LC_ALL, "portuguese");

    int vet[TAM],i;

    srand((unsigned)time(NULL));        //inicializar semente.
    func1(vet);                         // passar vet pra função.
    printf("Valores dentro do vetor:");
    for(i = 0; i < TAM; i++){
        printf("%d -- ", vet[i]);       // resultado do vetor após a passagem dos valores para posições pseudoaleatórias.
    }
}
