#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Lista* cria_lista(void) {
    Lista *lst = (Lista*) malloc(sizeof(Lista));
    
    if(lst == NULL){
        printf("Nao foi possivel criar a lista\n");
        exit(1);
    }

    lst->primeiro = NULL;
    lst->ultimo = NULL;

    return lst;
}

int verifica_lista_vazia(const Lista *lst) {
    return(lst->primeiro == NULL && lst->ultimo == NULL);
}

void insere_inicio_lista(Lista *lst, int valor) {
    if (lst == NULL) {
        printf("A lista não foi inicializada.\n");
        exit(1);
    }

    No *novoNo = (No*) malloc(sizeof(No));
    if(novoNo == NULL){
        printf("Memória insuficiente.\n");
        exit(1);
    }

    novoNo->idade = valor;
    novoNo->proximo = lst->primeiro;
    novoNo->anterior = NULL;

    if(verifica_lista_vazia(lst)) {
        lst->ultimo = novoNo;
    }
    else {
        lst->primeiro->anterior = novoNo;
    }

    lst->primeiro = novoNo;
}

void insere_final_lista(Lista *lst, int valor) {
    if (lst == NULL) {
        printf("A lista não foi inicializada.\n");
        exit(1);
    }   

    No *novoNo = (No*) malloc(sizeof(No));
    if(novoNo == NULL) {
        printf("Memória insuficiente.\n");
        exit(1);
    }

    novoNo->idade = valor;
    novoNo->proximo = NULL;
    novoNo->anterior = lst->ultimo;

    if(verifica_lista_vazia(lst)){
        lst->primeiro = novoNo;
    }
    else{
        lst->ultimo->proximo = novoNo;
    }

    lst->ultimo = novoNo;
}

void lerArquivo(const char* nomeArquivo, Lista* lista) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    int idade;
    while (fscanf(arquivo, "%d", &idade) != EOF) {
        insere_final_lista(lista, idade);
    }

    fclose(arquivo);
}

void imprime_lista(Lista *lst) {
    if(lst == NULL) {
        printf("A lista nao foi inicializada.\n");
        exit(1);
    }

    if(verifica_lista_vazia(lst)) {
        printf("A lista esta vazia.\n");
    }

    for(No *cont = lst->primeiro; cont != NULL; cont = cont->proximo){
        printf("%d ", cont->idade);
    }

    printf("\n");
}

void troca_no(Lista *lst, No *atual) {
    No *prox = atual->proximo; // Próximo nó em relação ao atual.

    // Troca no início da lista
    if(atual == lst->primeiro) {
        No *proxDoProx = prox->proximo; // Próximo do próximo nó do nó atual.

        prox->anterior = NULL;
        prox->proximo = atual;

        atual->anterior = prox;
        atual->proximo = proxDoProx;

        if(proxDoProx != NULL) {
            proxDoProx->anterior = atual;
        } else {
            lst->ultimo = atual; // Caso a lista tenha apenas dois nós, o 'atual' será o último.
        }

        lst->primeiro = prox; // Atualiza o primeiro nó da lista.
    }
    // Troca no final da lista (penúltimo nó)
    else if(atual == lst->ultimo->anterior) {
        No *ant = atual->anterior; // Nó anterior em relação ao atual.

        atual->proximo = NULL;
        atual->anterior = prox;

        prox->proximo = atual;
        prox->anterior = ant;

        if(ant != NULL) {
            ant->proximo = prox;
        } else {
            lst->primeiro = prox; // Caso a lista tenha apenas dois nós, o 'prox' será o primeiro.
        }

        lst->ultimo = atual; // Atualiza o último nó da lista.
    }
    // Troca no meio da lista
    else {
        No *ant = atual->anterior; // Nó anterior em relação ao atual.

        ant->proximo = prox;            // O nó anterior ao 'atual' agora aponta para 'prox'.
        prox->anterior = ant;           // O 'prox' agora aponta para 'ant'.

        atual->proximo = prox->proximo; // O 'atual' aponta para o próximo de 'prox'.
        atual->anterior = prox;         // O 'atual' aponta para 'prox'.

        if(prox->proximo != NULL) {     // Caso haja um nó após 'prox'.
            prox->proximo->anterior = atual;  // O próximo nó agora aponta para 'atual'.
        } else {
            lst->ultimo = atual;  // Caso 'prox' fosse o último nó, o 'atual' se torna o último.
        }

        prox->proximo = atual;  // O 'prox' agora aponta para o 'atual'.
    }
}

void bubble_sort(Lista *lst) {
    int trocou; //Essa variável serve para nos informar se houve troca ou não.
    No *atual;

    do {
        trocou = 0;
        atual = lst->primeiro;

        while(atual != NULL && atual->proximo != NULL) {
            if(atual->idade < atual->proximo->idade) {
                troca_no(lst, atual);
                trocou = 1;
            }
            atual = atual->proximo;
        }

    }while (trocou);
}


void destroi_lista(Lista *lst) {
    if (lst == NULL) {
        printf("A lista não foi inicializada.\n");
        exit(1);
    }

    No *atual = lst->primeiro;

    while (atual != NULL) {
        No *temp = atual->proximo;
        free(atual);
        atual = temp;
    }
    free(lst);
    lst = NULL;

    printf("Lista destruida.\n");
}