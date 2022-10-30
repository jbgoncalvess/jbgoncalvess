/*2. Escreva um programa que leia duas strings e um valor N. O programa deve copiar os
conteúdos das strings lidas para outra string, inserindo a segunda dentro da primeira, a partir
da posição indicada por N. Por exemplo, lidos “A aula”, “outra ” e 2, a string resultante deve
ficar “A outra aula”. A string que receberá os conteúdos deve ser alocada de forma a ter o
tamanho exato de acordo com o conteúdo que receberá.*/


#include <stdio.h>
#include <stdlib.h>

char *juntar(char *stra, char *strb, int n){

    char *p, *pini;
    int i,j,a;

    for(i = 0; stra[i]; i++);
    for(j = 0; strb[j]; j++);

    a = j+i+1;

    p = (char *) malloc(sizeof(char) * a);
    pini = p;

    for(j = 0; j < a; j++){
        if(j < n){
           *(p+j) = *stra;
            stra++;
        }
        else if(*strb){
            *(p+j) = *strb;
            strb++;
        }

        else{
            *(p+j) = *stra;
            stra++;
        }
    }
    *(p+j) = '\0';
    return p;
}


main(){

    int n;
    char stra[50], strb[50], *p;

    puts("Digite uma string: ");
    gets(stra);
    puts("Digite uma segunda string: ");
    gets(strb);
    puts("Digite um valor n para colocar a segunda string");
    scanf("%d", &n);

    p = juntar(stra, strb, n);

    printf("A nova string lida é: %s", p);
    free(p);

}
