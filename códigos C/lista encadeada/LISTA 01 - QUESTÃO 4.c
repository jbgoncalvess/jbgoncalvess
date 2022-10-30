/*4. A atribuição Segunda = Primeira; pode ser considerada uma cópia de uma lista? Não, pois
embora haja dois ponteiros (Segunda e Primeira), a lista é uma só, ou seja, os dois ponteiros apontam
para a mesma lista, e modificações em uma se refletirão na outra. Escreva uma função que receba como
parâmetro um ponteiro para o primeiro elemento de uma lista e retorne um ponteiro para o primeiro
elemento de outra lista que é uma cópia da recebida como parâmetro. (duplique a lista).*/

#include<stdio.h>
#include<stdlib.h>

struct item {
    int id;
    struct item *prox;

};

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

///FUNÇÃO PARA INSERIR NO INÍCIO DA LISTA ENCADEADA, ALOCANDO DINAMICAMENTE///
struct item *insertINI(struct item *pini, int n){
    struct item *paux;      //ponteiro aux, o novo elemento a ser colocado na ordem pedida
    paux = (struct item *) malloc (sizeof(struct item));    //alocação de memória para a nova struct

    paux->id= n;
    paux->prox= pini;
    return paux;
}

///FUNÇÃO PARA DUPLICAR LISTA ENCADEADA///
struct item *duplicarLIST(struct item *p1){
    struct item *p2, *aux, *lf;
    aux = p2 = NULL;

    if(p1){                 //faço este if para garantir q o aux não entre NULL no laço, ai n tento acessar ponteiro nulo de struct aux->prox
        aux=p2;
        p2= (struct item *) malloc (sizeof(struct item));
        lf= p2;             //Guardo a posição inicial do novo ponteiro
        p2->id= p1->id;     //O primeiro id da segunda lista original vai para a nova lista
        p1= p1->prox;       //Lista original vai para o segundo elemento
    }

    while(p1){
        aux=p2;             //Garanti q o aux não será NULL dentro do laço
        p2= (struct item *) malloc(sizeof(struct item));
        p2->id= p1->id;     //O respectivo elemento da lista original vai para a nova lista
        aux->prox= p2;      //Aux está no anterior p2, ou seja, aux->prox = p2;
        p1= p1->prox;       //lista original avança
    }
    p2->prox= NULL;         //Tenho que garantir que no final da lista cópia terá um fim, portanto p2->prox= NULL
    return lf;              //Retorno ponteiro inicial
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

    p2 = duplicarLIST(p1);

    mostrar(p2);

    killITEM(p1);
    killITEM(p2);

}
