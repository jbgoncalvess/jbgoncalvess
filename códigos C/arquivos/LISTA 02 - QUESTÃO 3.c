/*Escreva um programa que leia o nome de um arquivo de texto e abra este arquivo. Este
arquivo terá no máximo 100 linhas, com no máximo 100 caracteres por linha. A seguir, o
programa fará a leitura das linhas do arquivo para uma matriz de caracteres, cada linha do
arquivo para uma linha da matriz. Por fim, após fechar o arquivo, mostre o conteúdo da
matriz na tela.*/

#include<stdio.h>
#include<stdlib.h>


main(){
    FILE *arq;
    char nomearq[30];
    char matc[100][101];
    int i, j, k;
    i = k = j = 0;

    puts ("Digite o nome do arquivo que deseja copiar para matriz de caracteres");
    scanf("%s", nomearq);

    if((arq = fopen(nomearq, "r"))== NULL){
        puts ("O arquivo no existe");
    }
    else{
        while(!feof(arq)){
            fgets(matc[i], 101, arq);
            i++;
            k++;
        }

        for (i = 0; i < k; i++){
            for (j = 0; j < 101 && matc[i][j] != '\0'; j++){
                printf("%c", matc[i][j]);
            }
        }

    }
    fclose(arq);
}
