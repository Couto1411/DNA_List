#ifndef AULA
#define AULA

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAM 100

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

void FLVazia(Lista *l);
void preencheLista(Lista *l,char f[80]);
void maiorCodon(Lista *l);
void printLista(Lista *l);
void atualizaArquivo(Lista *l,char nomearquvio[80]);
#endif