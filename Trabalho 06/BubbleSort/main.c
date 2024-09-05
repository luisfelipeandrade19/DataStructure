#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sorts.c"

int gerador(){
 srand(time(NULL));
 return rand() % 1000;
}


int main(int argc, char const *argv[])
{
    int escolha;
    printf("-------------------------\n");
    printf("-Algoritmos de Ordenacao-\n");
    printf("-------Bubble Sort-------\n");
    printf("-------------------------\n\n");

    printf("1- Gerar Array de forma aleatoria\n"
           "2- Gerar Array de forma ordenada\n"
           "3- Gerar Array de forma reversamente ordenada\n"
           "4- Encerrar programa\n\n");
    scanf("%d", &escolha);

    do
    {
        switch (escolha)
        {
            case 1:
            printf("-------------------------\n");
            printf("Gerando Aleatoriamente...\n");
            printf("-------------------------\n\n");
            int l;
            printf("Ordenar Array?\n"
                   "1- Sim\n"
                  "2- Nao\n\n");
                  scanf("%d", &l);
            if(l == 1){

                double tempo;
                clock_t inicio, fim;

                int n = 0;

                printf("Qual tamanho de Array que deseja gerar?\n");
                scanf("%d", &n);
                if(n <= 0){
                    printf("valor invalido!");
                    return;
                }

                int arr[n];

                inicio = clock();

                    gerarAleatorio(arr, n);
                    printArray(arr, n);

                    printf("-------------------------\n"
                           "--------Ordenando--------\n"
                           "-------------------------\n\n");
                    
                    bubbleSort(arr, n);

                    printf("Array ordenado: ");
                    printArray(arr, n);

                fim = clock();

                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nTempo gasto: %g s.\n", tempo);

            }
            break;
    
            default:
            break;
        }
    } while (escolha != 4);
    
    
    

    return 0;
}
