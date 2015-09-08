#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 100

typedef struct{
    int v[MAX];
    int n;
}Heap;

void inicializa(Heap *h){
    h->n = 0;
}

int fe(int i){
    return (i*2)+1;
}

int fd(int i){
    return (i*2)+2;
}

int pai(int i){
    return (i-1)/2;
}

int Up(Heap *h){
//    printf("%d/2 -1 = %d\n", h->n,(h->n/2)-1);
    return (h->n/2)-1;
}

void swap(Heap *h, int i1, int i2){
    int aux = h->v[i1];
    h->v[i1] = h->v[i2];
    h->v[i2] = aux;
}

void Peneirar(Heap *h, int i){

    if(i > Up(h))
        return;

    int mf = fe(i);
    if(fd(i)<h->n && h->v[fd(i)] > h->v[mf])
        mf = fd(i);

    if(h->v[i] < h->v[mf]){
//        printf("%d %d\n", h->v[i], h->v[mf]);
        swap(h,i, mf);
        Peneirar(h,mf);
    }
}

void constroiHeap(Heap *h){
    int i=0;
//    printf("UP - %d\n", Up(h));
    for(i = Up(h); i >= 0; i--)
        Peneirar(h,i);
}

int inserirHeap(Heap *h, int prior){
    if(h->n == MAX)
        return 0;
    h->v[h->n] = prior;
    h->n+=1;
//    printf("constroi %d\n", h->n);
    constroiHeap(h);
    return 1;
}

int removerHeap(Heap *h){
    if(h->n <= 0)
        return 0;
    swap(h,0,h->n-1);
    h->n--;
    Peneirar(h,0);
    return 1;
}

void alterarHeap(Heap *h, int el, int nel){
    assert(el<h->n);
    el = nel;
    constroiHeap(h);
}

void destroiHeap(Heap *h){
    h->n=0;
}

int main()
{
    Heap h;
//    h.v[0] = 3;
//    h.v[1] = 8;
//    h.v[2] = 1;
//    h.v[3] = 7;
//    h.v[4] = 3;
//    h.v[5] = 9;
//    h.v[6] = 15;
//    h.v[7] = 7;
//    h.v[8] = 1;
//    h.v[9] = 2;
//    h.n = 10;
//    constroiHeap(&h);

//    inicializa(&h);
//    inserirHeap(&h,3);
//    inserirHeap(&h,8);
//    inserirHeap(&h,1);
//    inserirHeap(&h,7);
//    inserirHeap(&h,3);
//    inserirHeap(&h,9);
//    inserirHeap(&h,15);
//    inserirHeap(&h,7);
//    inserirHeap(&h,1);
//    inserirHeap(&h,2);

//       inicializa(&h);
//       inserirHeap(&h,20);
//       inserirHeap(&h,3);
//       inserirHeap(&h,15);
//       inserirHeap(&h,3);
//       inserirHeap(&h,10);
//       inserirHeap(&h,20);

       printf("%d\n", removerHeap(&h));
//       removerHeap(&h);

    int i=0;
    for(i = 0; i<h.n; i ++)
        printf("%d ", h.v[i]);


    return 0;
}

