#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

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

static int busca_valor(ArvNo* r, int v){
    if(r == NULL) return 0;
    if(v == r->info){
       return 1;
    }else{
        if(v > r->info){
            return busca_valor(r->dir, v);
        }
        else{
           return busca_valor(r->esq, v);
        }
     }
}

int arv_pertence(Arv* a, int v){
    busca_valor(a->raiz, v);
}


static ArvNo* busca(ArvNo* r, int v) {
    if(r == NULL)  return NULL;
    else if(v < r->info) return busca(r->esq, v);
    else if(v > r->info) return busca(r->dir, v);
    else return r;
}

ArvNo* arv_busca(Arv* a, int v) {
    return busca(a->raiz, v);
}











