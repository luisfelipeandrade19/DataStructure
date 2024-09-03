#include <stdio.h>
#include <stdlib.h>
#include "Pilha.c"

int main(int argc, char const *argv[]) {
    int escolha = 0;
    Pilha* l = criaPilha();

    printf("Ola! Este programa serve para criar e manipular uma Pilha!\n");

    do {
        printf("\n\nO que deseja fazer?\n"
               "1- Criar Pilha\n"
               "2- Verificar se a pilha esta vazia\n"
               "3- Inserir elemento\n"
               "4- Remover elemento\n"
               "5- Liberar pilha\n"
               "6- Imprimir\n"
               "7- Encerrar programa\n\n");

        scanf("%d", &escolha);

        int valor = 0;

        switch (escolha) {
            case 1:
                l = criaPilha();
                printf("Pilha criada com sucesso!\n");
                break;

            case 2:
                if (pilhaVazia(l)) {
                    printf("A pilha está vazia!\n");
                } else {
                    printf("A pilha não está vazia!\n");
                }
                break;

            case 3:
                printf("Qual elemento deseja inserir?\n");
                scanf("%d", &valor);  
                push(l, valor);
                break;

            case 4:
                pop(l);
                printf("Elemento removido!\n");
                break;

            case 5:
                pilhaLibera(l);
                printf("Pilha liberada!\n");
                break;

            case 6:
                pilhaImprime(l);
                break;
               
            case 7:
                escolha = 7;
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (escolha != 7);

    return 0;
}
