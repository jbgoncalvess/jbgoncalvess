/*1. Considere um pequeno banco de registros, cada registro composto pelo nome, idade e
altura (em metros) de uma pessoa. As informações são armazenados em um arquivo na
forma de texto, separadas por ‘ ‘. Escreva um programa em C que copie as informações do
arquivo e armazene em outro arquivo, gravado em modo binário.*/

#include<stdio.h>
#include<stdlib.h>

struct banco {

    char str[40];
    int i;
    float a;

};

main(){

    FILE *arq, *arqtwo;
    int i;
    char stra[30];

    struct banco r;

    puts("Digite o nome do primeiro arquivo:");
    arq = fopen(gets(stra), "w+");
    for(i = 0; i < 3; i++){
        puts("Digite um nome:");
        scanf("%s", r.str);

        puts("Digite uma idade:");
        scanf("%d", &r.i);

        puts("Digite uma altura:");
        scanf("%f", &r.a);

        fprintf(arq, "%s %d %.2f ", r.str, r.i, r.a);
        fflush(stdin);
    }
    puts("Digite o nome do segundo arquivo, o que sera copiado o conteudo em modo bin:");
    scanf("%s", stra);
    arqtwo = fopen(stra, "wb");

    rewind(arq);

    while(!feof(arq)){
        fscanf(arq, "%s %d %f", r.str, &r.i, &r.a);
        fwrite(&r, sizeof(struct banco), 1, arqtwo);
    }

    fclose(arq);
    fclose(arqtwo);

}
