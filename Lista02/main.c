#include <stdio.h>
#include <stdlib.h>
#include "arvbin.h"

int main(){
    ArvNo* tres = arv_criano(3, NULL, NULL);
    ArvNo* quatro = arv_criano(4, NULL, NULL);
    ArvNo* cinco = arv_criano(5, NULL, NULL);
    ArvNo* dois = arv_criano(2, quatro, cinco);
    ArvNo* um = arv_criano(1, dois, tres);

    Arv* arv = arv_cria(um);
    Arv* cop = copia(arv);

    printf("%d pares foram encontrados.\n", pares(arv));

    printf("#Arvore original#\n");
    arv_imprime(arv);
    arv_libera(arv);
    printf("\n#Arvore copia#\n");
    arv_imprime(cop);
    arv_libera(cop);

    return 0;
}
