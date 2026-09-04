#include <stdio.h>
#include <locale.h>

int soma(int a, int b);

int main()
{
    setlocale(LC_ALL,"");

    int numero1, numero2;
    printf("Digite um número: ");
    scanf("%d", &numero1);
    printf("Digite outro número: ");
    scanf("%d", &numero2);
    printf("%d + %d = %d\n", numero1, numero2, soma(numero1, numero2));
    return 0;
}