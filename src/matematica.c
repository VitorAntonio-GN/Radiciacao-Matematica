#include <stdio.h>
#include "matematica.h"

void buscarRaiz(double* baseRaiz, int* indiceRaiz, int* casasDecimais, double* resultado)
{
    /*Variáveis*/
    int achouRaiz = 0;
    double valorBuscaAnterior = 0;
    double valorBusca = 0;
    double posBuscaMax = 0;
    double posBuscaMin = 0;
    double potenciaBusca = 0;

    /*Se a base for negativa*/
    //valor inicial da busca é mudado
    if(*baseRaiz >= 0)
    {
        valorBusca = potencia(10, *casasDecimais);         // -> define a 1o valor com base nas casas decimais
        posBuscaMax = valorBusca;                          // -> define o max e o mínimo com base no valor busca
        posBuscaMin = 0;                                   // |
    }
    else
    {
        valorBusca = 0;                                                         // -> define a 1o valor com base nas casas decimais
        posBuscaMax = valorBusca;                                               // -> define o max e o mínimo com base no valor busca
        posBuscaMin = potencia(10, *casasDecimais) * -1;                        // |
    }

    /*Garante a 1a potencia de busca*/
    potenciaBusca = potencia(valorBusca, *indiceRaiz);

    /*Loop da busca*/
    do{
        /*Atualiza valor busca anterior*/
        valorBuscaAnterior = valorBusca;

        /*Verificações da potencia do valor de busca*/
        //se for maior, subtrai ao meio
        if(potenciaBusca > *baseRaiz)
        {
            valorBusca -= (posBuscaMax - posBuscaMin) / 2;
        }

        //se for menor, soma a metade
        else if(potenciaBusca < *baseRaiz)
        {
            valorBusca += (posBuscaMax - posBuscaMin) / 2;
        }

        /*Atualiza a nova potencia da busca*/
        potenciaBusca = potencia(valorBusca, *indiceRaiz);

        /*Verifica se a nova potencia da busca é ponto min ou max*/
        if(potenciaBusca > *baseRaiz) posBuscaMax = valorBusca;
        else posBuscaMin = valorBusca;

        /*Se achou a raiz*/
        //se for igual, achou a raiz
        if(potenciaBusca == *baseRaiz) achouRaiz = 1;
        else if(valorBuscaAnterior == valorBusca) achouRaiz = 1;

    } while(achouRaiz == 0);

    /*Atribui ao resultado*/
    *resultado = valorBusca;

    /*Fim*/
    return;
}

double potencia(double baseNum, int expoenteNum)
{
    /*Verifica se o expoente chegou a 0*/
    //se chegou a 0, é o fim, para de multiplicar
    if(expoenteNum == 0) return 1;
    else expoenteNum--; 

    /*Fim*/
    return (baseNum * potencia(baseNum, expoenteNum));
}

void contarCasasDecimais(double* baseRaiz, int* casasDecimais)
{
    /*Variáveis*/
    double base = *baseRaiz;

    /*Se negativo, inverte para uso*/
    if(*baseRaiz < 0) base *= -1;

    /*Loop*/
    //enquanto houver um num depois da vígula, ele conta. ex: 0,1 -> 0; 1,23 -> 1.
    while(base >= 1)
    {
        base /= 10;
        (*casasDecimais)++;
    }

    /*Fim*/
    return;
}