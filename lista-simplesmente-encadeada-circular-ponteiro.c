#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prox;
    int valor;
} TipoNode;

typedef struct lista {
    TipoNode *inicio; //head
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
    //se não há nenhum nó na lista
    if (vazia(*lista)){
        lista->inicio = malloc(sizeof(TipoNode));
        lista->inicio->valor=item;
        lista->inicio->prox=lista->inicio; //no caso do primeiro nó inserido, o prox dele é ele mesmo
    }else{
        TipoNode *prox = lista->inicio;
        while(prox->prox != lista->inicio){ //enquanto o próximo não é o primeiro (o último aponta para o primeiro)
            prox = prox->prox;
        }
        //chegou ao último elemento da lista

        TipoNode *novo = malloc(sizeof(TipoNode));
        prox->prox = novo;
        novo->valor = item;
        novo->prox = lista->inicio;
    }
    lista->tamanho++;
}

void insere(int item, int pos, Lista *lista){
    if (pos > lista->tamanho){
        printf("Impossível inserir pois posição <%d> é maior que tamanho <%d>", pos, lista->tamanho);
    }else {
        TipoNode *novo = malloc(sizeof(TipoNode));
        novo->valor = item;
        novo->prox = NULL;

        if(pos==1){
            novo->prox = lista->inicio;

            //devemos fazer o último apontar para o novo primeiro
            TipoNode *aux = lista->inicio;
            while(aux->prox != lista->inicio){ //enquanto o próximo não é o primeiro (o último aponta para o primeiro)
                aux = aux->prox;
            }
            //ao final do while, aux contém o último nó da lista
            lista->inicio = novo;
            aux->prox = lista->inicio;
        }else{
            int aux = 2;
            TipoNode *node;
            node = lista->inicio;

            while(aux < pos){
                node = node->prox;
                aux++;
            }

            novo->prox = node->prox;
            node->prox = novo;
            lista->tamanho++;
        }
    }
}

void remover(int pos, Lista *lista){
    if(pos == 1){
        TipoNode *n = lista->inicio;
        lista->inicio = lista->inicio->prox;
        lista->tamanho--;
        free(n);
    }else{
        int aux = 2;
        TipoNode *node = lista->inicio;
        while (aux < pos){
            aux = aux + 1;
            node = node->prox;
        }

        TipoNode *remover = node->prox;
        node->prox = node->prox->prox;
        free(remover);
    }
}

void imprime(Lista lista){
    TipoNode *node = lista.inicio;
    do{
        printf("%d ", node->valor);
        node = node->prox;
    }while(node->prox != lista.inicio);
    printf("%d ", node->valor);
    printf("\n");
}

int main() {
    Lista lista;
    FLVazia(&lista);
    insereFim(1, &lista);
    insereFim(3, &lista);
    insereFim(-1, &lista);
    insereFim(5, &lista);
    insere(10,2,&lista);
    insere(11,1,&lista);
    imprime(lista);
    //remover(3, &lista);
    //imprime(lista);
}
