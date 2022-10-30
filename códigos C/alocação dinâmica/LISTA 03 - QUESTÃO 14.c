/*13. Escreva um programa que leia um vetor V de 5000 elementos inteiros e um valor N menor do que 5000.
V e N devem ser passados para uma função onde é alocado dinamicamente outro vetor VN, de tamanho N,
que recebe os N menores valores de V. O vetor V não deve ser modificado, e não deve ser criado nenhum
vetor além de V e VN. Considere que V não tem repetição de valor.*/

#include<stdlib.h>
#include<stdio.h>
#define TAM 10

int *novoVET(int *pvet, int n){
    int *VN, *vini;
    int i, j, aux;

    VN = (int *) malloc(sizeof(int) * n);
    vini = VN;

    for(i = 0; i < TAM; i++){ //Comparo cada valor do laço com todos os outros do vetor                  //55 764 64 4 22 2 10 3 99 100
        for(j = 0, aux = 0; j < TAM; j++){ //Todos outros valores do laço                                         //4 2 3
            if(pvet[i] > pvet[j])       //Se o valor fixado for maior, então aumenta o auxiliar
                aux++;
        }
        if(aux < n){ //Se o número em questão foi maior que os n números, então ele não entra no novo vetor                                                                //1 2
        *VN= pvet[i]; //Caso contrário o número entra aqui
        VN++;         //O novo vetor avança
        }
    }
return vini;        //Retorno a posição inicial do novo vetor alocado
}

main(){
    int vet[TAM], *VN;
    int i, n;

    puts("Digite 10 elementos para o vetor");
    for(i= 0; i < TAM; i++){
        scanf("%d", &vet[i]);
    }

    puts("Digite um valor menor que o tamanho do vetor");
    scanf("%d", &n);

    VN= novoVET(vet, n);

    for(i= 0; i < n; i++){
        printf("%d ", VN[i]);
    }
    free(VN);   //DOU FREEEEEEE

}
