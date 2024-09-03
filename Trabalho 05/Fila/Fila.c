#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "Pilha.h"

struct nodo {
    Pilha* pilha;
    Nodo* proximo;
};

struct filaDePilhas {
    Nodo* frente;
    Nodo* tras;
    int tamanho;
};

FilaDePilhas* criarFilaDePilhas() {
    FilaDePilhas* fila = (FilaDePilhas*)malloc(sizeof(FilaDePilhas));
    fila->frente = fila->tras = NULL;
    fila->tamanho = 0;
    return fila;
}

void enfileirarPilha(FilaDePilhas* fila, Pilha* pilha) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    novoNodo->pilha = pilha;
    novoNodo->proximo = NULL;
    if (fila->tras == NULL) {
        fila->frente = fila->tras = novoNodo;
    } else {
        fila->tras->proximo = novoNodo;
        fila->tras = novoNodo;
    }
    fila->tamanho++;
}

Pilha* desenfileirarPilha(FilaDePilhas* fila) {
    if (fila->frente == NULL) {
        printf("Fila vazia\n");
        return NULL;
    }
    Nodo* nodoRemovido = fila->frente;
    Pilha* pilhaRemovida = nodoRemovido->pilha;
    fila->frente = fila->frente->proximo;
    if (fila->frente == NULL) {
        fila->tras = NULL;
    }
    free(nodoRemovido);
    fila->tamanho--;
    return pilhaRemovida;
}

Pilha* primeiraPilha(FilaDePilhas* fila) {
    if (fila->frente == NULL) {
        printf("Fila vazia\n");
        return NULL;
    }
    return fila->frente->pilha;
}

int tamanhoFila(FilaDePilhas* fila) {
    return fila->tamanho;
}

int filaEstaVazia(FilaDePilhas* fila) {
    return fila->tamanho == 0;
}

void liberarFilaDePilhas(FilaDePilhas* fila) {
    while (!filaEstaVazia(fila)) {
        Pilha* pilha = desenfileirarPilha(fila);
        pilhaLibera(pilha);
    }
    free(fila);
}
