#include <stdio.h>
#include <stdlib.h>
struct elemento {
char nome[40];
int idade;
float altura;
};
main () {
struct elemento p;
FILE *fp, *fp2;
if((fp=fopen("arquivin.txt","r"))==NULL){
puts("erro ao abrir o arquivo");
exit(1);
}
if((fp2=fopen("x2.txt","wb"))==NULL){
puts("erro ao abrir o arquivo");
exit(1);
}
while (!feof(fp)) {
fscanf(fp, "%s %d %f", p.nome, &p.idade, &p.altura);
fwrite (&p, sizeof(struct elemento), 1, fp2);
}
fclose (fp);
fclose (fp2);
}
