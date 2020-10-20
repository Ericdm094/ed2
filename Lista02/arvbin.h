
#ifndef ARV_H_INCLUDED
#define ARV_H_INCLUDED

typedef struct arv Arv;
typedef struct arvno ArvNo;

Arv* arv_cria(ArvNo* r);
ArvNo* arv_criano(int v, ArvNo* esq, ArvNo* dir);
void arv_libera(Arv* a);
void arv_imprime(Arv* a);

int pares (Arv* a);

Arv* copia (Arv* a);

#endif
