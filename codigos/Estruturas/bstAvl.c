#include <stdlib.h>
#include <assert.h>

typedef struct _no No;
struct _no{
    No *pai, *esquerda, *direita;
    int valor;
};

typedef struct{
    No *raiz;
	int tamanho;
}Arvore;

No **ptrDoPai(Arvore *a, No *p){
    if(a->raiz == p)
        return &(a->raiz);
    else{
        if(p->pai->direita == p)
            return &(p->pai->direita);
        else
            return &(p->pai->esquerda);
    }
}

void constroiBST(Arvore *a) {
	a->raiz = NULL;
	a->tamanho = 0;
}

void destroiBST_VISIT(No *p) {
	if (p == NULL)
		return;
	destroiBST_VISIT(p->esquerda);
	destroiBST_VISIT(p->direita);
	free(p);
}

void destroiBST(Arvore *a) {
	destroiBST_VISIT(a->raiz);
}

void atualizaPai(No *f, No *p) {
	if (f != NULL)
		f->pai = p;
}

void rotacionaEsquerda(Arvore *a, No *x) {
	assert(x != NULL && x->direita != NULL); 
	
	No *y = x->direita;

	*ptrDoPai(a, x) = y;
	x->direita = y->esquerda;
	y->esquerda = x;

	atualizaPai(y, x->pai);
	atualizaPai(x, y);
	atualizaPai(x->direita, x);
}

void rotacionaDireita(Arvore *a, No *x) {
	assert(x != NULL && x->esquerda != NULL); 
	
	No *y = x->esquerda;

	*ptrDoPai(a, x) = y;
	x->esquerda = y->direita;
	y->direita = x;

	atualizaPai(y, x->pai);
	atualizaPai(x, y);
	atualizaPai(x->esquerda, x);
}

int altura(No *p) {
	if (p == NULL)
		return -1;

	int e, d;
	e = altura(p->esquerda);
	d = altura(p->direita);

	return ((e > d) ? e : d) + 1;
}

int fatorBalanceamento(No *p) {
	if (p == NULL)
		return 0;
	return altura(p->direita) - altura(p->esquerda);
}

void rotaciona(Arvore *a, No *p, int f) {
	if (f > 0)
		rotacionaEsquerda(a, p);
	else
		rotacionaDireita(a, p);
}

void balanceia(Arvore *a, No *p) {
	No *pA;
	int f = 0, fA = 0;
	while (p != NULL && f >= -1 && f <= 1) {
		pA = p;
		fA = f;
		p = p->pai;
		f = fatorBalanceamento(p);
	}

	if (p == NULL) // Balanceada
		return;
	else {
		if (f*fA < 0)
			rotaciona(a, pA, fA);
		rotaciona(a, p, f);
	}
}

char insereBST(Arvore *a, int chave) {
	No *p = a->raiz, *p2 = NULL;
	while (p != NULL) {
		p2 = p;
		if (chave < p->valor)
			p = p->esquerda;
		else if (p->valor < chave)
			p = p->direita;
		else
			return 0;
	}

	No *n = (No *)malloc(sizeof(No));
	n->valor = chave;
	n->direita = NULL;
	n->esquerda = NULL;
	n->pai = p2;

	if (p2 == NULL) // nova raiz
		a->raiz = n;
	else if (chave < p2->valor)
		p2->esquerda = n;
	else
		p2->direita = n;

	a->tamanho++;

	balanceia(a, n);

	return 1;
}

No *buscaBST(Arvore *a, int chave) {
    No *p = a->raiz;
    while(p != NULL) {
        if(chave < p->valor)
            p = p->esquerda;
        else if(p->valor < chave)
            p = p->direita;
        else
            return p;
    }
    return NULL;
}

