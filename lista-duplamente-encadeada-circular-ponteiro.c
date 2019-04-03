#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prox;
    struct node *ant;
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
        lista->inicio->ant=lista->inicio; //no caso do primeiro nó inserido, o ant dele é ele mesmo
    }else{
        TipoNode *ultimo = lista->inicio->ant;
        TipoNode *novo = malloc(sizeof(TipoNode));
        ultimo->prox = novo;
        novo->prox = lista->inicio;
        novo->ant = ultimo;
        lista->inicio->ant = novo;
        novo->valor = item;
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
            TipoNode *head = lista->inicio;
            novo->prox = head;
            novo->ant = head->ant;
            head->ant->prox = novo;
            head->ant = novo;
            lista->inicio = novo;
        }else{
            int aux = 2;
            TipoNode *node;
            node = lista->inicio;

            while(aux < pos){
                node = node->prox;
                aux++;
            }

            novo->prox = node->prox;
            novo->ant = node;
            node->prox = novo;
            lista->tamanho++;
        }
    }
}

void remover(int pos, Lista *lista){
    if(pos == 1){
        TipoNode *head = lista->inicio;
        lista->inicio = lista->inicio->prox; //novo primeiro recebe o segundo da lista
        lista->inicio->ant = head->ant; //faz o anterior do novo primeiro apontar para o anterior do antigo primeiro
        lista->inicio->ant->prox = lista->inicio; //faz o último apontar para o novo primeiro
        lista->tamanho--;
        free(head);
    }else{
        int aux = 2;
        TipoNode *node = lista->inicio;
        while (aux < pos){
            aux = aux + 1;
            node = node->prox;
        }

        TipoNode *remover = node->prox;
        node->prox = node->prox->prox;
        node->prox->ant = node->prox;
        free(remover);
    }
}

void imprime(Lista lista){
    TipoNode *node = lista.inicio;
    do{
        printf("%d ", node->valor);
        node = node->prox;
    }while(node->prox != lista.inicio);
    if (lista.tamanho > 1){
        printf("%d ", node->valor);
    }
    printf("\n");
}

int main() {
    Lista lista;
    FLVazia(&lista);
    insereFim(1, &lista);
    imprime(lista);
    insereFim(3, &lista);
    imprime(lista);
    insereFim(-1, &lista);
    imprime(lista);
    insereFim(5, &lista);
    imprime(lista);
    insere(10,2,&lista);
    imprime(lista);

    insere(11,1,&lista);
    imprime(lista);

    remover(3, &lista);
    imprime(lista);    
}
