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
    char nucleotideo;
    Item aux;
    if(!(f=fopen(arquivo,"r"))){
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    fseek(f,0,SEEK_END);
    fseek(f, -1, SEEK_CUR);
    nucleotideo=fgetc(f);
    if(nucleotideo!='-'){
        fclose(f);
        f=fopen(arquivo,"a");
        fputc('-',f);
    }
    fclose(f);
    f=fopen(arquivo,"r");
    nucleotideo=fgetc(f);
    while(nucleotideo!='-'){
        l->cauda->prox=(Bloco*)malloc(sizeof(Bloco));
        l->cauda=l->cauda->prox;
        aux.value=nucleotideo;
        l->cauda->dado=aux;
        l->cauda->prox=NULL;
        nucleotideo=fgetc(f);
    }
    fclose(f);
}
void printLista(Lista *l){
    Bloco* aux;
    aux=l->cabeca;
    while (aux->prox!=NULL)
    {
        printf("%c-",aux->prox->dado.value);
        aux=aux->prox;
    }
    printf("\n");
}
void atualizaArquivo(Lista *l,char nomearquvio[80]){
    FILE *f;
    f=fopen(nomearquvio, "w");
    Bloco* aux;
    aux=l->cabeca;
    while(aux->prox!=NULL)
    {
        fputc(aux->prox->dado.value, f);
        aux=aux->prox;
    }
    fputc('-', f);
    fclose(f);
}
void maiorCodon(Lista *l, Lista *codon){
    Bloco *percorre, *remove, *aux;
    int cont=0,max=0;
    percorre=l->cabeca;
    aux=codon->cabeca;
    printf("%d\n",tamanhoLista(codon));
    while (percorre->prox!=NULL&&percorre->prox->prox!=NULL&&percorre->prox->prox->prox!=NULL){
        cont=0;
        remove=percorre->prox;
        while (remove!=NULL)
        {
            if (remove->dado.value==aux->prox->dado.value)
            {
                if (aux->prox==codon->cauda)
                    aux=codon->cabeca;
                else
                    aux=aux->prox;
                remove=remove->prox;
                cont+=1;
            }
            else
            {
                aux=codon->cabeca;
                break;
            }
        }
        printf("%c-",percorre->prox->dado.value);
        printf("%d\n",cont);
        if (cont%tamanhoLista(codon)==0)
        {
            if (cont>max)
                max=cont;
            for (int i = 1; i < (cont/(tamanhoLista(codon))); i++)
                percorre=percorre->prox->prox->prox;
        }
        percorre=percorre->prox->prox->prox;
    }
}
int tamanhoLista(Lista *l){
    Bloco* aux;
    int cont=0;
    aux=l->cabeca;
    while (aux->prox!=NULL){
        cont+=1;
        aux=aux->prox;
    }
    return cont;
}
void printCodon(Bloco *b,int cont){
    printf("oi");
    Bloco* aux;
    aux=b->prox;
    for (int i = 0; i < cont; i++)
    {
        printf("%c-",aux->prox->dado.value);
        aux=aux->prox;
    }
    printf("\n");
}