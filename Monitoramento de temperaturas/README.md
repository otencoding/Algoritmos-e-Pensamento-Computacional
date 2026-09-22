# Sistema de Monitoramento de Temperatura em C

## 1. Identificação
* **Nome do Aluno:** Alair Eloi de Araujo Neto
* **Disciplina:** Algoritmos e Pensamento Computacional
* **Professora:** Profa. Karla Sartin
* **Título do Projeto:** Sistema de Monitoramento e Alerta de Temperatura

## 2. Objetivo
O programa tem como objetivo monitorar leituras de temperatura em tempo real, validando dados de entrada, calculando estatísticas gerais (média, maior e menor valor, percentual de alertas) e detectando situações de risco por meio de um contador de temperaturas consecutivas acima do limite estabelecido.

## 3. Funcionamento do Programa
* **Definição do limite:** O usuário define o valor máximo permitido de temperatura antes das leituras começarem. O programa valida se o valor digitado é numérico e estritamente positivo.
* **Leituras realizadas:** O sistema solicita iterativamente valores de temperatura.
* **Tratamento de valores inválidos:** Caso o usuário insira letras, símbolos ou valores físicos impossíveis (abaixo do zero absoluto, -273.15°C), o programa rejeita a entrada, limpa o buffer do teclado e solicita um novo valor sem corromper o fluxo.
* **Identificação de excesso:** Cada leitura é comparada ao limite. Se for superior, um alerta é disparado.
* **Contagem de temperaturas consecutivas:** Uma variável controladora acumula quantas vezes seguidas a temperatura ultrapassou o limite. Se o valor normalizar, o contador é reiniciado para zero.
* **Condição de encerramento:** O monitoramento é encerrado automaticamente caso ocorram **três temperaturas consecutivas acima do limite** ou caso o operador decida encerrar manualmente digitando 'n'.

## 4. Estruturas de Repetição Utilizadas
Foram utilizadas estruturas **`do...while`** em duas frentes:
1. Na validação inicial do limite de temperatura (garantindo que o bloco execute ao menos uma vez e repita enquanto o dado for inválido).
2. No laço principal de inserção de dados e verificação de alertas, permitindo que o fluxo rode dinamicamente até atingir o gatilho de parada por valores consecutivos ou encerramento manual.

## 5. Como Executar
Certifique-se de ter um compilador C (como o GCC) instalado. No terminal, execute os comandos:

```bash
gcc monitoramento.c -o monitoramento
./monitoramento