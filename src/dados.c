#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "matematica.h"

void receberInputRaiz(double* baseRaiz, int* indiceRaiz, char indiceRaizString[], char baseRaizString[])
{
    /*Printa a tabela*/
    printf("-__________________________________________-\n");
    printf("|                                          |\n");
    printf("|          < Gerador de raizes >           |\n");
    printf("-__________________________________________-\n");

    /*Pede os inputs*/
    //quebra de linha
    printf("\n");

    //número
    printf("Digite a base:\n>> ");
    fgets(baseRaizString, 80, stdin);

    /*Formata a string para a base*/
    formatarStringBase(baseRaiz, baseRaizString);

    //indice
    printf("Digite o indice (ex: 2/3):\n>> ");
    fgets(indiceRaizString, 40, stdin);

    /*Formata a string para indice*/
    formatarStringIndice(baseRaiz, indiceRaiz, indiceRaizString);

    /*Fim*/
    return;
}

void formatarStringIndice(double* baseRaiz, int* indiceRaiz, char indiceRaizString[])
{
    /*Variáveis*/
    int vetorInt[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int isDenominador = 0;
    int isNumero = 0;
    int numerador = 0;
    int denominador = 0;
    int isNumeradorNegativo = 0;
    int isDenominadorNegativo = 0;
    int isFracao = 0;
 
    /*Desconverte a string*/
    int i = 0;
    while(indiceRaizString[i] != '\n')
    {
        /*Verifica se é numero*/
        for(int j = 0; j < 10; j++) 
        {
            if((indiceRaizString[i] - '0') == vetorInt[j])
            {
                isNumero = 1;
                break;
            }
        }

        /*Analisa os caracteres*/
        if(isNumero == 1 && isDenominador == 1)
        {
            denominador = (denominador * 10) + (indiceRaizString[i] - '0');
        }
        else if(isNumero == 1)
        {
            numerador = (numerador * 10) + (indiceRaizString[i] - '0');
        }
        else if(indiceRaizString[i] == '/')
        {
            isDenominador = 1;
            isFracao = 1;
        }
        else if(indiceRaizString[i] == '-' && isDenominador == 1)
        {
            isDenominadorNegativo = 1;
        }
        else if(indiceRaizString[i] == '-')
        {
            isNumeradorNegativo = 1;
        }
        else if(indiceRaizString[i] != '+' && indiceRaizString[i] != '(' && indiceRaizString[i] != ')')
        {
            printf("Erro! Digite apenas caracteres validos\n");
            exit(1);
        }

        /*Atualiaza os valores de controle*/
        i++;
        isNumero = 0;
    }

    /*Verifica se não é uma fração*/
    if(isFracao == 0 && isNumeradorNegativo == 1)
    {
        printf("Erro! Digite o indice nao pode ser negativo\n");
        exit(3);
    }
    else if(isFracao == 0)
    {
        *indiceRaiz = numerador;
        return;
    }

    /*Verificar se é negativo, e converter*/
    if (isNumeradorNegativo == 1 && isDenominadorNegativo == 1);
    else if(isNumeradorNegativo == 1) numerador *= -1;
    else if(isDenominadorNegativo == 1) denominador *= -1;
    
    /*Simplificar por mmc*/
    for(int i = 2; i < 10; i++)
    {
        /*Se for divisível em ambos*/
        if(numerador % vetorInt[i] == 0 && denominador % vetorInt[i] == 0)
        {
            /*Divide os valores*/
            numerador /= vetorInt[i];
            denominador /= vetorInt[i];

            /*Atualiza o index para voltar e testar novamente*/
            i--;
        }
    }

    /*Verifica se o denominador é negativo (impossível)*/
    if(denominador < 0)
    {
        printf("Erro! Digite o indice nao pode ser negativo\n");
        exit(2);
    }

    /*Verifica se o numerador é negativo e atualiza*/
    if(numerador < 0) *baseRaiz = 1 / potencia(*baseRaiz, (numerador * -1));
    else *baseRaiz = potencia(*baseRaiz, numerador);

    /*Atualiza o indice*/
    *indiceRaiz = denominador;

    /*Fim*/
    return;
}

void formatarStringBase(double* baseRaiz, char baseRaizString[])
{
    /*Variáveis*/
    int vetorInt[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int isDenominador = 0;
    int isNumero = 0;
    int numerador = 0;
    int denominador = 0;
    int isNumeradorNegativo = 0;
    int isDenominadorNegativo = 0;
    int isFracao = 0;

    /*Desconverte a string*/
    int i = 0;
    while(baseRaizString[i] != '\n')
    {
        /*Verifica se é numero*/
        for(int j = 0; j < 10; j++) 
        {
            if((baseRaizString[i] - '0') == vetorInt[j])
            {
                isNumero = 1;
                break;
            }
        }

        /*Analisa os caracteres*/
        if(isNumero == 1 && isDenominador == 1)
        {
            denominador = (denominador * 10) + (baseRaizString[i] - '0');
        }
        else if(isNumero == 1)
        {
            numerador = (numerador * 10) + (baseRaizString[i] - '0');
        }
        else if(baseRaizString[i] == '/')
        {
            isDenominador = 1;
            isFracao = 1;
        }
        else if(baseRaizString[i] == '-' && isDenominador == 1)
        {
            isDenominadorNegativo = 1;
        }
        else if(baseRaizString[i] == '-')
        {
            isNumeradorNegativo = 1;
        }
        else if(baseRaizString[i] != '+' && baseRaizString[i] != '(' && baseRaizString[i] != ')')
        {
            printf("Erro! Digite apenas caracteres validos\n");
            exit(4);
        }

        /*Atualiaza os valores de controle*/
        i++;
        isNumero = 0;
    }

    /*Verificar se é negativo, e converter*/
    if (isNumeradorNegativo == 1 && isDenominadorNegativo == 1);
    else if(isNumeradorNegativo == 1) numerador *= -1;
    else if(isDenominadorNegativo == 1) denominador *= -1;

    /*Verifica se não é uma fração*/
    if(isFracao == 0)
    {
        //atualiza a base
        *baseRaiz = numerador;
        return;
    }

    /*Simplificar por mmc*/
    for(int i = 2; i < 10; i++)
    {
        /*Se for divisível em ambos*/
        if(numerador % vetorInt[i] == 0 && denominador % vetorInt[i] == 0)
        {
            /*Divide os valores*/
            numerador /= vetorInt[i];
            denominador /= vetorInt[i];

            /*Atualiza o index para voltar e testar novamente*/
            i--;
        }
    }

    /*Atualiza o indice*/
    *baseRaiz = (double)numerador/denominador;

    /*Fim*/
    return;
}

void imprimirOutputRaiz(double* resultado)
{
    /*Printa a tabela*/
    printf("\nA raiz e: %.16lf\n", *resultado);

    /*Fim*/
    return;
}