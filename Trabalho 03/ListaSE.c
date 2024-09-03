#include <stdio.h>
#include <stdlib.h>
#include "ListaSE.h"

Lista* criarLista() {
    return NULL;
}

Lista* insere(Lista* l, int i) {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if (lista == NULL) {
        printf("Erro na alocacao de memoria!\n");
        exit(1);
    }
    lista->info = i;
    lista->prox = l;
    return lista;
}

Lista* insereFinal(Lista* l, int i) {
    Lista* nova = (Lista*) malloc(sizeof(Lista));
    if (nova == NULL) {
        printf("Erro na alocacao de memoria!\n");
        exit(1);
    }
    nova->info = i;
    nova->prox = NULL;

    if (l == NULL) {
        return nova;
    }

    Lista* p = l;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = nova;
    return l;
}

Lista* inserePosicao(Lista* l, int i, int p) {
    Lista* nova = (Lista*) malloc(sizeof(Lista));
    if (nova == NULL) {
        printf("Erro na alocacao de memoria!\n");
        exit(1);
    }
    nova->info = i;

    if (p == 0) {
        nova->prox = l;
        return nova;
    }

    Lista* k = l;
    for (int j = 0; j < p - 1; j++) {
        if (k == NULL) {
            printf("Posicao invalida!\n");
            free(nova);
            return l;
        }
        k = k->prox;
    }

    if (k == NULL) {
        printf("Posicao invalida!\n");
        free(nova);
        return l;
    }

    nova->prox = k->prox;
    k->prox = nova;
    return l;
}

Lista* removePosicao(Lista* l, int p) {
    if (l == NULL) {
        printf("A lista esta vazia!\n");
        return l;
    }

    Lista* k = l;
    if (p == 0) {
        l = l->prox;
        free(k);
        return l;
    }

    for (int i = 0; i < p - 1; i++) {
        if (k == NULL || k->prox == NULL) {
            printf("Posicao invalida!\n");
            return l;
        }
        k = k->prox;
    }

    if (k == NULL || k->prox == NULL) {
        printf("Posicao invalida!\n");
        return l;
    }

    Lista* temp = k->prox;
    k->prox = temp->prox;
    free(temp);
    return l;
}

Lista* removeValor(Lista* l, int i) {
    if (l == NULL) {
        printf("A lista esta vazia!\n");
        return l;
    }

    Lista* k = l;
    Lista* anterior = NULL;

    while (k != NULL && k->info != i) {
        anterior = k;
        k = k->prox;
    }

    if (k == NULL) {
        printf("O valor nao foi encontrado!\n");
        return l;
    }

    if (anterior == NULL) {
        l = k->prox;
    } else {
        anterior->prox = k->prox;
    }

    free(k);
    return l;
}

Lista* obterPosicao(Lista* l, int p) {
    if (l == NULL) {
        printf("A lista esta vazia!\n");
        return NULL;
    }

    if (p < 0) {
        printf("Posicao invalida!\n");
        return NULL;
    }

    Lista* k = l;
    for (int j = 0; j < p; j++) {
        if (k == NULL) {
            printf("Posicao invalida!\n");
            return NULL;
        }
        k = k->prox;
    }
    return k;
}

Lista* procurar(Lista* l, int i) {
    if (l == NULL) {
        printf("A lista esta vazia!\n");
        return NULL;
    }

    Lista* k = l;
    while (k != NULL && k->info != i) {
        k = k->prox;
    }

    if (k == NULL) {
        printf("O valor nao foi encontrado!\n");
        return NULL;
    }
    return k;
}

void imprimir(Lista* l) {
    if (l == NULL) {
        printf("A lista esta vazia!\n");
        return;
    }

    Lista* k = l;
    while (k != NULL) {
        printf("[%d] ", k->info);
        k = k->prox;
    }
    printf("\n");
}

int tamanho(Lista* l) {
    int tamanho = 0;
    Lista* k = l;
    while (k != NULL) {
        tamanho++;
        k = k->prox;
    }
    return tamanho;
}
