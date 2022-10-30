/*2. Escreva uma função que receba como parâmetro uma lista encadeada e elimine todos os elementos
que estejam repetidos, mantendo apenas a primeira ocorrência de cada, ou seja, de todos os elementos
que possuírem o mesmo conteúdo, deve ficar apenas o primeiro.*/

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

///FUNÇÃO PARA MATAR LISTA ENCADEADA///
void killITEM(struct item *pini){
    struct item *paux;

    while(pini){                //Crio uma variável aux para ponteiro inicial, assim eu aponto para o msm lugar q o ponteiro inicial e
    paux = pini;                //avanço com o ponteiro inicial para o próximo da lista, depois do free no ponteiro auxiliar q contem o end anterior
    pini = pini->prox;
    free(paux);
    }
}

///FUNÇÃO PARA MOSTRAR LISTA ENCADEADA NA TELA///
void mostrar(struct item *pini){
    while(pini){                 //Enquanto "p" for válido, mostra os nomes,
        printf("%c", pini->nome);//pois se fosse "p->prox" não mostraria o último, pois testaria no final e n entraria no laço dnv
        pini = pini->prox;
    }
    printf("\n");
}

///FUNÇÃO PARA MATAR IDS/NOMES IGUAIS, DEIXANDO SOMENTO O PRIMEIRO///
void killREP(struct item *px){
    struct item *aux, *pp, *ant;


    while(px){ // LAÇO DUPLO, UM PRA FIXAR EM UMA LETRA E O OUTRO PARA VARRER//
        ant= px;    // O endereço do valor anterior válido do auxiliar
        for(aux= px->prox; aux;  ){ // inicializo o segundo laço no próximo valor do encadeamento lógico
            if(px->nome == aux->nome){  //se for igual as letras do laço inicial e do segundario eu faço o free da letra a ser morta e avanço                                                                      // A A C A
                pp= aux;
                aux= aux->prox;
                free(pp);
                ant->prox= aux;
            }
            else{                       //caso as letras não sejam iguais, eu avanço minha anterior para a proxima letra válida e avanço a letra do segundo
                ant= aux;               //laço para a próxima passada
                aux= aux->prox;
            }
        }
        px= px->prox;                   //avanço o ponteiro do laço inicial para o próximo elemento lógico
    }
}

main(){
    char letra;
    struct item *p2;
    p2 = NULL;

    puts("Digite uma letra referente ao nome que deseja inserir na lista ou '@' para sair: ");
    fflush(stdin);
    scanf("%c", &letra);

    while(letra != '@'){
        p2 = insertINI(p2, letra); //Passo letra que o usuário digitou mais o ponteiro com endereço inicial
        fflush(stdin);
        puts("Digite uma letra referente ao nome que deseja inserir na lista ou '@' para sair: ");
        scanf("%c", &letra);
    }

    mostrar(p2);

    killREP(p2);

    mostrar(p2);

    killITEM(p2);
}
