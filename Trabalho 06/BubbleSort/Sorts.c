#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *v, int n){
    if(n < 1){
        return;
    }

    for(int i = 0; i < n-1; i++){
        if(v[i] > v[i + 1]){
            swap(&v[i], &v[i + 1]);
        }
    }
    bubbleSort(v, n-1);
}

void selectionSort(int *num, int tam) {
 int i, j, min, aux;

 for (i = 0; i < (tam-1); i++) {
 min = i;

 for (j = (i+1); j < tam; j++) {
    if(num[j] < num[min]){
    min = j;
    }
 } 

 if (i != min){
    swap(&num[i], &num[min]);
        }
    }
}

void insertionSort(int *a, int n) {
 int i, j, chave;

 for (i = 1; i < n; i++) {
    chave = a[i];

    j = i - 1;

    while (j >= 0 && a[j] > chave) {
        a[j + 1] = a[j];
        j = j - 1;
    }

    a[j + 1] = chave;
    }
}

void gerarOrdenado(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;  
    }
}


void gerarReverso(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;  
    }
}

void gerarAleatorio(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000000;  
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n && i < 35; i++) {  
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}



void merge(int *a, int esq, int meio, int dir){
    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    int aE[n1], aD[n2];

    for(i = 0; i < n1; i++){
        aE[i] = a[esq + i];
    }
    for(j = 0; j< n2; j++){
        aD[j] = a[meio + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = esq;

    while (i < n1 && j < n2)
    {
        if (aE[i] <= aD[j]){
            a[k] = aE[i];
            i++;
        }
        else {
            a[k] = aD[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = aE[i];
        i++;
        k++;
    }
    
    while (j < n2)
    {
        a[k] = aD[j];
        j++;
        k++;
    }
}

void mergeSort(int *a, int esq, int dir){
    if(esq < dir){
        int meio = esq + (dir - esq)/2;
         
        mergeSort(a, esq, meio);
        mergeSort(a, meio + 1, dir);

        merge(a, esq, meio, dir);
    }
}