#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	int dado;
	struct no *prox;
}No;

typedef struct lista{
	No *inicio;
	int tam;
}Lista;



void criarLista(Lista *L){
	No novo = (No)malloc(sizeof(No));
	L->inicio = NULL;
	L->tam = 0;
}

void excluirLista(Lista *L){
	No *lista = L->inicio;
	while(lista != NULL){
		No *exc = lista;
		lista = lista->prox;
		free(exc);
	}
	free(lista);
}

void inserirOrdenado(Lista *L, int x){
	No novo = (No)malloc(sizeof(No));
	No aux = (No)malloc(sizeof(No));
	if(novo){
		novo->dado = x;
		if(L->inicio == NULL){
		novo->prox = NULL;
		L->inicio = novo;
		}
		else if(novo->dado < L->inicio->dado){
			novo->prox = L->inicio;
		L->inicio = novo;		
		}else{
			aux = L->inicio;
				while(aux->prox && novo->dado > aux->prox->dado){
					aux = aux->prox;
				}
				novo->prox = aux->prox;
				aux->prox = novo;
			}
			L->tam++;
	}else{
		printf("Erro ao alocar memoria!");
	}
}

void imprimir(Lista L){
	No *atual = L.inicio;
	while(atual!=NULL){
		printf("%d ", atual->dado);
		atual = atual->prox;
	}
	printf("\n\n");
}
/*
void remover(Lista *L, int x){
	No *aux = L->inicio;
	No *exc = NULL;
	
	if(aux != NULL && L->inicio->dado == x){
		exc = L->inicio;
		L->inicio = exc->prox;
		if(L->inicio == NULL){
			L->fim = NULL;
		}
	}else{
		while(aux != NULL && aux->prox != NULL && aux->prox->dado != x){
			aux= aux->prox;
		}
		if(aux != NULL && aux->prox != NULL){
			exc = aux->prox;
			aux->prox = exc->prox;
			if(aux->prox == NULL){
				L->fim = aux;
			}
		}
		if(exc){
			free(exc);
		}
	}
	
}
*/

int main(){
	Lista lista;
	criarLista(&lista);

	
	inserirOrdenado(&lista, 4);
	inserirOrdenado(&lista, 10);
	inserirOrdenado(&lista, 8);
	inserirOrdenado(&lista, 2);
	
	imprimir(lista);
	excluirLista(&lista);

}