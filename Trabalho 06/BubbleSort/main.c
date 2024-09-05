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
    double tempo;
    clock_t inicio, fim;

    inicio = clock();

    

    fim = clock();

    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g s.\n", tempo);

    return 0;
}
