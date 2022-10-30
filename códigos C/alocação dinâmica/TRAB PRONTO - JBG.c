
                                           ///CAÇA PALAVRAS/// - PI - PLANEJAMENTO INICIAL

/*Ler 20 palavras que o user digitar, de 5 a 10 letras cada uma = */ /// Matriz [20] por [10].
/*Dispor posição aleatória na matriz principal*/ ///Trocar lixo da matriz principal por '/0'.
/*Dispor posição aleatória na matriz principal*/ ///Definir com rand a posição inicial.
/*Dispor posição aleatória na matriz principal*/ ///Definir a rosa dos ventos 0 = N | 1 = NE | 2 = L | 3 = SE | 4 = S | 5 = SO | 6 = O | 7 = NO.
/*Cuidados na disposição aleatória*/ /// Não cair pra fora da matriz, só comparar com o que ta dentro///
/*Cuidados na disposição aleatória*/ /// Colocar nos parametros os indices máx// - nao sei pq!

///USAR SHORT INT///
///TIRAR RABISCOS DOIDO//
///RETIRAR VARIÁVEIS LIXO///



#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#define TMAT 16
#define PAL 5


void funcpal(char mat[TMAT][TMAT],char matpal[PAL][11]){        //COLOCAR PALAVRAS DENTRO DA MAT//

    int i, j;                                             //SHORT INT = 16 BITS = PODIA USAR CHAR, MAS ASSIM GASTO MENOS Q O INT E N ME ENROLO//
    int i1,j1,dir,c,cont,tpal;
    i1=j1=c=cont = 0;

    for( ;cont < PAL; ){
    //cont = 10;      //teste//
    i = rand() % 16;                                           // SORTEAR POSIÇÃO ALEATÓRIA |LINHA| //
    j = rand() % 16;                                           // SORTEAR POSIÇÃO ALEÁTORIA |COLUNA| //
    dir = rand() % 8;
    for(tpal = 0; matpal[i1][tpal]; tpal++);                   // MINHA STRLEN QUE É MELHOR //

        if(dir == 0){       //NORTE//
            for(j1 = 0; matpal[i1][j1]; j1++,i--){
                if(mat[i][j] == '\0' && i >= 0  || mat[i][j] == matpal[i1][j1] && i >=0){
                    c++;            //CONTAR SE TEM POSIÇÕES VÁLIDAS NA DIREÇÃO QUE O RAND SORTEOU//
                }                   //JÁ PERMITO O CRUZAMENTO DE PALAVRAS//
            }
            //printf("%d\n" ,c);
            if(c == tpal){          //PALAVRA CABE NA POSIÇÃO//
                i +=tpal;
                //j1-=tpal;
                //printf("%d\n", i1);
                for(j1 = 0; matpal[i1][j1]; j1++,i--){
                    mat[i][j] = matpal[i1][j1];     //COLOCANDO PALAVRA NAS POSIÇÕES TESTADAS//
                    //printf("%c", matpal[i1][j1]);
                }
                i1++;                               //PASSAR PRA PROXIMA PALAVRA//
                cont++;                             //PALAVRA COLOCADA NA MATRIZ COM SUCESSO// INDICADOR DISSO//
            }
        }

         else if(dir == 1){       //NORDESTE//
            for(j1 = 0; matpal[i1][j1]; j1++,i--,j++){
                if(mat[i][j] == '\0' && i >=0 && j <=15 || mat[i][j] == matpal[i1][j1] && i >= 0 && j <= 15){
                    c++;
                }
            }
            if(c == tpal){
                i +=tpal;
                j -=tpal;
                //j1 -=tpal;
                for(j1 = 0; matpal[i1][j1]; j1++,i--,j++){
                    mat[i][j] = matpal[i1][j1];
                    //printf("%c\n", matpal[i1][j1]);
                }
                i1++;
                cont++;
            }
        }
        else if(dir == 2){      //LESTE//
            for(j1 = 0; matpal[i1][j1]; j1++,j++){
                if(mat[i][j] == '\0' && j <=15 || mat[i][j] ==  matpal[i1][j1] && j <=15){
                    c++;
                }
            }
            if(c == tpal){
                j -=tpal;
                //j1 -=tpal;
                for(j1 = 0; matpal[i1][j1]; j1++,j++){
                    mat[i][j] = matpal[i1][j1];
                    //printf("%c\n", matpal[i1][j1]);
                }
                i1++;
                cont++;
            }
        }
        else if(dir == 3){      //SUDESTE//
            for(j1 = 0; matpal[i1][j1]; j1++,i++,j++){
                if(mat[i][j] == '\0' && j <=15 && i <=15 || mat[i][j] == matpal[i1][j1] && j <=15 && i <=15){
                    c++;
                }
            }
            //printf("%d\n", c);
            if(c == tpal){
                i -=tpal;
                j -=tpal;
                //j1 -=tpal;
                for(j1 = 0; matpal[i1][j1]; j1++,i++,j++){
                    mat[i][j] = matpal[i1][j1];
                    //printf("%c\n", matpal[i1][j1]);
                }
                i1++;
                cont++;


            }

        }
        else if(dir == 4){      //SUL//
            for(j1 = 0; matpal[i1][j1]; j1++,i++){
                if(mat[i][j] == '\0' && i <= 15 || mat[i][j] == matpal[i1][j1] && i <= 15){
                    c++;
                }
            }
            if(c == tpal){
                i -=tpal;
                //j1 -=tpal;
                for(j1 = 0; matpal[i1][j1]; j1++,i++){
                    mat[i][j] = matpal[i1][j1];
                    //printf("%c\n", matpal[i1][j1]);
                }
                i1++;
                cont++;
            }
        }
        else if(dir = 5){       //SUDOESTE//
            for(j1 = 0; matpal[i1][j1]; j1++,i++,j--){
                if(mat[i][j] == '\0' && i <=15 && j >= 0 || mat[i][j] == matpal[i1][j1] && i <=15 && j >= 0){
                    c++;
                }
            }
            //printf("%d\n", c);
            if(c == tpal){
                i -=tpal;
                j +=tpal;
                //j1 -=tpal;
                for(j1 = 0 ; matpal[i1][j1]; j1++,i++,j--){
                    mat[i][j] = matpal[i1][j1];
                    //printf("%c\n", matpal[i1][j1]);
                }
                i1++;
                cont++;
            }
        }
        else if(dir = 6){       //OESTE//
            for(j1 = 0; matpal[i1][j1]; j1++,j--){
                if(mat[i][j] == '\0' && j >= 0 || mat[i][j] == matpal[i1][j1] && j >= 0){
                    c++;
                }
            }
            //printf("%d\n", c);
            if(c == tpal){
                j +=tpal;
                //j1 -=tpal;
                for(j1 = 0; matpal[i1][j1]; j1++,j--){
                    mat[i][j] = matpal[i1][j1];
                    //printf("%c\n", matpal[i1][j1]);
                }
                i1++;
                cont++;
            }

        }
        else if(dir =7){        //NOROESTE//
            for(j1 = 0; matpal[i1][j1]; j1++,i--,j--){
                if(mat[i][j] == '\0' && i >=0 && j >=0 || mat[i][j] == matpal[i1][j1] && i >=0 && j >=0){
                    c++;
                }
            }
            //printf("%d\n", c);
            if(c == tpal){
                i +=tpal;
                j +=tpal;
                //ja -=tpal;
                for(j1 = 0; matpal[i1][j1]; j1++,i--,j--){
                    mat[i][j] = matpal[i1][j1];
                    //printf("%c", matpal[i1][j1]);
                }
                i1++;
                cont++;
            }
        }
c = 0;
}
}

