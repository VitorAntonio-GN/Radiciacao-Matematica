#include <stdio.h>
#include <stdlib.h>
#include "verificacao.h"
#include "matematica.h"

void validarRaizReais(double* baseRaiz, int* indiceRaiz)
{
    /*Verifica se a raiz é inexistente*/
    //se houver sinal negativo e indice par, é impossível
    if(*baseRaiz < 0 && *indiceRaiz % 2 == 0)
    {
        printf("Erro! Raiz impossivel\n");
        exit(5);
    }

    /*Fim*/
    return;
}

void verificarRaiz(double* baseRaiz)
{
    /*Verifica se a base é 0*/
    if(baseRaiz == 0)
    {
        printf("A raiz e: %.16lf\n", 0);
    }

    /*Fim*/
    return;
}