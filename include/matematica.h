#ifndef MATEMATICA_H
#define MATEMATICA_H

/*Calcula a raiz do número*/
void buscarRaiz(double* baseRaiz, int* indiceRaiz, int* casasDecimais, double* resultado);

/*Calcula a potência do número*/
double potencia(double baseNum, int expoenteNum);

/*Conta a quantidade de casas decimais*/
void contarCasasDecimais(double* baseRaiz, int* casas);

#endif