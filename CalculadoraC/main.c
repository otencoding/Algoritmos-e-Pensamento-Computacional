#include <stdio.h>
#include <locale.h>
#include "operacoes.h"

int main()
{
    setlocale(LC_ALL,"pt_BR");
    float numero1, numero2, resultado;
    int executando, operador;
    executando = 1;
    while (executando == 1)
    {
        printf("==================\n");
        printf("CALCULADORA EM C\n");
        printf("==================\n");
        printf("Digite o valor do primeiro número: \n");
        scanf("%f", &numero1);
        printf("Selecione um dos operadores abaixo:\n1.Soma\n2.Subtração\n3.Multiplicação\n4.Divisão\n5.Resto da divisão\n6.Porcentagem\n7.Potenciação\n8.Raíz Quadrada\n9.Valor Absoluto\n10.Quadrado\n11.Cubo\n12.Inverso\n13.Média de dois números\n14.Seno\n15.Cosseno\n16.Tangente\n17.Log Base 10\n18.Log Natural\n19.Arrendondar para cima\n20.Arredondar para baixo\n");
        scanf("%d", &operador);

        switch (operador)
        {
        case 1:
            printf("Digite o valor do segundo número: \n");
            scanf("%f", &numero2);
            printf("%f + %f = %f \n", numero1, numero2, soma(numero1,numero2));
            numero1 = soma(numero1,numero2);
            break;
        case 2:
            printf("Digite o valor do segundo número")
        default:
            break;
        }
        executando = 0;
    }
    
    
}