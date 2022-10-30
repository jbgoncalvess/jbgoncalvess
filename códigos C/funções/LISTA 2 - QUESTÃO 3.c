/*Escrever um programa que lê dois valores, x e y, e chama uma função para calcular x elevado na y (assuma x e y inteiros não
negativos). A função deve retornar o valor resultante para a função main, para então ser exibido. Não utilize a função
pronta pow!*/


#include<stdio.h>
#include<locale.h>

int funcpotencia(int x, int y){
    if(y == 0)
        return 1;
    int i, aux;
    aux = x;
    for(i = 1; i < y; i++){
        x = x * aux;

    }
    return x;

}

main(){
setlocale(LC_ALL, "portuguese");
    int x,y;

    printf("Digite um número e a potência para que ele seja elevado: ");
    scanf("%d", &x);
    scanf("%d", &y);

    x =funcpotencia(x,y);
    printf("O resultado é %d", x);



}
