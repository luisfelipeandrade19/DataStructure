#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

typedef struct { 
    int* dados;     
    int tamanho;   
    int capacidade;
    }Lista;

Lista* criarLista(int capacidade);

int tamanho(Lista* lista);

int inserirFim(Lista* lista, int valor);

int inserirPosicao(Lista* lista, int valor, int posicao);

void removerPosicao(Lista* lista, int posicao);

void removerValor(Lista* lista, int valor);

int obterPosicao(Lista* lista, int posicao);

int obterValor(Lista* lista, int valor);

void exibir(Lista* lista);

#endif 