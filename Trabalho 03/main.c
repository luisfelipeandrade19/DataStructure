#include <stdio.h>
#include <stdlib.h>
#include "ListaSE.c"

int main(int argc, char const *argv[]) {
    int escolha = 0;
    Lista* l = criarLista();

    printf("Ola! Este programa serve para criar e manipular uma Lista Encadeada Simples!\n");

    do {
        printf("\n\nO que deseja fazer?\n"
               "1- Criar Lista\n"
               "2- Exibir tamanho da lista\n"
               "3- Inserir elemento na lista\n"
               "4- Remover elemento\n"
               "5- Obter posicao de valor desejado\n"
               "6- Obter elemento pelo valor\n"
               "7- Exibir lista\n"
               "8- Encerrar Programa\n");

        scanf("%d", &escolha);

        int valor = 0;
        int posicao = 0;

        switch (escolha) {
            case 1:
                l = criarLista();
                printf("Lista criada com sucesso!\n");
                break;

            case 2:
                printf("Tamanho da lista: %d\n", tamanho(l));
                break;

            case 3:
                printf("1- Inserir valor na posicao desejada\n"
                       "2- Inserir no fim da lista\n"
                       "3- Inserir no comeco\n");
                scanf("%d", &valor);
                if (valor == 1) {
                    printf("Qual valor deseja inserir?\n");
                    scanf("%d", &valor);
                    printf("Qual a posicao que deseja inserir esse valor?\n");
                    scanf("%d", &posicao);
                    l = inserePosicao(l, valor, posicao);
                    printf("Elemento inserido com sucesso!\n");
                } else if (valor == 2) {
                    printf("Qual valor deseja inserir?\n");
                    scanf("%d", &valor);
                    l = insereFinal(l, valor);
                    printf("Elemento inserido com sucesso!\n");
                } else if (valor == 3) {
                    printf("Qual valor deseja inserir?\n");
                    scanf("%d", &valor);
                    l = insere(l, valor);
                    printf("Elemento inserido com sucesso!\n");
                } else {
                    printf("Escolha nao existe!\n");
                }
                break;

            case 4:
                printf("1- Remover elemento da posicao desejada\n"
                       "2- Remover elemento pelo valor\n");
                scanf("%d", &valor);
                if (valor == 1) {
                    printf("Qual a posicao que deseja remover o valor?\n");
                    scanf("%d", &posicao);
                    l = removePosicao(l, posicao);
                    printf("Elemento removido\n");
                } else if (valor == 2) {
                    printf("Qual valor deseja remover?\n");
                    scanf("%d", &valor);
                    l = removeValor(l, valor);
                    printf("Elemento removido\n");
                } else {
                    printf("Escolha nao existe!\n");
                }
                break;

            case 5:
                printf("Qual posicao deseja obter?\n");
                scanf("%d", &posicao);
                Lista* pos = obterPosicao(l, posicao);
                if (pos != NULL) {
                    printf("Valor na posicao %d: %d\n", posicao, pos->info);
                }
                break;

            case 6:
                printf("Qual valor deseja procurar?\n");
                scanf("%d", &valor);
                Lista* elem = procurar(l, valor);
                if (elem != NULL) {
                    printf("Valor %d encontrado na lista.\n", valor);
                }
                break;

            case 7:
                printf("Lista:\n");
                imprimir(l);
                break;

            case 8:
                escolha = 8;
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (escolha != 8);

    return 0;
}
