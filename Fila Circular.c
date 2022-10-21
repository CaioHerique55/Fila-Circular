//#include <iostream>
#include <stdlib.h>
//#include <string>


struct Fila {

	int capacidade;
	float *dados;
	int first;
	int last;
	int nItens;

};

void criarFila( struct Fila *f, int c ) {

	f->capacidade = c;
	f->dados = (float*) malloc (f->capacidade * sizeof(float));
	f->first = 0;
	f->last = -1;
	f->nItens = 0;

}

void add(struct Fila *f, int v) {

	if(f->last == f->capacidade-1)
		f->last = -1;

	f->last++;
	f->dados[f->last] = v; 
	f->nItens++;

}

int remover( struct Fila *f ) { 

	int temp = f->dados[f->first++]; 
	if(f->first == f->capacidade)
		f->first = 0;

	f->nItens--;  
	return temp;

}

int FilaVazia( struct Fila *f ) { //retorna se a fila esta vazia

	return (f->nItens==0);

}

int FilaCheia( struct Fila *f ) { // retorna se a fila esta cheia

	return (f->nItens == f->capacidade);
}

void MostraFila(struct Fila *f){ //mostra a fila inteira - conteudo da fila

	int cont, i;

	for ( cont=0, i= f->first; cont < f->nItens; cont++){

		printf("%.2f\t",f->dados[i++]);

		if (i == f->capacidade)
			i=0;

	}
	printf("\n\n");

}

void main () {

	int opcao, capa;
	float valor;
	struct Fila FilaUm;

	// cria a fila
	printf("\nCapacidade da fila? ");
	scanf("%d",&capa);
	criarFila(&FilaUm, capa);

	// menu de opções
	while( 1 ){

		printf("\n1 - Inserir \n2 - Remover\n3 - Mostra Conteudo da Fila\n0 - Sair\n\nOpcao? ");
		scanf("%d", &opcao);

		switch(opcao){

			case 0: exit(0);

			case 1: // add 
				if (FilaCheia(&umaFila)){

					printf("\nFila Cheia!!!\n\n");

				}
				else {

					printf("\nEntre com o valor a ser adicionado ");
					scanf("%f", &valor);
					inserir(&FilaUm,valor);

				}

				break;

			case 2: // remove
				if (FilaVazia(&FilaUm)){

					printf("\n a fila esta vazia!!!\n\n");

				}
				else {

					valor = remover(&FilaUm);
					printf("\n%1f Valor removido\n\n", valor) ;

				}
				break;

				case 3: // mostrar fila
					if (FilaVazia(&umaFila)){

						printf("\nFila vazia!!!\n\n");

					}
					else {

						printf("\nConteudo da fila => ");
						mostrarFila(&umaFila);

					}
					break;

				default:
					printf("\nEssa opção não existe\n\n");

		}
	}
}
