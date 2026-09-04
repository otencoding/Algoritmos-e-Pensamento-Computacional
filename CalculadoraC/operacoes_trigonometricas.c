#include <stdio.h>
#include <math.h>
#include "operacoes.h"

double seno (double angulo_graus)
{
    double angulo_radianos;
    angulo_radianos = angulo_graus * ( 3.14159265 / 180.0);
    return sin(angulo_radianos);
}
double cosseno (double angulo_graus)
{
    double angulo_radianos;
    angulo_radianos = angulo_graus * ( 3.14159265 / 180.0);
    return cos(angulo_radianos);
}
double tangente (double angulo_graus)
{
    double angulo_radianos;
    angulo_radianos = angulo_graus * ( 3.14159265 / 180.0);
    return tan(angulo_radianos);
}
double logaritmo_base10 (double a)
{
    if (a <= 0)
    {
        printf("Erro! Log de zero ou negativo.");
    }
    else
    {
    return log10(a);
    }
}
double logaritmo_natural (double a)
{
    if (a <= 0)
    {
        printf("Erro! Log de zero ou negativo.");
    }
    else
    {
    return log(a);
    }
}
double arredondar_cima (double a)
{
    return ceil(a);
}
double arredondar_baixo (double a)
{
    return floor(a);
}