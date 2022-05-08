#include "aula.h"

int main(){
	Lista l,codon;
	char arquivo[80];
	int opcao;
	FLVazia(&l);
	printf("Qual o nome do arquivo da cadeia? (Max 80)\n");
	fgets(arquivo,80,stdin);
	arquivo[strlen(arquivo)-1]='\0';
	preencheLista(&l,arquivo);
	FLVazia(&codon);
	printf("Qual o nome do arquivo? (Max 80)\n");
	fgets(arquivo,80,stdin);
	arquivo[strlen(arquivo)-1]='\0';
	preencheLista(&codon,arquivo);
	do
	{
		printf("O que deseja fazer?\n\t1-Inserir nome\n\t2-Buscar Codon\n\t3-Remover iguais\n\t4-Printar lista\n\t5-Mostrar repetições\n\t8-Atualizar arquivo\n\t9-Sair (Arquivo atualizado)\n\t0-Sair (Não atualizar arquivo)\n");
		scanf("%d",&opcao);
		switch (opcao)
		{
		case 1:
			break;
		case 2:
			maiorCodon(&l,&codon);
			//printCodon(&maxCodon,max);
			break;
		case 4:
			printLista(&l);
			printLista(&codon);
			break;
		case 8:
			printf("Atualizando arquivo...\n");
			atualizaArquivo(&l,arquivo);
			break;
		case 9:
			printf("Atualizando arquivo...\n");
			atualizaArquivo(&l,arquivo);
			printf("Saindo.\n");
			opcao=0;
			break;
		case 0:
			printf("Saindo.\n");
			break;
		default:
			break;
		}
	}while (opcao!=0);
	return 0;
}
