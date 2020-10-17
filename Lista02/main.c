#include <stdio.h>
#include <stdlib.h>
#include "arvbin.h"

int main(){
    ArvNo* um = arv_criano(1, NULL, NULL);
    ArvNo* seis = arv_criano(6, NULL, NULL);
    ArvNo* tres = arv_criano(3, um, seis);
    ArvNo* qua = arv_criano(14, NULL, NULL);
    ArvNo* dez = arv_criano(10, NULL, qua);

    ArvNo* oito = arv_criano(8, tres, dez);

    Arv* arv = arv_cria(oito);

    printf("%d", pares(arv));

    arv_libera(arv);
    return 0;
}
