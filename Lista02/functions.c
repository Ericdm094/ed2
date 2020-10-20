
#include <stdio.h>
#include <stdlib.h>
#include "arvbin.h"

struct arv {
     ArvNo* raiz;
};

struct arvno {
    int info;
    ArvNo* esq;
    ArvNo* dir;
};

Arv* arv_cria(ArvNo* r){
    Arv* a = (Arv*) malloc(sizeof(Arv));
    if(a == NULL) {
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    a->raiz = r;
    return a;
}

ArvNo* arv_criano(int v, ArvNo* e, ArvNo* d){
    ArvNo* no = (ArvNo*) malloc(sizeof(ArvNo));
    if(no == NULL) {
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    no->info = v;
    no->esq = e;
    no->dir = d;
    return no;
}


static void libera(ArvNo* r)
{
    if(r!= NULL){
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}


void arv_libera(Arv* a){
    libera(a->raiz);
    free(a);
}

static int verifica(ArvNo* r) {
    if(r != NULL) {
        if(r->info % 2 == 0){
            return 1 + verifica(r->esq) + verifica(r->dir);
        }else{
            return 0 + verifica(r->esq) + verifica(r->dir);
        }
    }
}

int pares(Arv* a){
    return verifica(a->raiz);
}

static void imprime(ArvNo* r) {
    printf("<");
    if(r != NULL) {
        printf("%d", r->info);
        imprime(r->esq);
        imprime(r->dir);
    }
    printf(">");
}

void arv_imprime(Arv* a){
    imprime(a->raiz);
}


static ArvNo* copyTree(ArvNo* r){
    if(r == NULL){
        return NULL;
    }

    ArvNo* b = (ArvNo*) malloc(sizeof(ArvNo));
    if(b == NULL) {
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    b->info = r->info;
    b->esq = copyTree(r->esq);
    b->dir = copyTree(r->dir);
    return b;
}

Arv* copia (Arv* a){
    Arv* b1 = (Arv*) malloc(sizeof(Arv));
    if(b1 == NULL) {
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    b1->raiz = copyTree(a->raiz);
    return b1;
}
















