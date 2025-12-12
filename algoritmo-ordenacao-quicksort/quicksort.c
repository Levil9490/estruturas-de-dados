#include <stdio.h>
#include <stdlib.h>

int particiona(int *v, int inicio, int fim){
    int pivo = (v[inicio] + v[fim] + v[(inicio + fim) / 2]) / 3;
    while(inicio < fim){
        while(inicio < fim && v[inicio] <= pivo) inicio++;
        while(inicio < fim && v[fim] > pivo) fim--;
        int aux = v[inicio];
        v[inicio] = v[fim];
        v[fim] = aux;
    }
    return inicio;
}

int main(){
    int vetor[] = {47, 35, 12, 49, 56, 25, 71, 83, 5, 3, 1, 70, 99, 10, 61};

    printf("%d\n", particiona(vetor, vetor[0], vetor[14]));

    return 0;
}
