#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 1000
#define INICIO 0
#define NAO_INICIALIZADO -1

typedef struct tipo_lista {
    int valores[TAMANHO_MAX];
    int fim;
} TipoLista;

void FLVazia(TipoLista *lista){
    lista->fim = NAO_INICIALIZADO;
}

int vazia(TipoLista lista){
    return lista.fim == NAO_INICIALIZADO;
}

void insereFim(int item, TipoLista *lista){
    lista->fim = lista->fim + 1;
    lista->valores[lista->fim] = item;
}

void insere(int item, int pos, TipoLista *lista){
    int aux;
    for (int i=lista->fim+1; i>pos; i--){
        lista->valores[i] = lista->valores[i-1];
    }
    lista->valores[pos] = item;
    lista->fim = lista->fim + 1;
}

void imprime(TipoLista lista){
    if (!vazia(lista)){
        int index = INICIO;
        int value = lista.valores[index];
        while (index <=  lista.fim){
            index = index + 1;
            printf("%d ", value);
            value = lista.valores[index];
        }
        printf("\n");
    } else {
        printf("Lista vazia\n");
    }
}

int retira(int pos, TipoLista *lista){
    int valor = lista->valores[pos];
    for (int i=pos; i < lista->fim; i++){
        lista->valores[pos]=lista->valores[pos+1];
    }
    lista->fim = lista->fim - 1;
    return valor;
}

int main(){
    TipoLista lista;
    FLVazia(&lista);
    if (vazia(lista)){
        printf("A lista está vazia.\n");
    }else{
        printf("A lista não está vazia.\n");
    }

    insereFim(10, &lista);
    insereFim(1, &lista);
    insereFim(100, &lista);
    insere(99,1,&lista);
    imprime(lista);
    insere(88,0,&lista);
    imprime(lista);
    retira(3, &lista);
    imprime(lista);
}
