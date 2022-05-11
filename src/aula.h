#ifndef AULA
#define AULA

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bloco Bloco;

typedef struct ItemPos
{
    int pos;
}ItemPos;

typedef struct Item{
    char value[3];
    ItemPos *posicao;
}Item;

struct Bloco{
    Item dado;
    Bloco *prox;
};

typedef struct Lista{
    Bloco* cabeca;
    Bloco* cauda;
}Lista;

Bloco *maxCodon;
int tamanhoCodon;

void FLVazia(Lista *l);
void preencheLista(Lista *l,char f[80]);
void printLista(Lista *l);
void maiorCodon(Lista *l,Lista *codon);
// int tamanhoLista(Lista *l);
void printCodon();
#endif