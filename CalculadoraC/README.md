# Calculadora Modular em C

Uma calculadora de linha de comando (CLI) avançada e modular desenvolvida na linguagem C, estruturada para fins acadêmicos na faculdade UDF (Curso de Análise e Desenvolvimento de Sistemas). O projeto foca em organização modular de arquivos, tratamento de precisão numérica com ponto flutuante e uma interface de terminal amigável.

## Funcionalidades

O sistema conta com um menu interativo dividido em quatro categorias principais e mantém um acumulador dinâmico (`VALOR ATUAL`), permitindo que o resultado de uma operação seja utilizado automaticamente na próxima:

* **Operações Básicas:** Soma, Subtração, Multiplicação, Divisão e Resto da Divisão (com casting para inteiros).
* **Operações Avançadas:** Porcentagem, Potenciação, Raiz Quadrada, Valor Absoluto, Quadrado, Cubo, Inverso, Média de dois números e Arredondamento (para cima e para baixo).
* **Operações Trigonométricas e Logarítmicas:** Seno, Cosseno, Tangente, Logaritmo na Base 10 e Logaritmo Natural.
* **Controle de Sessão:** Menu cíclico baseado em laço `while` com opção de encerramento seguro.

## Estrutura do Projeto

O código-fonte é separado em múltiplos arquivos para garantir a modularidade e a clareza da arquitetura:

* `main.c` — Controla o fluxo principal, a interface do menu via terminal, a persistência do valor atual e o laço de repetição.
* `operacoes.h` — Cabeçalho unificado contendo os protótipos de todas as funções matemáticas do projeto.
* `operacoes_basicas.c` — Implementação das operações aritméticas elementares.
* `operacoes_avancadas.c` — Implementação das funções de exponenciação, radiciação, arredondamento e estatística básica.
* `operacoes_trigonometricas.c` — Implementação das funções trigonométricas e logarítmicas baseadas na biblioteca matemática padrão (`math.h`).

## Tecnologias e Ambiente

* **Linguagem:** C (Padrão C99/C11)
* **Ambiente de Desenvolvimento:** Visual Studio Code (VS Code)
* **Compilador:** GCC (via ambiente MSYS2/UCRT64 no Windows)
* **Recursos de Terminal:** Configuração de codificação UTF-8 (`locale.h`) e comandos de sistema controlados (`stdlib.h`).

## Como Compilar e Executar

Como o projeto utiliza múltiplos arquivos de código-fonte modularizados, você deve compilar todos os arquivos `.c` em conjunto.

Se estiver utilizando o terminal com o GCC instalado, execute:

```bash
gcc *.c -o calculadora -lm

```

*(Nota: a flag `-lm` é necessária para vincular a biblioteca matemática padrão do C).*

Para executar o programa gerado no Windows:

```bash
.\calculadora.exe

```