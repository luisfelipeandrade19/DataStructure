
#include "Pilha.h"

typedef struct nodo Nodo;
typedef struct filaDePilhas FilaDePilhas;

FilaDePilhas* criarFilaDePilhas();

void enfileirarPilha(FilaDePilhas* fila, Pilha* pilha);

Pilha* desenfileirarPilha(FilaDePilhas* fila);

Pilha* primeiraPilha(FilaDePilhas* fila);

int tamanhoFila(FilaDePilhas* fila);

int filaEstaVazia(FilaDePilhas* fila);

void liberarFilaDePilhas(FilaDePilhas* fila);

