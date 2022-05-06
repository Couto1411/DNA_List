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
    int i=0;
    while(nucleotideo!='-'){
        l->cauda->prox=(Bloco*)malloc(sizeof(Bloco));
        l->cauda=l->cauda->prox;
        aux.value=nucleotideo;
        l->cauda->dado=aux;
        l->cauda->prox=NULL;
        nucleotideo=fgetc(f);
        i++;
    }
    if (i>=MAXTAM)
        printf("Arquivo e igual ou excedeu a quantidade maxima de 100 nomes, lista fica com os 100 primeiros\n");
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
void maiorCodon(Lista *l){
    Bloco *percorre, *remove;
    int cont=0;
    percorre=l->cabeca;
    while (percorre->prox!=NULL){
        cont=0;
        remove=percorre->prox;
        while (remove->prox!=NULL)
        {
            printf("%c/%c ",remove->dado.value,remove->prox->dado.value);
            if (remove->dado.value=='T'&&remove->prox->dado.value=='A')
                cont+=1;
            else if (remove->dado.value=='A'&&remove->prox->dado.value=='G')
                cont+=1;
            else if(remove->dado.value=='G'&&remove->prox->dado.value=='C')
                cont+=1;
            else if(remove->dado.value=='C'&&remove->prox->dado.value=='T')
                cont+=1;
            else
                break;
            remove=remove->prox;
        }
        printf("%c-",percorre->prox->dado.value);
        printf("%d\n",cont);
        percorre=percorre->prox;
    }
}