#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

Lista* criarLista(int capacidade) {
    Lista* lista = (Lista*) malloc(sizeof(Lista));

    if (lista == NULL) {
        printf("Erro na alocação de memória para a Lista!\n");
        exit(1);
    }

    lista->dados = (int*) malloc(capacidade * sizeof(int)); // Use a capacidade fornecida
    if (lista->dados == NULL) {
        printf("Erro na alocação de memória para os Dados!\n");
        free(lista);
        exit(1);
    }
    lista->tamanho = 0;
    lista->capacidade = capacidade;

    return lista;
}

int tamanho(Lista* lista) {
    return lista->tamanho;
}

int inserirFim(Lista* lista, int valor) {
    if (lista->tamanho >= lista->capacidade) {
        printf("Erro! A Lista já está cheia!\n");
        return -1;
    }
    lista->dados[lista->tamanho] = valor;
    lista->tamanho++;
    return 0;
}

int inserirPosicao(Lista* lista, int valor, int posicao) {
    if (lista->tamanho >= lista->capacidade) {
        printf("Erro! A Lista já está cheia!\n");
        return -1;
    }
    if (posicao < 0 || posicao > lista->tamanho) {
        printf("Posição inválida\n");
        return -1;
    }
    for (int j = lista->tamanho; j > posicao; j--) {
        lista->dados[j] = lista->dados[j - 1];
    }
    lista->dados[posicao] = valor;
    lista->tamanho++;
    return 0;
}

void removerPosicao(Lista* lista, int posicao) {
    if (lista->tamanho <= 0) {
        printf("Erro! A lista está vazia!\n");
        return;
    }
    if (posicao >= lista->tamanho || posicao < 0) {
        printf("Erro! Posição inválida!\n");
        return;
    }
    for (int j = posicao; j < lista->tamanho - 1; j++) {
        lista->dados[j] = lista->dados[j + 1];
    }
    lista->tamanho--;
}

void removerValor(Lista* lista, int valor) {
    if (lista->tamanho <= 0) {
        printf("Erro! A lista está vazia!\n");
        return;
    }

    int posicao = -1;
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->dados[i] == valor) {
            posicao = i;
            break;
        }
    }
    if (posicao == -1) {
        printf("Erro, o valor não foi encontrado na lista!\n");
        return;
    }

    for (int j = posicao; j < lista->tamanho - 1; j++) {
        lista->dados[j] = lista->dados[j + 1];
    }
    lista->tamanho--;
}

int obterPosicao(Lista* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Erro! Posição inválida!\n");
        return -1;
    }

    printf("Valor que está na posição %d: %d\n", posicao, lista->dados[posicao]);
    return lista->dados[posicao];
}

int obterValor(Lista* lista, int valor) {
    if (lista->tamanho <= 0) {
        printf("Erro! A lista está vazia!\n");
        return -1;
    }

    int aux = -1;
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->dados[i] == valor) {
            aux = i;
            break;
        }
    }
    if (aux == -1) {
        printf("Erro, o valor não foi encontrado na lista!\n");
        return -1;
    }

    printf("O valor pedido: %d\n", aux);
    return aux;
}

void exibir(Lista* lista) {
    if (lista->tamanho <= 0) {
        printf("Erro! A lista está vazia\n");
        return;
    }

    for (int i = 0; i < lista->tamanho; i++) {
        printf("[%d] ", lista->dados[i]);

        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}
