#include "aula.h"

int main(){
	Lista l,codon;
	char arquivo[80];
	int opcao;
	FLVazia(&l);
	FLVazia(&codon);
	printf("Qual o nome do arquivo da cadeia principal? (Max 80)\n");
	fgets(arquivo,80,stdin);
	arquivo[strlen(arquivo)-1]='\0';
	preencheLista(&l,arquivo);
	printf("Qual o nome do arquivo da cadeia que deseja buscar? (Max 80)\n");
	fgets(arquivo,80,stdin);
	arquivo[strlen(arquivo)-1]='\0';
	preencheLista(&codon,arquivo);
	do
	{
		printf("O que deseja fazer?\n\t1-Buscar Maior Codon\n\t2-Imprimir cadeia principal\n\t3-Imprimir cadeia de busca\n\t4-Imprimir maior codon(Funciona após 1)\n\t0-Sair\n");
		scanf("%d",&opcao);
		switch (opcao)
		{
		case 1:
			maiorCodon(&l,&codon);
			break;
		case 2:
			printLista(&l);
			break;
		case 3:
			printLista(&codon);
			break;
		case 4:
			printCodon();
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