void removeBST_VISIT(Arvore *a, No *r) {
	if (r->direita == NULL) {
		*ptrDoPai(a, r) = r->esquerda;
		if (r->esquerda != NULL)
			r->esquerda->pai = r->pai;
		balanceia(a, r->pai);
		free(r);
	}
	else{
		No *p;
		for (p = r->direita; p->esquerda != NULL; p = p->esquerda);
		r->valor = p->valor;
		removeBST_VISIT(a, p);
	}
}

char removeBST(Arvore *a, int chave) {
    No *r = buscaBST(a, chave);
	if(r == NULL)
        return 0;

	removeBST_VISIT(a, r);

	a->tamanho--;
    return 1;
}

void prefixoBST(No *p, int *v) {
	static int c = 0;

	if (p == NULL)
		return;

	v[c++] = p->valor;

	prefixoBST(p->esquerda, v);
	prefixoBST(p->direita, v);
}

void infixoBST(No *p, int *v) {
	static int c = 0;

	if (p == NULL)
		return;

	infixoBST(p->esquerda, v);

	v[c++] = p->valor;

	infixoBST(p->direita, v);
}

void posfixoBST(No *p, int *v) {
	static int c = 0; 
	
	if (p == NULL)
		return;

	posfixoBST(p->esquerda, v);
	posfixoBST(p->direita, v);
	
	v[c++] = p->valor;
}

void xfixoBST(Arvore *a, char x, int *v, int n) {
	assert(n >= a->tamanho);
	if (x == 'e')
		prefixoBST(a->raiz, v);
	else if (x == 'i')
		infixoBST(a->raiz, v);
	else
		posfixoBST(a->raiz, v);
}

void imprimeBST(Arvore *a) {
	int *v = malloc(sizeof(int)*(a->tamanho));
	int i;

	printf("Tamanho %d\n\n", a->tamanho);

	xfixoBST(a, 'e', v, a->tamanho);
	printf("Prefixo: ");
	for (i = 0; i < a->tamanho; i++)
		printf("%d ", v[i]);
	printf("\n\n");

	xfixoBST(a, 'i', v, a->tamanho);
	printf("Infixo: ");
	for (i = 0; i < a->tamanho; i++)
		printf("%d ", v[i]);
	printf("\n\n");

	xfixoBST(a, 'o', v, a->tamanho);
	printf("Posfixo: ");
	for (i = 0; i < a->tamanho; i++)
		printf("%d ", v[i]);
	printf("\n\n");

	free(v);
}

No *incrementaItBST(No *p) {
	if (p->direita != NULL)
		for (p = p->direita; p->esquerda != NULL; p = p->esquerda);
	else {
		No *pA = NULL;
		while (p->pai != NULL && pA == p->direita) {
			pA = p;
			p = p->pai;
		}
	}
	return p;
}

No *decrementaItBST(No *p) {
	if (p->esquerda != NULL)
		for (p = p->esquerda; p->direita != NULL; p = p->direita);
	else {
		No *pA = NULL;
		while (p->pai != NULL && pA == p->esquerda) {
			pA = p;
			p = p->pai;
		}
	}
	return p;
}

void espacamento(const char* str, int n) {
	while (n > 0) {
		printf("%s", str);
		n--;
	}
}

void imprimeSubArvore(No *no, int nivel) {
	if (!no) {
		espacamento("    ", nivel);
		puts("   ~");
	}
	else {
		imprimeSubArvore(no->direita, nivel + 1);
		espacamento("    ", nivel);
		printf("%4d\n", no->valor);
		imprimeSubArvore(no->esquerda, nivel + 1);
	}
	if (nivel == 0) {
		espacamento("=", 40);
		printf("\n");
	}
}

int main() {
	Arvore a;
	constroiBST(&a);

	for (int i = 1; i <= 50; i++)
		insereBST(&a, i);
	
	for (int i = 0; i < 50; i++) {
		int l = rand() % 50 + 1;
		removeBST(&a, l);
	}
	

	imprimeSubArvore(a.raiz, 0);
	imprimeBST(&a);

	system("PAUSE");
	destroiBST(&a);
}