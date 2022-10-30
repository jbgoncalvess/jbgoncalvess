/*Faça um programa que lê uma string composta apenas pelos dígitos 0 e 1, representando um valor binário, e
posteriormente chama uma função para converter a string no valor inteiro representado. O valor inteiro deve ser
retornado para a main, onde deve ser exibido no formato decimal.
Por exemplo: para uma string de entrada “101”, a saída deve ser 5; para uma string de entrada “0110101”, a saída
deve ser 53.*/

#include<stdio.h>
#include<locale.h>
#define TAM 20

int bindec (char str[TAM]){

    int j,j1,k,y= 0,z = 0,x = 2;

    for(j = 0; str[j] != '\0'; j++);        //1010
    j--;   // 3   // 3
    if(str[j] == '1')
            z--;
    for(j1 = 0, j; str[j] != '\0'; j--,j1++){
        /*if(j1 == 0 && str[j] == 1){
            z--;
        }*/
        for(k = 1; k < j1;k++){
            x = x * 2;
            //printf("\n%d",x);
        }
        y = x * (str[j] - 48);     // 0 2
        //printf("\npotencia vezes binario  %d", y);
        z = z + y;
        //printf("\n soma de todos resultados%d",z);
        x = 2;
    }
    return z;

}




main(){
setlocale(LC_ALL, "portuguese");

    int n,i;
    char str[TAM];

    printf("Digite a string com zeros e uns: ");
    scanf("%s", str);
    n = bindec(str);
    printf("\n O valor em decimal é %d", n);

    //printf("%s", str);


}
