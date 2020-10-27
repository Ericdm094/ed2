#include <stdio.h>
#include <stdlib.h>
#include "arvbin.h"

int main()
{
    Arv* raiz = aa_cria();

    aa_insere(raiz,"Helton", 6,6,6);
    aa_insere(raiz,"Pedro", 3,2,3);
    aa_insere(raiz,"Eric", 8,10,8);

    arv_imprime(raiz);

    float media = aa_media(raiz, "Helton");
    if(media >= 0){
        printf("\nMedia = %.1f\n", media);
    }else{
        printf("\naluno nao encontrado!.\n");
    }

    aa_retira(raiz, "Pedro");
    arv_imprime(raiz);

    aa_libera(raiz);
    return 0;
}
