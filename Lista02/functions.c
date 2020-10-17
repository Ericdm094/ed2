
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

static int aux(ArvNo* r){
    if(r->info %2 == 0){
        return 1 + aux()
    }
}

int pares (Arv* a){
    if (a != NULL){
        return aux(a->raiz);
    }
}













