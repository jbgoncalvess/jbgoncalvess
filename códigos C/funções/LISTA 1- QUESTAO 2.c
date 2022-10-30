/*Escrever um programa que lê um valor que representa a medida, em metros, da aresta de
um cubo, e chama uma função para calcular o volume do cubo e outra para calcular o
perímetro de cada um dos seus lados.*/

#include<stdio.h>
#include<locale.h>

float func1(float n){
    n = (n*n)*n;
    return n;

}
float func2(float n){
    n = n*12;
    return n;

}



main(){
setlocale(LC_ALL, "portuguese");

    float n,vol,per;

    printf("Digite a aresta de um cubo: ");
    scanf("%f", &n); //5
    vol = func1(n);
    per = func2(n);
    printf("O volume do cubo é %.2f e o perímetro do cubo é %.2f", vol, per);


}
