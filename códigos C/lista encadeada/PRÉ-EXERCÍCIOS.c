/*Criar lista encadeada inserindo elementos no início*/
/*Criar lista encadeada inserindo elementos no Final*/
/*Criar função para mostrar a lista encadeada*/
/*Criar função para eliminar a lista encadeada*/

#include<stdio.h>
#include<stdlib.h>

struct item {
    char nome;
    struct item *prox;
};

///FUNÇÃO PARA INSERIR NO INÍCIO DA LISTA ENCADEADA, ALOCANDO DINAMICAMENTE///
struct item *insertINI(struct item *pini, char l){
    struct item *paux;      //ponteiro aux, o novo elemento a ser colocado na ordem pedida
    paux = (struct item *) malloc (sizeof(struct item));    //alocação de memória para a nova struct

    paux->nome= l;
    paux->prox= pini;
    return paux;
}

///FUNÇÃO PARA INSERIR ELEMENTO NO FINAL DA LISTA ENCADEADA, ALOCANDO DINAMICAMENTE///
struct item *insertFIN(struct item *pini, char l){
    struct item *paux, *andar;
    paux = (struct item *) malloc (sizeof(struct item));
    andar = pini;

    paux->nome= l;
    paux->prox= NULL;

    if(!pini)
        return paux;

    for( ;andar->prox != NULL; andar= andar->prox);
    andar->prox= paux;
    return pini;
}

///FUNÇÃO PARA MOSTRAR LISTA ENCADEADA NA TELA///
void mostrar(struct item *pini){
    while(pini){                 //Enquanto "p" for válido, mostra os nomes,
        printf("%c", pini->nome);//pois se fosse "p->prox" não mostraria o último, pois testaria no final e n entraria no laço dnv
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

main(){
    char letra;
    struct item *p2;
    p2 = NULL;

    puts("Digite uma letra referente ao nome que deseja inserir na lista ou '@' para sair (INICIO): ");
    fflush(stdin);
    scanf("%c", &letra);

    while(letra != '@'){
        p2 = insertINI(p2, letra); //Passo letra que o usuário digitou mais o ponteiro com endereço inicial
        fflush(stdin);
        puts("Digite uma letra referente ao nome que deseja inserir na lista ou '@' para sair(INICIO): ");
        scanf("%c", &letra);
    }

    mostrar(p2);

    killITEM(p2);

    //---------------------------------------------------------------------------------------------------//
    //---------------------------------------------------------------------------------------------------//
    //---------------------------------------------------------------------------------------------------//

    p2 = NULL;

    puts("Digite uma letra referente ao nome que deseja inserir na lista ou '@' para sair (FINAL): ");
    fflush(stdin);
    scanf("%c", &letra);

    while(letra != '@'){
        p2 = insertFIN(p2, letra); //Passo letra que o usuário digitou mais o ponteiro com endereço inicial
        fflush(stdin);
        puts("Digite uma letra referente ao nome que deseja inserir na lista ou '@' para sair(FINAL): ");
        scanf("%c", &letra);
    }

    mostrar(p2);

    killITEM(p2);
}
