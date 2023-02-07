/*3. Escreva uma função que receba como parâmetro um ponteiro apontando para a raiz de uma árvore binária e
retorne um ponteiro para o menor elemento da árvore. Se houver mais de uma ocorrência do menor valor, retorne
qualquer um.*/

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

///FUNÇÃO PARA RETORNAR UM PONTEIRO PARA O MENOR VALOR DA ÁRVORE///

struct elemento *menorv(struct elemento *arv){
    struct elemento *aux;

    if(!arv)
        return NULL;

    aux = menorv(arv->fesq);
    aux = menorv(arv->fdir);

    if(arv->fesq && arv->fdir){
        if(arv->valor < arv->fesq->valor && arv->valor < arv->fdir->valor /*&& arv->valor < aux->valor*/)
            return arv;
        if(arv->fesq->valor < arv->valor && arv->fesq->valor < arv->fdir->valor /*&& arv->valor < aux->valor*/)
            return arv->fesq;
        if(arv->fdir->valor < arv->valor && arv->fdir->valor < arv->fesq->valor && arv->valor < aux->valor)
            return arv->fdir;
    }

    if(arv->fesq){
        if(arv->valor < arv->fesq->valor)
            return arv;
        if(arv->fesq->valor < arv->valor)
            return arv->fesq;
    }

    if(arv->fdir){
        if(arv->valor < arv->fdir->valor)
            return arv;
        if(arv->fdir->valor < arv->valor)
            return arv->fdir;
    }
    printf("\n--%d--\n", arv->valor);
    return arv;

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
    int armazenada[16] = { 0, 10, 2, 3, 47, 5, 6, 7, 58, 9, 10, 11, 12, 103, -1, 15 };
    struct elemento *aux, *raiz = NULL;

    printf("\n\n");
    raiz = alocar(1, armazenada);

    printf("\n\n");
    posfixado(raiz);
    printf("\n\n");

    aux = menorv(raiz);
    printf("O elemento de menor valor na arvore e: %d\n", aux->valor);
    eliminar(raiz);
    return 0;
}
