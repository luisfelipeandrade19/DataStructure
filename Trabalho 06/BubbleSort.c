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