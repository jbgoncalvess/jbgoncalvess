/*2. Escreva um programa que leia um nome de um arquivo e um caractere, e verifique quantas
vezes o caractere aparece no arquivo.*/


#include<stdio.h>
#include<stdlib.h>

main(){

    FILE *arq;
    char str[20];
    char c,ct;
    int i = 0;

    puts("Digite o nome de um arquivo da pasta corrente:");
    gets(str);
    puts("Digite um caractere");
    scanf("%c", &c);

    if((arq = fopen(str,"r")) == NULL){
        puts("Erro ao abrir o arquivo");
        exit(1);
    }

    ct = getc(arq);
    while(!feof(arq)){
        if(ct == c)
            i++;
        ct = getc(arq);
    }

    printf("O caractere |%c| se repete %d vezes", c, i);

}
