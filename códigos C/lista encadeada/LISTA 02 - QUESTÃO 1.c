/*1. Escreva uma função que receba como parâmetro um ponteiro para o primeiro elemento de
uma lista encadeada e retorne esta lista invertida. O primeiro elemento deve passar a ser o
último, o segundo passa a ser o penúltimo, e assim por diante.*/

#include<stdio.h>
#include<stdlib.h>

struct item {
    int id;
    struct item *prox;
};

///FUNÇÃO PARA INSERIR NO INÍCIO DA LISTA ENCADEADA, ALOCANDO DINAMICAMENTE///
struct item *insertINI(struct item *pini, int n){
    struct item *paux;      //ponteiro aux, o novo elemento a ser colocado na ordem pedida
    paux = (struct item *) malloc (sizeof(struct item));    //alocação de memória para a nova struct

    paux->id= n;
    paux->prox= pini;
    return paux;
}

///FUNÇÃO PARA MOSTRAR LISTA ENCADEADA NA TELA///
void mostrar(struct item *pini){
    while(pini){                 //Enquanto "p" for válido, mostra os nomes,
        printf("%d ", pini->id);//pois se fosse "p->prox" não mostraria o último, pois testaria no final e n entraria no laço dnv
        pini = pini->prox;
    }
    printf("\n");
}

///FUNÇÃO PARA MATAR LISTA ENCADEADA///
void killITEM(struct item *pini){
    struct item *paux;

    while(pini){                //Crio uma variável aux para ponteiro inicial, assim eu aponto para o msm lugar q o ponteiro inicial e
    paux = pini;                //avanço com o ponteiro inicial para o próximo da lista, depois do free no ponteiro auxiliar q contem o end anterior
    pini = pini->prox;
    free(paux);
    }
}

///FUNÇÃO PARA INVERTER LISTA ENCADEADA///
struct item *invertLIST(struct item *p){
    struct item *paux, *po;
    paux= NULL;
    po= p;
    while(p){
        p= p->prox;
        po->prox= paux;
        paux= po;
        po= p;
    }
    return paux;

}

main(){

    struct item *p1, *p2;
    int n;

    p1 = NULL;

    puts("Digite um numero referente ao id do item/user ou '-1' para sair: ");
    scanf("%d", &n);
    fflush(stdin);

    while(n != -1){
       p1= insertINI(p1, n);
       fflush(stdin);
       puts("Digite um número referente ao id do item/user ou '-1' para sair: ");
       scanf("%d", &n);
    }

    mostrar(p1);

    p1= invertLIST(p1);

    mostrar(p1);

    killITEM(p1);
}
