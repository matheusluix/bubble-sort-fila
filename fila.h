// Estrutura que representa um nó de uma lista duplamente encadeada.
typedef struct no No;
struct no {
    int idade;         // Valor inteiro armazenado no nó (neste caso, a idade do cliente).
    No *proximo;       // Ponteiro para o próximo nó da lista.
    No *anterior;      // Ponteiro para o nó anterior da lista.
};

// Estrutura que representa uma lista duplamente encadeada.
typedef struct lista {
    No *primeiro;      // Ponteiro para o primeiro nó da lista.
    No *ultimo;        // Ponteiro para o último nó da lista.
} Lista;

/*
    Cria e inicializa uma lista vazia. 
    Retorna um ponteiro para a estrutura Lista recém-criada. A lista será inicialmente vazia,
    com os ponteiros `primeiro` e `ultimo` definidos como NULL.
 */
Lista* cria_lista(void);

/*
    Verifica se a lista está vazia. 
    Parametrôs: lst Ponteiro para a lista que será verificada.
    Retorna 1 (verdadeiro) se a lista estiver vazia, ou 0 (falso) caso a lista tenha pelo menos um elemento.
 */
int verifica_lista_vazia(const Lista *lst);

/* 
    A função insere um novo nó no inicio da lista.
    Parâmetro: 'Lista *lst' - Ponteiro para a lista onde o nó será inserido.
    Parâmetro: 'int valor' - Valor inteiro (idade) a ser armazenado no novo nó.
    A função cria um novo nó contendo o valor especificado e o adiciona como o primeiro
    elemento da lista. Atualiza os ponteiros da lista e do nó conforme o necessário.
 */
void insere_inicio_lista(Lista *lst, int valor);

/*

  A função insere um novo nó no final da lista. 
  Parâmetro: 'Lista *lst' - Ponteiro para a lista onde o nó será inserido.
  Parâmetro: 'int valor' - Valor inteiro (idade) a ser armazenado no novo nó.
  A função cria um novo nó contendo o valor especificado e o adiciona como o último
  elemento da lista. Atualiza os ponteiros da lista e do nó conforme necessário.
 */
void insere_final_lista(Lista *lst, int valor);

/*

    Lê valores inteiros de um arquivo texto e os insere sempre no final da lista.
    Parâmetro: 'const char* nomeArquivo' - Nome do arquivo texto que contém os valores.
    Parâmetro: 'Lista *lista' - Ponteiro para a lista onde os valores serão inseridos.
    O arquivo deve conter um número inteiro por linha. A função lê cada valor e o adiciona
    ao final da lista usando a função `insere_final_lista`.
 */
void lerArquivo(const char *nomeArquivo, Lista* lista);

/*
    Imprime todos os valores armazenados na lista.
    Parâmetro: 'Lista *lst' - Ponteiro para a lista cujos elementos serão exibidos.
    A função percorre a lista do início ao fim, imprimindo os valores armazenados em cada nó.
 */
void imprime_lista(Lista *lst);

/*
    Realiza a troca de posição entre um nó atual e o próximo nó na lista. 
    Parâmetro: 'Lista *lst' - Ponteiro para a lista onde a troca será realizada.
    Parâmetro: 'No *atual' - Ponteiro para o nó atual que será trocado com o próximo.
    A função ajusta os ponteiros do nó atual, do próximo nó e de seus vizinhos para
    realizar a troca de posição, preservando a integridade e encadeamento da lista duplamente encadeada.
 */
void troca_no(Lista *lst, No *atual);

/*
    Ordena os elementos da lista em ordem decrescente usando Bubble Sort. 
    Parâmetro: 'Lista *lst' - Ponteiro para a lista que será ordenada.
    A função utiliza o algoritmo Bubble Sort para ordenar os nós da lista com base no valor
    armazenado em cada nó (neste caso, as idades). A ordenação é realizada diretamente nos nós,
    ajustando os ponteiros conforme necessário.
 */
void bubble_sort(Lista *lst);

/*
    Libera toda a memória alocada pela lista e destrói sua estrutura.
    Parâmetro: 'Lista *lst' - Ponteiro para a lista que será destruída.
    A função percorre todos os nós da lista, liberando a memória alocada para cada um deles.
    Por fim, libera a memória da própria estrutura Lista e define os ponteiros como NULL.
 */
void destroi_lista(Lista *lst);