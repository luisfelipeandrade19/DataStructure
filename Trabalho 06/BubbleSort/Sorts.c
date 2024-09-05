void bubbleSort(int *v, int n){
    if(n < 1){
        return;
    }

    for(int i = 0; i < n-1; i++){
        if(v[i] > v[i + 1]){
            swap(&v[i], &v[i + 1]);
        }
    }
}


void swap(int *a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
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


void printArray(int arr[], int n) {
    for (int i = 0; i < n && i < 35; i++) {  
        printf("%d ", arr[i]);
    }
    printf("\n");
}