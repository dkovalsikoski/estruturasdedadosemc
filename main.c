#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prox;
    int valor;
} TipoNode;

typedef struct lista {
    TipoNode *inicio;
    int tamanho;
} Lista;

void FLVazia(Lista *lista){
    lista->inicio = NULL;
    lista->tamanho = 0;
}

int vazia(Lista lista){
    return lista.inicio == NULL;
}

void insereFim(int item, Lista *lista){
    if (vazia(*lista)){
        lista->inicio = malloc(sizeof(TipoNode));
        lista->inicio->valor=item;
        lista->inicio->prox=NULL;
    }else{
        TipoNode *prox = lista->inicio;
        while(prox->prox != NULL){
            prox = prox->prox;
        }

        TipoNode *novo = malloc(sizeof(TipoNode));
        prox->prox = novo;
        novo->valor = item;
        novo->prox = NULL;
    }
    lista->tamanho++;
}

void insere(int item, int pos, Lista *lista){
    if (pos > lista->tamanho){
        printf("Impossível inserir pois posição <%d> é maior que tamanho <%d>");
    }else {
        while(){

        }
    }
}

void imprime(Lista lista){
    TipoNode *node = lista.inicio;
    while(node != NULL){
        printf("%d ", node->valor);
        node = node->prox;
    }
    printf("\n");
}

int main() {
    Lista lista;
    FLVazia(&lista);
    insereFim(1, &lista);
    insereFim(3, &lista);
    insereFim(-1, &lista);
    insereFim(5, &lista);
    imprime(lista);
}