void funcale(char mat[TMAT][TMAT]){

    int letale = 26,i, j;
    char a,b,c, letra;
    i = j = 0;

    for(i = 0; i < TMAT; i++){
        for(j = 0; j <TMAT; j++){
            //printf("%c", mat[i][j]);
            if(mat[i][j] == '\0'){  //SE TIVER LIXO NA MATRIZ A FUNÇÃO RAND GERA LETRA//
                //mat[i][j] = (rand()%letale)+65;
                if(j-1 >=0)         //COMPARAÇÃO PARA GARANTIR Q A LETRA AO OESTE NÃO SE REPITA 3 VEZES NA HORIZONTAL
                    a = mat[i][j-1];
                if(i-1 >=0 && j-1 >=0) //COMPARAÇÃO PARA GARANTIR Q A LETRA AO NOROESTE NÃO SE REPITA 3 VEZES NA DIAGONAL
                    b = mat[i-1][j-1];
                if(i-1 >=0)         //COMPARAÇÃO PARA GARANTIR Q A LETRA AO NOROESTE NÃO SE REPITA 3 VEZES NA VERTICAL
                    c = mat[i-1][j];
                letra= (rand()%letale)+65; //GERO UMA LETRA
                while(letale == a || letale == b || letale == c){
                    letra = (rand()%letale)+65;         //LETRA FOI IGUAL A UMA DAS POSIÇÕES ANTERIORES, EU TROCO.
                }
                mat[i][j] = letra;                      //MATRIZ RECEBE A LETRA.

            }
        }
    }
}

                                        ///NÃO FUNCIONOU MAS RENDEU UMAS IDÉIAS///

                /*if(j-1 >=0 && mat[i][j-1] == mat[i][j]){
                    letale--;
                    mat[i][j] = rand()%letale+65;
                    aux = mat[i][j];
                    if(aux>= mat[i][j])
                        mat[i][j]= aux+1;

                    else
                        mat[i][j] = aux;

                }
                else if(i-1 >=0 && j+15 == 15  && mat[i-1][j+15] == mat[i][j]){
                    letale--;
                    mat[i][j] = rand()%letale+65;
                    aux = mat[i][j];
                    if(aux>= mat[i][j])
                        mat[i][j] = aux+1;
                    else
                        mat[i][j] = aux;
                }
            }*/

    /*for(i = 0; i < TMAT; i++){
        for(j = 0; j <TMAT; j++){
            if(i-1 >=0 && i+1 <=15 && mat[i-1][j] == mat[i+1][j] && mat[i-1][j] == mat[i][j]){
                letale--;
                aux = rand()%letale+65;
                if(aux >= mat[i][j]){
                    aux++;
                    mat[i][j] = aux;
                }
                else{
                    mat[i][j] = aux;
                }
                letale = 26;
            }
            if(j-1 >=0 && j+1 <=15 && mat[i][j-1] == mat[i][j+1] && mat[i][j-1] == mat[i][j]){
                letale--;
                aux = rand()%letale+65;
                if(aux >= mat[i][j]){
                    aux++;
                    mat[i][j] = aux;
                }
                 else{
                    mat[i][j] = aux;
                }
                letale = 26;
            }
            if(i+1 <=15 && j-1 >=0 && i-1 >= 0 && j+1 <=15 && mat[i+1][j-1] == mat[i-1][j+1]){
                letale--;
                aux = rand()%letale+65;
                if(aux >= mat[i][j]){
                    aux++;
                    mat[i][j] = aux;
                }
                 else{
                    mat[i][j] = aux;
                }
                letale = 26;
            }
            if(i-1 >=0 && j-1 >= 0 && i+1 <=15 && j+1 <=15 && mat[i-1][j-1] == mat[i+1][j+1] ){
                letale--;
                aux = rand()%letale+65;
                if(aux >= mat[i][j]){
                    aux++;
                mat[i][j] = aux;
                }
                 else{
                    mat[i][j] = aux;
                }
                letale = 26;
            }
        }
    }*/


    /*for(i = 0; i <TMAT; i++){
        for(j = 0; j <TMAT; j++){
            letale = 26;
            if(i-1 >=0 && i+1 <=15 && mat[i-1][j] == mat[i+1][j]){
                letra1 = mat[i-1][j];  //C = 67
                letale--;
                i1++;
            }
            if(j-1 >=0 && j+1 <=15 && mat[i][j-1] == mat[i][j+1]){
                letra2 = mat[i][j-1];
                letale--;
                i1++;
            }
            if(i+1 <=15 && j-1 >=0 && i-1 >= 0 && j+1 <=15 && mat[i+1][j-1] == mat[i-1][j+1]){
                letra3 = mat[i+1][j-1];
                letale--;
                i1++;
            }
            if(i-1 >=0 && j-1 >= 0 && i+1 <=15 && j+1 <=15 && mat[i-1][j-1] == mat[i+1][j+1] ){
                letra4 = mat[i-1][j-1];
                letale--;
                i1++;
            }
            printf("\nQUANTO VALE O LETALE %d\n", letale);

            for( j1 = 0; j1 < i1; j1++){
                if(letra1 >= letra2 && letra1 >= letra3 && letra1 >= letra4){           //66 67 70 78
                    aux = letra1;
                    letra1 = '!';
                }
                else if(letra2 >= letra1 && letra2 >= letra3 && letra2 >= letra4){
                    aux = letra2;
                    letra2 = '!';
                }
                else if(letra3 >= letra1 && letra3 >= letra2 && letra3 >= letra4){
                    aux = letra3;   // 78 P
                    letra3 = '!';
                }
                else if(letra4 >= letra1 && letra4 >= letra2 && letra4 >= letra3){
                    aux = letra4;
                    letra4 = '!';
                }
                l1 = l2;
                l2 = l3;
                l3 = l4;
                l4 = aux;       //78
            }
                if(l1 == '!')
                    l1 = '~';
                if(l2 == '!')
                    l2 = '~';
                if(l3 == '!')
                    l3 = '~';
                if(l4 == '!')
                    l4 = '~';                                                                    // 78 67 70 66
                letale = (rand()%letale)+65;
                if(letale >=  l4)
                    letale++;
                if(letale >=  l3)
                    letale++;
                if(letale >=  l2)
                    letale++;
                if(letale >=  l1)
                    letale++;
                printf("\n L4 OQ TEM %d \n", l4);


                if(mat[i][j] == '\0')
                    mat[i][j] = letale;
            }
            i1 = 0;

        }*/

