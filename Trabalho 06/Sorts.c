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
 if(num[j] < num[min])
 min = j;
 } 

 if (i != min) 
 swap(&num[i], &num[min]);

 }
}
