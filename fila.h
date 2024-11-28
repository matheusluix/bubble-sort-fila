typedef struct no No;
struct no {
    int idade;
    No *proximo;
    No *anterior;
};

typedef struct lista
{
    No *primeiro;
    No *ultimo;
}Lista;




Lista* cria_lista (void);

void insere_lista(Lista *l, int valor);

void bubble_sort(Lista *l);

void imprime_lista(Lista *l);

void verifica_lista_vazia(Lista *l);
