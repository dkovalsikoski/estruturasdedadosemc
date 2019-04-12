#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
        int valor;
        struct Node *prox;
}no;

typedef struct Lista{
        no *inicio;
        no *fim;
}lista;

void lista_vazio(lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
}

void insere_lista_vazia(lista *lista, int valor){
    //aloca espaço para o novo nó
    lista->inicio=malloc(sizeof(no));
    //define o ponteiro lista inicio para nulo
    lista->inicio->prox=NULL;
    //recebe o valor
    lista->inicio->valor=valor;
    //diz que o lista fim é o mesmo que o incio porque só tem ele
    lista->fim=lista->inicio;
}

void insere_inicio(lista *lista, int valor){
    if(lista->inicio==NULL){
        insere_lista_vazia(lista, valor);
    } else {
        //aloca espaço pro novo nó
        no *novoNo = malloc(sizeof(no));
        //define um valor
        novoNo->valor=valor;
        //novo nó aponta para lista inicio
        novoNo->prox=lista->inicio;
        //define o novo nó como lista inicio
        lista->inicio=novoNo;
    }
}
void insere_fim(lista *lista, int valor){
    if(lista->inicio==NULL){
        insere_lista_vazia(lista,valor);
    } else {
        //aloca o novo nó
        no *novoNo = malloc(sizeof(no));
        novoNo->prox = NULL;
        novoNo->valor = valor;

        //cria um ponteiro de verificção que aponta para o inicio da lista
        no *tmp = lista->inicio->prox;

        while (tmp->prox != NULL)
            //enquanto a parada aqui não for nula ele percorre
            tmp = tmp->prox;
        tmp->prox = novoNo;
        lista->fim->prox = novoNo;
        lista->fim = novoNo;

    }
}



void imprime_lista(lista lista){
    no *tmp = lista.inicio;
    while(tmp!=NULL){
        printf("%d\n", tmp->valor);
        tmp=tmp->prox;

    }
}


int main()
{
    lista lista;
    lista_vazio(&lista);
    insere_inicio(&lista, 3);
    insere_inicio(&lista,4);
    insere_fim(&lista, 7);
    imprime_lista(lista);
    return 0;
}
