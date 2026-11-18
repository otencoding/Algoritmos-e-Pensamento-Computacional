#include <stdio.h>

int main(){
    int numeros[5];
    for (int y = 0; y < 5; y++)
    {
            printf("Digite os números para o vetor ");
            scanf("%d", &numeros[y]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("numeros[%d] = %d\n", i, numeros[i]);
    }
    
    return 0;
}