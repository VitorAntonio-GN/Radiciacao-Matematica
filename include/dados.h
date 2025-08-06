#ifndef DADOS_H
#define DADOS_H

/*Lê os inputs*/
void receberInputRaiz(double* baseRaiz, int* indiceRaiz, char indiceRaizString[], char baseRaizString[]);

/*Formata o input de string*/
void formatarStringIndice(double* baseRaiz, int* indiceRaiz, char indiceRaizString[]);

/*Formata o input de string*/
void formatarStringBase(double* baseRaiz, char baseRaizString[]);

/*Imprime o resultado*/
void imprimirOutputRaiz(double* resultado);

#endif