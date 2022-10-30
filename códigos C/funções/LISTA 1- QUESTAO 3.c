/*Escreva um programa no qual seja chamada uma função que receba como parâmetro um
ano e retorne 1 se o ano for bissexto, e 0 caso contrário. São bissextos todos os anos não
seculares divisíveis por 4, e os seculares divisíveis por 400.*/

#include<stdio.h>
#include<locale.h>

int func1(int n){
    if(n % 4 == 0 && n % 100 != 0 || n % 100 == 0 && n % 400 == 0)
        return 1;
    else
        return 0;

}

main(){
setlocale(LC_ALL, "portuguese");
    int n;

    printf("Digite um ano para verificar se ele é bissexto: ");
    scanf("%d", &n);
    n = func1(n);
    printf("%d", n);

}
