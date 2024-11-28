#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Lista* cria_lista(void) {

    Lista *l = (Lista*) malloc(sizeof(Lista));
    
    if(l == NULL){
        printf("Nao foi possivel criar a lista\n");
        exit(1);
    }

    l->primeiro = NULL;
    l->ultimo = NULL;

    return l;
}

void insere_lista(Lista *l, int valor) {
    No *novoNo = (No*) malloc(sizeof(No));

    if(novoNo == NULL){
        printf("Nao foi possivel criar o novo no\n");
        exit(1);
    }

    novoNo->idade = valor;

    novoNo->proximo = l->primeiro;
    novoNo->anterior = NULL;

}

void imprime_lista(Lista *l) {

    for(No *cont = l->primeiro; cont != NULL; cont = cont->proximo){
        printf("%d ", cont->idade);
    }

}

void verifica_lista_vazia(Lista *l) {
    if(l->primeiro == NULL|| l->ultimo == NULL){
        printf("A lista esta vazia...\n");
    }
}