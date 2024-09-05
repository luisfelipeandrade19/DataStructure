#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sorts.c"

int gerador(){
 srand(time(NULL));
 return rand() % 1000;
}


int main(int argc, char const *argv[]){

    int escolha;
    do{
    printf("-------------------------\n");
    printf("-Algoritmos de Ordenacao-\n");
    printf("-------Bubble Sort-------\n");
    printf("-------------------------\n\n");

    printf("1- Gerar Array de forma aleatoria\n"
           "2- Gerar Array de forma ordenada\n"
           "3- Gerar Array de forma reversamente ordenada\n"
           "4- Encerrar programa\n\n");
    scanf("%d", &escolha);

        int l;
        switch (escolha){
            case 1:
            int arr1[0];
            int n = 0;
            printf("-------------------------\n");
            printf("Gerando Aleatoriamente...\n");
            printf("-------------------------\n\n");
            
            printf("Ordenar Array?\n"
                   "1- Sim\n"
                  "2- Nao\n\n");
                  scanf("%d", &l);
            if(l == 1){

                double tempo;
                clock_t inicio, fim;

                

                printf("Qual tamanho de Array que deseja gerar?\n");
                scanf("%d", &n);
                if(n <= 0){
                    printf("valor invalido!");
                    return -1;
                }

                arr1[n];

                inicio = clock();

                    gerarAleatorio(arr1, n);
                    printArray(arr1, n);

                    printf("-------------------------\n"
                           "--------Ordenando--------\n"
                           "-------------------------\n\n");
                    
                    bubbleSort(arr1, n);

                    printf("Array ordenado: ");
                    printArray(arr1, n);

                fim = clock();

                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nTempo gasto: %g s.\n", tempo);

            }else if (l == 2) {
                printArray(arr1, n);
                return 0;
            } else {
                printf("Opcao invalida\n");
                return 1;
            }
            break;


            case 2:
            int n = 0;
            int arr2[0];
            printf("-------------------------\n");
            printf("Gerando Ordenadamente....\n");
            printf("-------------------------\n\n");
            printf("Ordenar Array?\n"
                   "1- Sim\n"
                   "2- Nao\n\n");
                  scanf("%d", &l);
            if(l == 1){

                double tempo;
                clock_t inicio, fim;

                

                printf("Qual tamanho de Array que deseja gerar?\n");
                scanf("%d", &n);
                if(n <= 0){
                    printf("valor invalido!");
                    return -1;
                }

                arr2[n];

                inicio = clock();

                    gerarOrdenado(arr2, n);
                    printArray(arr2, n);

                    printf("-------------------------\n"
                           "--------Ordenando--------\n"
                           "-------------------------\n\n");
                    
                    bubbleSort(arr2, n);

                    printf("Array ordenado: ");
                    printArray(arr2, n);

                fim = clock();

                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nTempo gasto: %g s.\n", tempo);

            }else if (l == 2) {
                printArray(arr2, n);
                return 0;
            } else {
                printf("Opcao invalida\n");
                return 1;
            }
            break;

            case 3:
                int arr3[0];
                int n = 0;
                 printf("-----------------------------\n");
                 printf("Gerando Reversamente Ordenado\n");
                 printf("-----------------------------\n\n");
            printf("Ordenar Array?\n"
                   "1- Sim\n"
                   "2- Nao\n\n");
                  scanf("%d", &l);
            if(l == 1){

                double tempo;
                clock_t inicio, fim;

                

                printf("Qual tamanho de Array que deseja gerar?\n");
                scanf("%d", &n);
                if(n <= 0){
                    printf("valor invalido!");
                    return -1;
                } 
                arr3[n];

                inicio = clock();

                    gerarOrdenado(arr3, n);
                    printArray(arr3, n);

                    printf("-------------------------\n"
                           "--------Ordenando--------\n"
                           "-------------------------\n\n");
                    
                    bubbleSort(arr3, n);

                    printf("Array ordenado: ");
                    printArray(arr3, n);

                fim = clock();

                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nTempo gasto: %g s.\n", tempo);
            } else if (l == 2) {
                printArray(arr3, n);
                return 0;
            } else {
                printf("Opcao invalida\n");
                return 1;
            }
            break;
            
            case 4:
            escolha = 4;
            break;
            default:
            printf("Numero nao listado!");
            return 1;
            break;
    }    
}while (escolha != 4);

return 0;
}
