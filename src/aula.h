#ifndef AULA
#define AULA

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bloco Bloco;
typedef struct Item{
    char value;
}Item;

struct Bloco{
    Item dado;
    Bloco *prox;
};

typedef struct Lista{
    Bloco* cabeca;
    Bloco* cauda;
}Lista;

Bloco maxCodon;

void FLVazia(Lista *l);
void preencheLista(Lista *l,char f[80]);
int maiorCodon(Lista *l,Lista *codon);
void printLista(Lista *l);
int tamanhoLista(Lista *l);
void printCodon(Bloco *b,int cont,Lista *codon);
#endif