/*Escreva um programa que leia dois arquivos, um que armazena uma seqüência de inteiros
em modo texto, separados por espaço, e outro que armazena uma seqüência de inteiros
em modo binário, e verifique se os inteiros são os mesmos (na mesma ordem e na mesma
quantidade).*/


#include<stdio.h>
#include<stdlib.h>


main(){

    FILE *fp1, *fp2;
    char nomearq[30];
    int n, x, i;
    i = 0;

    puts("Digite o nome do primeiro arquivo, oq ta em modo texto os num: ");
    scanf("%s", nomearq);

    if((fp1 = fopen(nomearq, "r")) == NULL){
        puts("Este arquivo no existe cria");
        exit(1);
    }

    puts("Digite o nome do segundo arquivo, oq ta em modo binario: ");
    scanf("%s", nomearq);

    if((fp2 = fopen(nomearq, "r")) == NULL){
        puts("Este arquivo no existe cria");
        exit (1);
    }

    while(!feof(fp1) && !feof(fp2)){
        fscanf(fp1, "%d", &n);
        fread(&x, sizeof(int), 1, fp2);
        if(n != x){
            puts("Os inteiros nao sao os mesmo, pelo menos nao na mesma sequencia");
            fclose(fp1);
            fclose(fp2);
            exit(1);
        }
    }
    puts("Sequencia de valores iguais.");
    fclose(fp1);
    fclose(fp2);
}
