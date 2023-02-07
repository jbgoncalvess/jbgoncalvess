/*5. Construa uma função que receba como parâmetro um ponteiro apontando para a raiz de uma árvore binária de
pesquisa e retorne um valor indicando verdadeiro se a árvore existir e se os nós de maior e menor valor da árvore
estiverem no mesmo nível.*/

#include<stdio.h>
#include<stdlib.h>

struct elemento{
    int valor;
    struct elemento *fesq;
    struct elemento *fdir;
};

///MOSTRO OS VALORES COM IDENTAÇÃO PARA A DIREITA///

void mostrar1(int nivel, struct elemento *arv) {
  int i;
  for(i = 0; i < nivel; i++)
    printf("   ");
  if (arv) {
    printf("%d\n", arv->valor);
    mostrar1(nivel+1, arv->fesq);
    mostrar1(nivel+1, arv->fdir);
    }
  else
    printf("-\n");
}

///FUNÇÃO PARA INSERIR ELEMENTOS NA ABP, RECURSIVAMENTE, VOU INDO PARA O ESPAÇO DO MENOR OU MAIOR VALOR, ATÉ CHEGAR NO NULL E ALOCAR O ELEMENTO///

struct elemento *inserirRec (int valor, struct elemento *arv) {
  if (!arv) {
    arv = (struct elemento *) malloc (sizeof(struct elemento));
    arv->valor = valor;
    arv->fdir = arv->fesq = NULL;
    return arv;
    }
  //else
  if (valor < arv->valor) {
    arv->fesq = inserirRec(valor, arv->fesq);
    }
  else {
    arv->fdir = inserirRec(valor, arv->fdir);
    }
  return arv;
}

///FUNÇÃO PARA INSERIR ELEMENTOS NA ABP, UTILIZANDO LAÇO DE REPETIÇÃO, SE CHEGAR NO NULL, ALOCAR E AVANÇAR, SAI DO LAÇO E ENDEREÇO IGUAIS SAI FORA///

struct elemento *inserir (int valor, struct elemento *arv) {
  struct elemento *novo, *ini;
  novo = (struct elemento *) malloc (sizeof(struct elemento));
  novo->valor = valor;
  novo->fdir = novo->fesq = NULL;
  if (!arv)
    return novo;
  ini = arv;
  while(arv != novo) {
    if (valor < arv->valor) {
      if (!arv->fesq)
        arv->fesq = novo;
      arv = arv->fesq;
      }
    else {
      if (!arv->fdir)
        arv->fdir = novo;
      arv = arv->fdir;
      }
    }
  return ini;
}

///FUNÇÃO PARA LOCALIZAR VALOR NA ARVÓRE, RETORNA UM PONTEIRO PARA O ELEMENTO COM O VALOR PEDIDO, SE RETORNAR NULL É Q NÃO TEM O VALOR///

struct elemento *localizar (int valor, struct elemento *arv) {
  if (!arv)
    return NULL;
  while(arv && arv->valor != valor) {
    if (valor < arv->valor) {
      arv = arv->fesq;
      }
    else {
      arv = arv->fdir;
      }
    }
  return arv;
}

///FUNÇÃO QUE RECEBE UM PONTEIRO PARA UMA ABP E RETORNA UM VALOR X SE A ABP TEM O MAIOR E MENOR VALOR NO MESMO NÍVEL///

int me_maN(struct elemento *arv){
    struct elemento *aux;
    int nivel;
    aux = arv;

    for(nivel = 0; arv; arv = arv->fesq, nivel++);
    for( ; aux; aux = aux->fdir, nivel--);

    if(nivel == 0)
        return 0;
    else
        return 1;
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
    struct elemento *aux, *raiz = NULL;

    raiz = inserir(60, raiz);
    raiz = inserir(40, raiz);
    raiz = inserir(10, raiz);
    raiz = inserir(3, raiz);
    raiz = inserirRec(15, raiz);
    raiz = inserirRec(51, raiz);
    raiz = inserirRec(70, raiz);
    raiz = inserir(80, raiz);
    raiz = inserir(71, raiz);
    raiz = inserir(72, raiz);
    raiz = inserir(111, raiz);
    raiz = inserir(121, raiz);
    raiz = inserir(-3, raiz);

    mostrar1(0, raiz);
    printf("\n\n\n\n");

    aux = localizar(111, raiz);
    if (aux)
    printf("Valor %d encontrado.\n", aux->valor);
    else
    printf("Valor 111 nao encontrado.\n");

    aux = localizar(72, raiz);
    if (aux)
    printf("Valor %d encontrado.\n", aux->valor);
    else
    printf("Valor 72 nao encontrado.\n");

    if(me_maN(raiz) == 0)
        puts("O maior e menor valor da arvore estao no mesmo nivel");
    else
        puts("O maior e menor valor da arvore NAO estao no mesmo nivel");

    eliminar(raiz);
    return 0;
}
