#ifndef __JOGOS_H__
#define __JOGOS_H__
#include "biblioteca.h"

typedef struct{
	int pontos;
	char nome[3];
}N;

void entry(int score);

void intro(char* nome, int score);

void print_arquivo();

void Creditos();

void jogar();

void tipo_jogo(int tipo);

void saida();

void tuto();

void velha_p(int tam);

void velha_c(int tam);

#endif
