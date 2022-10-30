#include <stdio.h>
#include <stdlib.h>
main (void) {
FILE *fp;
char mat[100][102], str[20]; // 102 colunas para comportar aindao \n da linha e o \0 da string guardada
int i;
for (i = 0; i < 100; i++) mat[i][0] = '\0';
printf("Digite o nome do arquivo: ");
gets(str);
if ((fp = fopen(str,"r")) == NULL) {
puts("erro ao abrir o arquivo");
exit(1);
}
fgets (mat[i=0], 102, fp);
while (!feof(fp)) {
fgets (mat[++i], 102, fp);
}
fclose (fp);
for (i = 0; i < 100; i++)
if (mat[i][0]) printf ("%d - %s", i, mat[i]);
}
/*
Uso 102 no fgets assumindo que os 100 caracteres do enunciado se
referem a letras válidas, e a linha a ser armazenada pode ter mais
um, que é o \n.
*/
