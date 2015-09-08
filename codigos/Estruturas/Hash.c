#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct _no no;
struct _no{
    no *proximo;
    int chave;
    char valor[50];
};

typedef struct{
    no *primeiro;
    int qt;
}LDE;

void inicializaLDE(LDE*l){
    l->primeiro = NULL;
    l->qt = 0;
}

int  insereLDE(LDE *l, int chave, char valor[]){
    no *novo = malloc(sizeof(no));
    if(novo==NULL)
        return 0;
    novo->chave = chave;
    strcpy(novo->valor, valor);

    novo->proximo = l->primeiro;
    l->primeiro = novo;
    l->qt++;
    return 1;
}


no *buscaLDE(LDE *l, int chaveI){
    no *ptrAtual = l->primeiro;
    while(ptrAtual!=NULL && ptrAtual->chave!=chaveI)
        ptrAtual = ptrAtual->proximo;

    if(ptrAtual!=NULL)
        return ptrAtual;
    else
        return NULL;
}


int removeLDE(LDE *lista, int chave){
     no* ptrAtual = lista->primeiro;
     no *ptrAnterior = NULL;

     while(ptrAtual!=NULL && ptrAtual->chave!=chave){
         ptrAnterior = ptrAtual;
         ptrAtual = ptrAtual->proximo;
     }

     if(ptrAtual!=NULL && ptrAtual->chave == chave){
        if(ptrAnterior==NULL)
            lista->primeiro = ptrAtual->proximo;
        else
            ptrAnterior->proximo = ptrAtual->proximo;
        free(ptrAtual);
        lista->qt-=1;
    }
    return 1;
}

void destroiLDE(LDE *lista){
    no *ptrAtual = lista->primeiro;
    no *aux = NULL;

    while(ptrAtual!=NULL){
        aux = ptrAtual->proximo;
        free(ptrAtual);
        ptrAtual = aux;
    }
    inicializaLDE(lista);
}

void imprimeLDE(const LDE l){
    no *ptrAtual = l.primeiro;
    if(ptrAtual==NULL)
        printf("%c",178);
    while(ptrAtual!=NULL){
        printf("%s ",ptrAtual->valor );
        ptrAtual = ptrAtual->proximo;
    }
    printf("\n\n");
}

typedef struct{
    LDE *v; //hash de encadeamento externo(colisao)
    int tamanho;
}Hash;

Hash* inicializa(int tamanho){
    Hash *h = malloc(sizeof(Hash));
    h->tamanho = tamanho;
    h->v = malloc(sizeof(LDE)* tamanho);

    int i=0;
    for(i=0;i<tamanho;i++)
        inicializaLDE(&h->v[i]);
    return h;
}

void destroiHash(Hash*h){
    int i=0;
    for(i=0;i<h->tamanho;i++)
        destroiLDE(&h->v[i]);
    free(h->v);
    free(h);
}

//metodo da divisao
int fh(Hash *h, int chave){
    return chave%(h->tamanho);
}

void insereHash(Hash *h, int chave, char *valor){
    int indice = fh(h,chave);
    insereLDE(&h->v[indice],chave, valor);
}

no* buscaHash(Hash *h,int chave){
    int indice = fh(h,chave);
    return buscaLDE(&h->v[indice], chave);
}

void removeHash(Hash *h, int chave){
    int indice = fh(h,chave);
    removeLDE(&h->v[indice], chave);
}

void imprimeHash(const Hash h){
    int i=0;
    for(int i=0;i<h.tamanho;i++){
        printf("%d ", i);
        imprimeLDE(h.v[i]);
    }
}

int main(void)
{
    Hash *h = inicializa(10);

    insereHash(h,100,"hello");
    insereHash(h,10,"hello2");
    insereHash(h,18,"world");
    insereHash(h,16,"word");
    insereHash(h,21,"hey");
    insereHash(h,2,"hi");
    insereHash(h,19,"bye");
    insereHash(h,94,"horse");

//    no *p =  buscaHash(h,100);
//    printf("%s\n", p->valor);

    imprimeHash(*h);
    printf("------------------\n");
    removeHash(h, 10);
    imprimeHash(*h);

    destroiHash(h);

    return 0;
}

