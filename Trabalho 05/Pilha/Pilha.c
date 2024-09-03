#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

#define TAM 50

struct pilha{
    int qtdeItens;
    float vet[TAM];
};

Pilha* criaPilha(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->qtdeItens = 0; 
    return p;
}

void push(Pilha *p, float valor){

    if(p->qtdeItens == TAM){
        printf("Pilha esta cheia");
        exit(1);
    }

    p->vet[p->qtdeItens] = valor;
    p->qtdeItens++;
}

int pilhaVazia(Pilha *p){
    return (p->qtdeItens == 0);
}

float pop(Pilha *p){
    float topo;
    if(pilhaVazia(p)){
        printf("Pilha vazia!");
        exit(1);
    }

    topo = p->vet[p->qtdeItens - 1];
    p->qtdeItens--;
    return topo;
}

void pilhaLibera(Pilha *p){
    free(p);
}

void pilhaImprime(Pilha *p){
    for (int i = (p->qtdeItens - 1); i >= 0; i--){
    printf("%.1f\n",p->vet[i]);
    }
}