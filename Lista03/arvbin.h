#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED

typedef struct aluno Aluno;

typedef struct arv Arv;
typedef struct arvno ArvNo;

Arv* aa_cria (void);

ArvNo* arv_criano(ArvNo* arvn, ArvNo* no);

void aa_insere (Arv* a, char* nome, float p1, float p2, float p3);

void arv_imprime(Arv* a);

float aa_media (Arv* a, char* nome);

void aa_libera (Arv* a);

void aa_retira (Arv* a, char* nome);


#endif
