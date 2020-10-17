#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

int main(){
    ArvNo* um = arv_criano(1, NULL, NULL);
    ArvNo* seis = arv_criano(6, NULL, NULL);
    ArvNo* tres = arv_criano(3, um, seis);
    ArvNo* qua = arv_criano(14, NULL, NULL);
    ArvNo* dez = arv_criano(10, NULL, qua);

    ArvNo* oito = arv_criano(8, tres, dez);

    Arv* arv = arv_cria(oito);
    arv_imprime(arv);

    int exist = arv_pertence(arv, 10);
    if(exist == 1){
        printf("\nNumero Encontrado. \n");
    }else{
         printf("\nNumero Nao Encontrado. \n");
    }

    ArvNo* arv_contain = arv_busca(arv, 1);
    if(arv_contain != NULL){
       printf("No encontrado.\n");
    }
    else
        printf("No nao encontrado.\n");


    arv_libera(arv);
    return 0;
}
