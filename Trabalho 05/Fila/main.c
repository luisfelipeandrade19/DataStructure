#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "Fila.h"

int main(int argc, char const *argv[]) {
    int escolha = 0;
    FilaDePilhas* p = criarFilaDePilhas();

    printf("Ola! Este programa serve para criar e manipular uma Fila de Pilhas!\n");

    do {
        printf("\n\nO que deseja fazer?\n"
               "1- Criar Fila\n"
               "2- Verificar se a fila esta vazia\n"
               "3- Enfileirar Fila\n"
               "4- Desenfileirar Fila\n"
               "5- Primeira Fila\n"
               "6- Tamanho da Fila\n"
               "7- Imprimir Fila\n"
               "8- Liberar Fila\n"
               "9- Encerrar programa\n");

        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                liberarFilaDePilhas(p); 
                p = criarFilaDePilhas();
                printf("Fila criada com sucesso!\n");
                break;

            case 2:
                if (filaEstaVazia(p)) {
                    printf("A fila esta vazia!\n");
                } else {
                    printf("A fila nao está vazia!\n");
                }
                break;

            case 3: {
                Pilha* novaPilha = criaPilha();
                int valor;
                printf("Quantos elementos deseja empilhar?\n");
                int numElementos;
                scanf("%d", &numElementos);
                for (int i = 0; i < numElementos; i++) {
                    printf("Digite o valor %d: ", i + 1);
                    scanf("%d", &valor);
                    push(novaPilha, valor);
                }
                enfileirarPilha(p, novaPilha);
                printf("Pilha enfileirada com sucesso!\n");
                break;
            }

            case 4: {
                Pilha* removida = desenfileirarPilha(p);
                if (removida) {
                    printf("Pilha removida com sucesso!\n");
                    pilhaLibera(removida);  
                } else {
                    printf("Nao ha pilhas para remover!\n");
                }
                break;
            }

            case 5: {
                Pilha* primeira = primeiraPilha(p);
                if (primeira) {
                    printf("Primeira pilha na fila:\n");
                    pilhaImprime(primeira);
                } else {
                    printf("A fila esta vazia!\n");
                }
                break;
            }

            case 6:
                printf("Tamanho da fila: %d\n", tamanhoFila(p));
                break;
               
            case 7: {
                if (filaEstaVazia(p)) {
                    printf("A fila esta vazia!\n");
                } else {
                    printf("Imprimindo todas as pilhas na fila:\n");
                    FilaDePilhas* tempFila = criarFilaDePilhas();
                    while (!filaEstaVazia(p)) {
                        Pilha* tempPilha = desenfileirarPilha(p);
                        pilhaImprime(tempPilha);
                        enfileirarPilha(tempFila, tempPilha);
                    }
                    liberarFilaDePilhas(p);
                    p = tempFila;
                }
                break;
            }

            case 8:
                liberarFilaDePilhas(p);
                p = criarFilaDePilhas();
                printf("Fila liberada!\n");
                break;

            case 9:
                liberarFilaDePilhas(p);
                printf("Programa encerrado!\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (escolha != 9);

    return 0;
}
