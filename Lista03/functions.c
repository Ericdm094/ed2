#include <stdio.h>
#include <stdlib.h>
#include "arvbin.h"
#include <string.h>

struct aluno {
 char nome[81];
 float p1, p2, p3;
};

struct arv {
 ArvNo* raiz;
};

struct arvno {
 Aluno* info;
 ArvNo* esq;
 ArvNo* dir;
};


static void imprime(ArvNo* r) {
    printf("<");
    if(r != NULL) {
        printf("%s", r->info->nome);
        imprime(r->esq);
        imprime(r->dir);
    }
    printf(">");
}

void arv_imprime(Arv* a){
    imprime(a->raiz);
}

Arv* aa_cria (void){
    Arv* a = (Arv*) malloc(sizeof(Arv));
    if(a == NULL) {
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    a->raiz = NULL;
    return a;
}

ArvNo* arv_criano(ArvNo* arvn, ArvNo* no){
    int esq_or_dir = strcmp(arvn->info->nome, no->info->nome);
    if (esq_or_dir > 0){
        if(arvn->esq == NULL){
            arvn->esq = no;
            return arvn;
        }else{
            return arv_criano(arvn->esq, no);
        }

    }else if(esq_or_dir < 0){
        if(arvn->dir == NULL){
            arvn->dir = no;
            return arvn;
        }else{
            return arv_criano(arvn->dir, no);
        }
    }
}

void aa_insere (Arv* a, char* nome, float p1, float p2, float p3){
    Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));
    if(aluno == NULL){
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    strcpy(aluno->nome,nome);
    aluno->p1 = p1;
    aluno->p2 = p2;
    aluno->p3 = p3;

    ArvNo* no = (ArvNo*) malloc(sizeof(ArvNo));
    if(no == NULL) {
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    no->info = aluno;
    no->esq = NULL;
    no->dir = NULL;

    if(a->raiz == NULL){
        a->raiz = no;
    }else{
        arv_criano(a->raiz, no);
    }
}

static ArvNo* busca_aluno(ArvNo* arvn, char* nome) {
    if(arvn == NULL)  return NULL;
    int esq_or_dir = strcmp(arvn->info->nome, nome);
    if(esq_or_dir > 0) return busca_aluno(arvn->esq, nome);
    else if(esq_or_dir < 0) return busca_aluno(arvn->dir, nome);
    else return arvn;
}

float aa_media (Arv* a, char* nome){
    float media = 0;
    ArvNo* no_aluno = busca_aluno(a->raiz, nome);
    if(no_aluno != NULL){
        media = (no_aluno->info->p1 + no_aluno->info->p2 + no_aluno->info->p3)/3;
        return media;
    }
    return 0;
}

void aa_retira (Arv* a, char* nome){
    ArvNo* no_aluno = busca_aluno(a->raiz, nome);
    if(no_aluno != NULL){
        ArvNo* no = (ArvNo*) malloc(sizeof(ArvNo));
        if(no == NULL) {
            printf("Memoria insuficiente.\n");
            exit(1);
        }
        no->info = NULL;
        no->esq = no_aluno->esq;
        no->dir = no_aluno->dir;
        no_aluno->info = no;
    }
}

static void libera(ArvNo* arvn){
    if(arvn!= NULL){
        libera(arvn->esq);
        libera(arvn->dir);
        free(arvn->info);
        free(arvn);
    }
}

void aa_libera (Arv* a){
    libera(a->raiz);
    free(a);
}



