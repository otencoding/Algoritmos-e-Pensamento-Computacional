#include <stdio.h>
#include <locale.h>
#include "operacoes.h"

int main()
{
    setlocale(LC_ALL,"");
    double n1 = 10;
    double n2 = 5;
    printf("%f - %f = %f", n1, n2, divisao(n1,n2));
    return 0;
}