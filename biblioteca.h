#ifndef __BIBLIOTECA_H__
#define __BIBLIOTECA_H__
#include "jogos.h"

void limp(int n);

int *criar_campo(int m);

void tela(int *v, int m);

void jogo(int *v, int m);

int mudar_X(int *v, int num, int tam);

int mudar_O(int *v, int num, int tam);

int verif(int *v, int num);

#endif
