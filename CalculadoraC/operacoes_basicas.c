#include <stdio.h>
#include "operacoes.h"

double soma(double a, double b)
{
    return a+b;
}
double subtracao(double a, double b)
{
    return a-b;
}
double multiplicacao(double a, double b)
{
    return a*b;
}
double divisao(double a, double b)
{
    if (b==0.0)
    {
        printf("Erro! Divisão por zero!\n");
    }
    
    return a/b;
}
int resto_divisao(int a, int b)
{
    return a%b;
}
double porcentagem(double total, double percentual)
{
    return(total*percentual)/100.0;
}