/*3. Faça um programa para copiar um arquivo de texto. O arquivo de destino deve ser criado.*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


main(){
setlocale(LC_ALL, "portuguese");

    FILE *arq, *arqtwo;
    char str[20], strtwo[20], pl[200];
    char c, ctwo;

    puts("Digite o nome do arquivo que você deseja copiar o conteúdo, para um novo arquivo criado(DIGITE .txt NO FINAL):");
    gets(str);
    puts("Digite o nome do arquivo a ser criado(DIGITE .txt NO FINAL");
    gets(strtwo);

    if((arq = fopen(str,"r")) == NULL){
        puts("Arquivo não encontrado!!!");
        exit(1);
    }
    arqtwo = fopen(strtwo,"w");

    fgets(pl, 200, arq);
    fputs(pl, arqtwo);

}
