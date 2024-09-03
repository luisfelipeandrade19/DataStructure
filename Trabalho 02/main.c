#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

void bold(int status) {
    static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
    printf("%s", seq[!!status]);
}

int main(int argc, char const *argv[]) {
    int escolha = 0;
    Lista* lista = 0;

    printf("Olá! Este programa serve para criar e manipular uma Lista Linear Sequencial!");
    
    do{
    printf("\n\nO que deseja fazer?\n"
           "1- Criar Lista\n"
           "2- Exibir tamanho da lista\n"
           "3- Inserir elemento na lista\n"
           "4- Remover elemento\n"
           "5- Obter posição de valor desejado\n"
           "6- Obter elemento pelo valor\n"
           "7- Exibir lista\n"
           "8- Encerrar Programa\n");

    scanf("%d", &escolha);

    int valor = 0;
    int posicao = 0;

    switch (escolha) {
    case 1:
        lista  = criarLista(50);
        printf("Lista criada com capacidade para 50 elementos.\n");
        break;

    case 2:
        printf("Tamanho da lista: %d\n", tamanho(lista));
        break;

    case 3:
        printf("1- Inserir valor na posição desejada\n"
               "2- Inserir no fim da lista\n");
        scanf("%d", &valor);
        if (valor == 1) {
            printf("Qual valor deseja inserir?\n");
            scanf("%d", &valor);
            printf("Qual a posição que deseja inserir esse valor?\n");
            scanf("%d", &posicao);

            inserirPosicao(lista, valor, posicao);
            printf("Elemento inserido com sucesso!\n");
        } else if (valor == 2) {
            printf("Qual valor deseja inserir?\n");
            scanf("%d", &valor);

            inserirFim(lista, valor);
        } else {
            printf("Escolha não existe!\n");
            exit(1);
        }
        break;

    case 4:
        printf("1- Remover elemento da posição desejada\n"
               "2- Remover elemento pelo valor\n");
        scanf("%d", &valor);
        if (valor == 1) {
            printf("Qual a posição que deseja remover o valor?\n");
            scanf("%d", &posicao);

            removerPosicao(lista, posicao);
            printf("Elemento removido\n");
        } else if (valor == 2) {
            printf("Qual valor deseja remover?\n");
            scanf("%d", &valor);

            removerValor(lista, valor);
            printf("Elemento removido\n");
        } else {
            printf("Escolha não existe!\n");
            exit(1);
        }
        break;

    case 5:
        printf("Qual valor deseja obter a posição?\n");
        scanf("%d", &valor);

        printf("A posição do %d: %d\n", valor, obterPosicao(lista, valor));
        break;

    case 6:
        printf("Qual elemento deseja obter?\n");
        scanf("%d", &valor);

        printf("O valor: %d\n", obterValor(lista, valor));
        break;

    case 7:
        exibir(lista);
        break;

    case 8:
        escolha = 8;
    break;

    default:
        printf("Erro! Alternativa não encontrada!\n");
        break;
    }

    }while(escolha != 8);



    return 0;
}
