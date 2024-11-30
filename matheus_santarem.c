#include "fila.h"
#include <stdio.h>

int main(void) {

    Lista *lst = cria_lista();

    lerArquivo("clientes.txt", lst);

    printf("Fila original:\n");
    imprime_lista(lst);

    bubble_sort(lst);
    if(verifica_lista_vazia(lst)){
        printf("A fila esta vazia, nao ha nada para ordenar aqui.\n");
    }
    else if(lst->primeiro->proximo == NULL){
        printf("A fila so tem uma pessoa, nao ha nada para ordenar aqui.\n");
        printf("Idade da unica pessoa da fila: %d.\n", lst->primeiro->idade);
        
    }
    else{
        printf("Fila ordenada:\n");
        imprime_lista(lst);
    }

    destroi_lista(lst);
    
    return 0;
}