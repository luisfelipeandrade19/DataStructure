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
    printf("-----Insertion Sort------\n");
    printf("-------------------------\n\n");

    printf("1- Gerar Array de forma aleatoria\n"
           "2- Gerar Array de forma ordenada\n"
           "3- Gerar Array de forma reversamente ordenada\n"
           "4- Encerrar programa\n\n");
    scanf("%d", &escolha);

        int l;
        int n;
        int *arr = NULL;
        double tempo;
        clock_t inicio, fim;
        switch (escolha){
            case 1:
            
            printf("-------------------------\n");
            printf("Gerando Aleatoriamente...\n");
            printf("-------------------------\n\n");
            
            printf("Ordenar Array?\n"
                   "1- Sim\n"
                  "2- Nao\n\n");
                  scanf("%d", &l);

                  

                  printf("Qual tamanho de Array que deseja gerar?\n");
                    scanf("%d", &n);
                    arr = (int *)malloc(n * sizeof(int));
                    if(n <= 0){
                    printf("valor invalido!");
                    return -1;
                } 
            if(l == 1){

        

                inicio = clock();

                    gerarAleatorio(arr, n);
                    printf("Imprimindo os primeiros 35 elementos do Array...\n");
                    printArray(arr, n);

                    printf("-------------------------\n"
                           "--------Ordenando--------\n"
                           "-------------------------\n\n");
                    
                    insertionSort(arr, n);

                    printf("Imprimindo os primeiros 35 elementos do Array...\n");
                    printArray(arr, n);

                fim = clock();

                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nTempo gasto: %g s.\n", tempo);

            }else if (l == 2) {
                printf("Imprimindo os primeiros 35 elementos do Array...\n");
                printArray(arr, n);
                
            } else {
                printf("Opcao invalida\n");
                return 1;
            }
            free(arr);
            break;


            case 2:
            printf("-------------------------\n");
            printf("Gerando Ordenadamente....\n");
            printf("-------------------------\n\n");
    
                  printf("Qual tamanho de Array que deseja gerar?\n");
                    scanf("%d", &n);
                    arr = (int *)malloc(n * sizeof(int));
                    if(n <= 0){
                    printf("valor invalido!");
                    return -1;
                } 

                inicio = clock();

                    gerarOrdenado(arr, n);
                    printf("Imprimindo os primeiros 35 elementos do Array...\n");
                    printArray(arr, n);

                    printf("-------------------------\n"
                           "--------Ordenando--------\n"
                           "-------------------------\n\n");
                    
                    insertionSort(arr, n);

                    printf("Imprimindo os primeiros 35 elementos do Array...\n");
                    printArray(arr, n);

                fim = clock();

                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nTempo gasto: %g s.\n", tempo);

            
            break;

            case 3:

                 printf("-----------------------------\n");
                 printf("Gerando Reversamente Ordenado\n");
                 printf("-----------------------------\n\n");
        

                  printf("Qual tamanho de Array que deseja gerar?\n");
                    scanf("%d", &n);
                    arr = (int *)malloc(n * sizeof(int));
                    if(n <= 0){
                    printf("valor invalido!");
                    return -1;
                } 

                inicio = clock();

                    gerarReverso(arr, n);
                    printf("Imprimindo os primeiros 35 elementos do Array...\n");
                    printArray(arr, n);

                    printf("-------------------------\n"
                           "--------Ordenando--------\n"
                           "-------------------------\n\n");
                    
                    insertionSort(arr, n);

                    printf("Imprimindo os primeiros 35 elementos do Array...\n");
                    printArray(arr, n);

                fim = clock();

                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("\nTempo gasto: %g s.\n", tempo);
            
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