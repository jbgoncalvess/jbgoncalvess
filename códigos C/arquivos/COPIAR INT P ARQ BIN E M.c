
#include<stdio.h>
#include<stdlib.h>


main(){

    FILE *fp1, *fp2;
    char nomearq[30];
    int x, n;

    puts("Digite o nome do arquivo que deseja copiar os dados para o outro");
    scanf("%s", nomearq);

    if((fp1 = fopen(nomearq, "r")) == NULL){
        puts ("Este arquivo no existe");
        exit (1);
    }

    puts("Digite o nome do arquivo que recebera os dados em binário");
    fflush(stdin);
    scanf("%s", nomearq);
    fp2 = fopen(nomearq, "w+b");

    while(!feof(fp1)){
        fscanf(fp1, "%d", &x);
        fwrite(&x, sizeof(int), 1, fp2);
        if(x == 445)
            n = ftell(fp2);
    }
    fseek(fp2, n, SEEK_SET);
    while(!feof(fp2)){
        fread(&x, sizeof(int), 1, fp2);
        printf("%d ", x);
    }
    //printf("%d", n);
    fclose(fp1);
    fclose(fp2);
}
