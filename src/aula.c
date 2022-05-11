#include "aula.h"
void FLVazia(Lista *l){
    // diz que a cabeça da lista é um espaço de memória que armazena um BLOCO
    l->cabeca=(Bloco*)malloc(sizeof(Bloco));
    // diz que o ultimo termo da lista é o primeiro
    l->cauda=l->cabeca;
    // diz que o proximo item depois do ultimo é nulo
    l->cauda->prox=NULL;
}
void preencheLista(Lista *l,char arquivo[80]){
    FILE *f;
    int nucleotideo;
    Item aux;
    if(!(f=fopen(arquivo,"r"))){
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    nucleotideo=fgetc(f);
    while(!feof (f)){
        aux.value[0]=nucleotideo;
        nucleotideo=fgetc(f );
        aux.value[1]=nucleotideo;
        nucleotideo=fgetc(f );
        aux.value[2]=nucleotideo;
        nucleotideo=fgetc(f );
        l->cauda->prox=(Bloco*)malloc(sizeof(Bloco));
        l->cauda=l->cauda->prox;
        aux.posicao=(ItemPos*)malloc(sizeof(ItemPos));
        aux.posicao->pos=0;
        l->cauda->dado=aux;
        l->cauda->prox=NULL;
    }
    fclose(f);
}
void printLista(Lista *l){
    Bloco* aux;
    aux=l->cabeca;
    while (aux->prox!=NULL)
    {
        printf("%s-%d\n",aux->prox->dado.value,aux->prox->dado.posicao->pos);
        aux=aux->prox;
    }
}
void maiorCodon(Lista *l, Lista *codon){
    Bloco *codons, *aux, *temp;
    int i=1,tamanho;
    codons=codon->cabeca;
    while (codons->prox!=NULL)
    {
        codons->prox->dado.posicao->pos=i;
        codons=codons->prox;
        i++;
    }
    codons=codon->cabeca;
    while (codons->prox!=NULL)
    {
        aux=l->cabeca;
        while (aux->prox!=NULL)
        {
            if (strcmp(codons->prox->dado.value,aux->prox->dado.value)==0)
                aux->prox->dado.posicao->pos=codons->prox->dado.posicao->pos;
            aux=aux->prox;
        }
        codons=codons->prox;
    }
    i=0;
    aux=l->cabeca;
    while (aux->prox!=NULL)
    {
        if (aux->prox->dado.posicao->pos==i+1)
        {
            temp=aux->prox;
            tamanho=1;
            while (temp!=NULL&&temp->dado.posicao->pos==i+1)
            {
                tamanho+=1;
                i++;
                temp=temp->prox;
            }
            if (tamanho>tamanhoCodon)
            {
                tamanhoCodon=tamanho;
                maxCodon=aux;
            }
            i=i-tamanho+1;
        }   
        aux=aux->prox;
        if (aux->prox==NULL&&i<codons->dado.posicao->pos)
        {
            aux=l->cabeca;
            i++;
        }
    }
    
}
// int tamanhoLista(Lista *l){
//     Bloco* aux;
//     int cont=0;
//     aux=l->cabeca;
//     while (aux->prox!=NULL){
//         cont+=1;
//         aux=aux->prox;
//     }
//     return cont;
// }
void printCodon(){
    Bloco *aux;
    aux=maxCodon;
    for (int i = 1; i < tamanhoCodon; i++)
    {
        printf("%s - %d \n",aux->prox->dado.value,aux->prox->dado.posicao->pos);
        aux=aux->prox;
    }
    printf("\n");
}