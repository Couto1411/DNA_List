#include "aula.h"

int main(){
	Lista l,codon;
	char arquivo[80];
	int opcao,max=0;
	FLVazia(&l);
	printf("Qual o nome do arquivo da cadeia principal? (Max 80)\n");
	fgets(arquivo,80,stdin);
	arquivo[strlen(arquivo)-1]='\0';
	preencheLista(&l,arquivo);
	FLVazia(&codon);
	printf("Qual o nome do arquivo da cadeia que deseja buscar? (Max 80)\n");
	fgets(arquivo,80,stdin);
	arquivo[strlen(arquivo)-1]='\0';
	preencheLista(&codon,arquivo);
	do
	{
		printf("O que deseja fazer?\n\t1-Buscar Maior Codon\n\t2-Imprimir cadeia principal\n\t3-Imprimir cadeia de busca\n\t0-Sair\n");
		scanf("%d",&opcao);
		switch (opcao)
		{
		case 1:
			max=maiorCodon(&l,&codon);
			printCodon(&maxCodon,max,&codon);
			break;
		case 2:
			printLista(&l);
			break;
		case 3:
			printLista(&codon);
			break;
		case 0:
			printf("Saindo\n");
			break;
		default:
			break;
		}
	}while (opcao!=0);
	return 0;
}
