/*1. Construa uma função em C que receba como parâmetro um ponteiro apontando para a raiz de uma árvore
 binária e retorne 1 se todo nó não folha tem valor maior que seu(s) filho(s), e 0 caso contrário.*/

#include<stdio.h>
#include<stdlib.h>

struct elemento{
    int valor;
    struct elemento *fesq;
    struct elemento *fdir;
};

///NESTE CASO, PRIMEIRO MOSTRA O ELEMENTO E DEPOIS AVANÇA, DANDO PRIORIDADE PARA OS "Fesq"///

void prefixado(struct elemento *arv) {
  if (arv) {
    printf("%d ", arv->valor);
    prefixado(arv->fesq);
    prefixado(arv->fdir);
    }
}

///NESTE CASO, PRIMEIRO MOSTRA O ELEMENTO MAIS DA ESQUERDA, DEPOIS SEU PAI, E POR FIM O SEU///
///ELEMENTO MAIS DA DIREITA///

void central(struct elemento *arv) {
  if (arv) {
    central(arv->fesq);
    printf("%d ", arv->valor);
    central(arv->fdir);
    }
}

///NESTE CASO, SEMPRE TENTA MOSTRAR OS NÓS FOLHAS, DANDO PRIORIDADE PARA AS FOLHAS DA///
///ESQUERDA, MOSTRA FILHO DA ESQUERDA, FILHO DA DIREITA E SEU PAI, ASSIM POR DIANTE///

void posfixado(struct elemento *arv) {
  if (arv) {
    posfixado(arv->fesq);
    posfixado(arv->fdir);
    printf("%d ", arv->valor);
    }
}

///ALOCA TODOS OS ELEMENTOS DO VETOR "Armazenada", SENDO QUE O "Fesq" É OS PARES E O "Fdir" SÃO OS ÍMPARES///
///QUALQUER VALOR NO VETOR QUE FOR "-1", SIGNIFICA QUE NÃO TEM ELEMENTO NAQUELA POSIÇÃO///

// int armazenada[16] = { 0, 10, 2, 3, 47, 5, 6, 7, 58, 9, 10, 11, 12, 103, -1, 15 };
struct elemento *alocar(int no, int armazenada[]) {
  struct elemento *novo;
  if (armazenada[no] != -1 && no < 16) {
    novo = (struct elemento *) malloc (sizeof(struct elemento));
    novo->valor = armazenada[no];
    novo->fesq = alocar(no*2, armazenada);
    novo->fdir = alocar(no*2+1, armazenada);
    return novo;
    }
  return NULL;
  }

///FUNÇÃO QUE RECEBE UM PONTEIRO PARA UMA ARVORE BINARIA E RETORNE 1 SE TODO NÓ NÃO FOLHA TEM VALOR MAIOR QUE SEUS FILHOS///
///E 0 CASO CONTRÁRIO///

int paiMfilho(struct elemento *arv){

    int f = 1;

    if(!arv)
        return 1;

    f = paiMfilho(arv->fesq);
    if(f == 0)
        return 0;
    f = paiMfilho(arv->fdir);
    if(f == 0)
        return 0;

    if(!arv->fesq && !arv->fdir)
        return 1;
    if((arv->fesq && arv->valor > arv->fesq->valor) && (arv->fdir && arv->valor > arv->fdir->valor))
        return 1;
    if((!arv->fesq && arv->valor > arv->fdir->valor) || (!arv->fdir && arv->valor > arv->fesq->valor))
        return 1;

    return 0;
}


///FUNÇÃO QUE ELIMINA A ÁRVORE, RETIRANDO OS FOLHAS INICIAMENTE, OBVIAMENTE///

void eliminar(struct elemento *arv) {
  if (!arv)
    return;
  eliminar(arv->fesq);
  eliminar(arv->fdir);
  free(arv);
  }

int main(){
    int armazenada[16] = { 0, 100, 50, 30, 40, 450, 25, 20, 30, 35, 1, 6, 12, -103, -1, -15 };
    struct elemento *aux, *raiz = NULL;
    int n;

    printf("\n\n");
    raiz = alocar(1, armazenada);

    prefixado(raiz);
    printf("\n\n");
    central(raiz);
    printf("\n\n");
    posfixado(raiz);
    printf("\n\n");

    if(paiMfilho(raiz) == 1)
        puts("Todo no nao folha tem seus filhos menores");
    else if(paiMfilho(raiz) == 0)
        puts("Todo no nao folha NAO tem seus filhos menores");

    eliminar(raiz);

return 0;
}