main(){

setlocale(LC_ALL, "portuguese");
    char  mat[TMAT][TMAT], matpal[PAL][11];   //MATRIZ DO JOGO//MATRIZ DAS PALAVRAS//
    int i = 0,j = 0;
    int i1 = 0, j1 = 0, i2 = 0, j2 = 0;
    int a = 0, dir, cont= 0,tpal, ant = 0;


    srand((unsigned)time(NULL));            //INICIALIZAR A SEMENTE//

    for(i = 0; i < TMAT; i++){
        for( j = 0; j <TMAT; j++){          //ADD ELEMENTO CONHECIDO'\0';
            mat[i][j] = '\0';
        }
    }
    printf("\n\nALUNO: |JARDEL GONÇALVES|\n\n");
    printf("\n|BEM VINDO AO CAÇA PALAVRA|\n");         //BOAS-VINDAS//
    printf("\nDIGITE 20 PALAVRAS, TODAS ENTRE 5 E 10 CARACTERES: \n");
    for(i = 0; i < PAL; ){
        scanf("%s", matpal[i]);
                                                                        //LER STRING DO USER//
        for(tpal = 0;matpal[i][tpal]; tpal++);
        //printf("\n%d\n", tpal);
        if(tpal >= 5 && tpal <= 10)
            i++;
        else
            printf("\nPOR FAVOR, PALAVRAS ENTRE 5 E 10 CARACTERES!!!\n");    //USER DIGITAR AS PALAVRAS CORRETAMENTE// N INCREMENTO//

    }
    printf("\n");
    printf("PALAVRAS A SEREM ENCONTRADAS: \n");
    for(i1 = 0; i1 < 5; i1++){                                                  //MOSTRAR PALAVRAS DO USER NA TELA, QUE ELE DEVE ACHAR//
        printf("%s\n", matpal[i1]);
    }
    printf("\n");

    funcpal(mat, matpal);                                                   // CHAMAR FUNÇÃO Q COLOCA NA GRADE AS PALAVRAS//
    funcale(mat);
    /*for(i = 0; i < PAL; i++){
        printf("\n%s\n",matpal[i]);         //teste
    }*/
                                                              // CHAMAR FUNÇÃO Q GERA LETRAS ALEATÓRIAS//
    while(a < PAL){
        for(i = 0; i < TMAT; i++){
            for(j = 0; j < TMAT; j++){
                printf("   %c   ", mat[i][j]);                              // MOSTRAR NA TELA A MATRIZ SEMPRE Q ELE JOGAR UMA RODADA//
                }
                printf("\n\n");
            }
        /*for(i = 0; i < PAL; i++){
        printf("\n%s\n",matpal[i]);         //teste
        }*/
        printf("Digite a posição inicial - |LINHA E COLUNA|(RESPECTIVAMENTE):\n");
        scanf("%d", &i);                                                            // DIGITAR LINHA E COLUNA
        scanf("%d", &j);
        printf("Considere |0 = NORTE| - |1 = NORDESTE| - |2 = LESTE| - |3 = SUDESTE| -\n|4 = SUL| - |5 = SUDOESTE| - |6 = OESTE| - |7 = NOROESTE|: ");
        scanf("%d", &dir);
        //tpal = 0;
        if(dir == 0){   //NORTE//
            for(i1 = 0; i1 < PAL; i1++){                        //NUMERO DE PALAVRAS//
                for(tpal = 0; matpal[i1][tpal]; tpal++);        //STRLEN MINHA//
                for( ;i >= 0 && mat[i][j] == matpal[i1][j1]; j1++,i--){     //cavalo    //5//
                    cont++;                                     //A CADA LETRA IGUAL, CONT AUMENTA//
                }
                //printf("\n\nCONTADOR %d\n\n",cont);
                if(cont == tpal){                               // SE CONT FOR IGUAL AO TAMANHO DA PALAVRA O a aumenta(menos 1 palavra)//
                    a++;
                    printf("VOCE ACERTOU\n");                   //AVISO Q ELE ACERTOU//
                }
                i +=cont;                                       //REINICIO A POSIÇÃO DA PALAVRA NA MATRIZ, PRA CASO A PALAVRA A SER PROCURADA SEJA FINAL E COM INICIO SEMELHANTE A ANTERIOR//
                j1 -=cont;                                      //REINICIO A POSIÇÃO INICIAL DA LEITURA DA PALAVRA//
                cont = 0;                                       //REDEFINO O CONTADOR, ELE Q ME GARENTE SE AS PALAVRAS SÃO IGUAIS
            }
            if(a == ant){                                       //MEU a TAMBÉM ATUA COMO UMA ESPÉCIE DE FLAG, JÁ QUE DEIXO O DA RODADA PASSADA NO anterior
                printf("VOCE ERROU\n");                         //SE O a NÃO AUMENTAR, SIGNIFICA QUE O USER ERROU//
            }
        }
        else if(dir == 1){ //NORDESTE//
            for(i1 = 0; i1 < PAL; i1++){
                for(tpal = 0; matpal[i1][tpal]; tpal++);
                for( ; i >=0 && j <=15 && mat[i][j] == matpal[i1][j1]; j1++, i--,j++){
                    cont++;
                }
                //printf("\n\nCONTADOR %d\n\n",cont);
                if(cont == tpal){
                    a++;
                    printf("VOCE ACERTOU\n");
                }
                i +=cont;
                j -=cont;
                j1 -=cont;
                cont = 0;
            }
            if(a == ant)
                printf("VOCE ERROU\n");

        }
        else if(dir == 2){  //LESTE//
            for(i1 = 0; i1 <PAL; i1++){
                for(tpal = 0; matpal[i1][tpal]; tpal++);
                for( ;j <=15 && mat[i][j] == matpal[i1][j1]; j1++, j++){
                    cont++;
                }
                //printf("\n\nCONTADOR %d\n\n",cont);
                if(cont == tpal){
                    a++;
                    printf("VOCE ACERTOU\n");
                }
                j -=cont;
                j1 -=cont;
                cont = 0;

            }
            if(a == ant)
                printf("VOCE ERROU\n");

        }
        else if(dir == 3){  //SUDESTE//
            for(i1 = 0; i1 < PAL; i1++){         //i1++// //
                //printf("\n%d\n", i1);
                //printf("\n%d\n", tpal);
                for(tpal = 0; matpal[i1][tpal]; tpal++);    //tpal 8//
                for( ;i <= 15 && j <=15 && mat[i][j] == matpal[i1][j1]; j1++,i++,j++){
                    cont++;
                }
                //printf("\n\nCONTADOR %d\n\n",cont);
                if(cont == tpal){
                    a++;
                    printf("VOCE ACERTOU\n");
                }
                i -=cont;
                j -=cont;
                j1 -=cont;
                cont = 0;
            }
            if(a == ant)
                printf("VOCE ERROU\n");
        }
        else if(dir == 4){  //SUL//
            for(i1 = 0; i1 <PAL; i1++){
                for(tpal = 0; matpal[i1][tpal]; tpal++);
                for( ;i <= 15 && mat[i][j] == matpal[i1][j1]; j1++,i++){
                    cont++;
                }
                //printf("\n\nCONTADOR %d\n\n",cont);
                if(cont == tpal){
                    a++;
                    printf("VOCE ACERTOU\n");
                }
                i -=cont;
                j1-=cont;
                cont = 0;
            }
            if(a == ant)
                printf("VOCE ERROU\n");
        }
        else if(dir == 5){  //SUDOESTE//
            for(i1 = 0; i1 <PAL; i1++){
                for(tpal = 0; matpal[i1][tpal]; tpal++);
                for( ;i <= 15 && j >= 0 && mat[i][j] == matpal[i1][j1]; j1++,i++,j--){
                    cont++;
                }
                //printf("\n\nCONTADOR %d\n\n",cont);
                if(cont == tpal){
                    a++;
                    printf("VOCE ACERTOU\n");
                }
                i -=cont;
                j +=cont;
                j1 -=cont;
                cont = 0;
            }
            if(a == ant)
                printf("VOCE ERROU\n");
        }
        else if(dir == 6){  //OESTE//
            for(i1 = 0; i1 <PAL; i1++){
                for(tpal = 0; matpal[i1][tpal]; tpal++);
                for( ;j >= 0 && mat[i][j] == matpal[i1][j1]; j1++,j--){
                    cont++;
                }
                //printf("\n\nCONTADOR %d\n\n",cont);
                if(cont == tpal){
                    a++;
                    printf("VOCE ACERTOU\n");
                }
                j +=cont;
                j1 -=cont;
                cont = 0;
            }
            if(a == ant)
                printf("VOCE ERROU\n");
        }
        else if(dir == 7){  //NOROESTE//
            for(i1 = 0; i1 <PAL; i1++){
                for(tpal = 0; matpal[i1][tpal]; tpal++);
                for( ; i >= 0 && j >=0 && mat[i][j] == matpal[i1][j1]; j1++,i--,j--){
                    cont++;
                }
                //printf("\n\nCONTADOR %d\n\n",cont);
                if(cont == tpal){
                    a++;
                    printf("VOCE ACERTOU\n");
                }
                i +=cont;
                j +=cont;
                j1 -= cont;
                cont = 0;
            }
            if(a == ant)
                printf("VOCE ERROU\n");
        }
        ant = a;                        //O ANTERIOR É O a DA PASSADA//
        cont = 0;
        //tpal = 0;
    }

    printf("\nMEUS PARABENS, VOCE ACHOU TODAS AS PALAVRAS!!!!!!!! \n");
}
