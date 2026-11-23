#include <stdio.h>
#include <locale.h>

int Soma(int a, int b)
{
return a+b;
}
int main(){
    setlocale(LC_ALL, ".UTF8");

    int n1, n2;
    printf("Digite um número: ");
    scanf("%d", &n1);
    printf("Digite outro número: ");
    scanf("%d", &n2);
    printf("A soma de %d e %d é igual a %d", n1, n2, Soma(n1,n2));

    return 0;
}