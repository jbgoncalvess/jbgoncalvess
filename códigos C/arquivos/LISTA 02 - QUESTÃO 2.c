/*Escreva um programa que leia um nome de um arquivo de texto e mostre na tela qual linha
do arquivo tem mais caracteres (assuma que as linhas têm no máximo 100 caracteres). O
programa deve mostrar uma mensagem na tela informando qual a linha e quantos
caracteres ela tem.*/

#include<stdio.h>
#include<stdlib.h>

main(){

    FILE *fp;
    int i,j,m,l;
    char nomefp[30], strtam[100];
    m = 0;
    j = 1;
    strtam [0] = '\0';

    puts("Digite o nome do arquivo que deseja verificar qual linha tem mais caracteres:");
    scanf("%s", nomefp);

    if((fp = fopen(nomefp, "r")) == NULL){
        puts("ESSE ARQUIVO NO EXISTE");
        exit(1);
    }

    while(!feof(fp)){

        fgets(strtam, 101, fp);
        //printf("%s", strtam);
        for (i = 0; strtam[i]; i++);
        //printf(" O Q DEU");
        if (m < i){
            m = i;
            l = j;
        }
        j++;
    }

    if (m == 0)
        puts("Este arquivo esta vazio");
    else
        printf("A linha que contem mais caracteres e a %d, com %d caracteres", l, m);

    fclose(fp);










}
