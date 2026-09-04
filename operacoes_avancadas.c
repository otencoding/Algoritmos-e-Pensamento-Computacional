#include <stdio.h>
#include <math.h>
#include "operacoes.h"

double potencia (double base, double expoente)
{
    return pow(base, expoente);
}
double raiz_quadrada (double a)
{
    return sqrt(a);
}
double valor_absoluto (double a)
{
    return fabs(a);
}
double quadrado (double a)
{
    return pow(a, 2);
}
double cubo (double a)
{
    return pow(a, 3);
}
double inverso (double a)
{
    if (a==0)
    {
        printf("Erro! Divisão por zero!\n");
        return 0;
    }
    else
    {
        return 1.0/a;
    }
}
double media_dois (double a, double b)
{
    return (a+b)/2.0;
}