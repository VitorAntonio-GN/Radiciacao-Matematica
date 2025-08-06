#include <stdio.h>
#include "dados.h"
#include "matematica.h"
#include "verificacao.h"

int main(void)
{   
    /*Variáveis*/
    double baseRaiz = 0;
    int indiceRaiz = 0;
    char baseRaizString[80] = {};
    char indiceRaizString[40] = {};
    int casasDecimais = 0;
    double resultado = 0;

    /*Recebe o input*/
    receberInputRaiz(&baseRaiz, &indiceRaiz, indiceRaizString, baseRaizString);

    /*Verifica se a raiz é 0*/
    verificarRaiz(&baseRaiz);

    /*Verifica a validade nos Reais*/
    validarRaizReais(&baseRaiz, &indiceRaiz);

    /*Conta a quantidade de casas decimais*/
    contarCasasDecimais(&baseRaiz, &casasDecimais);

    /*Busca a raiz*/
    buscarRaiz(&baseRaiz, &indiceRaiz, &casasDecimais, &resultado);

    /*Imprime o resultado*/
    imprimirOutputRaiz(&resultado);

    /*Fim*/
    return 0;
}
