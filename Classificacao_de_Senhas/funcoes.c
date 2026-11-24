#include <stdio.h>
#include <ctype.h>
#include "operacoes.h"

// Indice das filas: 0 = Urgente, 1 = Preferencial, 2 = Normal
// (a ordem dos indices ja e a ordem de prioridade de chamada)
Senha fila[3][MAX];
int qtd[3] = {0, 0, 0};          // quantos esperando em cada fila
int contador[3] = {0, 0, 0};     // ultimo numero emitido em cada categoria

char letras[3] = {'U', 'P', 'N'};
char nomes[3][15] = {"Urgente", "Preferencial", "Normal"};

Senha atual;                     // senha em atendimento
int emAtendimento = 0;           // 1 = tem alguem sendo atendido
int totalEmitidas = 0;
int totalAtendidas = 0;


// funcoes auxiliares de leitura 

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// le 1 (sim) ou 0 (nao), repete ate o usuario digitar certo
int lerSimNao(char pergunta[]) {
    int resp;
    do {
        printf("%s (1 - Sim / 0 - Nao): ", pergunta);
        if (scanf("%d", &resp) != 1) {
            limparBuffer();
            resp = -1;
        }
        if (resp != 0 && resp != 1) {
            printf("Opcao invalida!\n");
        }
    } while (resp != 0 && resp != 1);
    return resp;
}


// Modulo 2: classificacao

int classificar(char genero, int idade, int gestante, int lactante, int especial, int obeso) {
    // Urgente: mais de 80 anos
    if (idade > 80) {
        return 0;
    }
    // Preferencial
    if (gestante == 1 || lactante == 1 || especial == 1 || obeso == 1) {
        return 1;
    }
    if (genero == 'F' && idade >= 60) {
        return 1;
    }
    if (genero == 'M' && idade >= 65) {
        return 1;
    }
    // Normal
    return 2;
}


// Modulo 1: registro de senhas 

void gerarSenha(int categoria) {
    Senha nova;

    if (qtd[categoria] >= MAX) {
        printf("Fila %s cheia! Nao foi possivel emitir a senha.\n", nomes[categoria]);
        return;
    }

    contador[categoria]++;
    sprintf(nova.codigo, "%c%03d", letras[categoria], contador[categoria]);
    nova.categoria = categoria;

    // coloca no final da fila (FIFO)
    fila[categoria][qtd[categoria]] = nova;
    qtd[categoria]++;
    totalEmitidas++;

    printf("\nSenha emitida: %s (%s)\n", nova.codigo, nomes[categoria]);
}

void cadastrarPaciente() {
    char genero;
    int idade;
    int gestante = 0, lactante = 0, especial, obeso;
    int categoria;

    printf("\n--- Cadastro de paciente ---\n");

    do {
        printf("Genero (F/M): ");
        scanf(" %c", &genero);
        genero = toupper(genero);
        if (genero != 'F' && genero != 'M') {
            printf("Genero invalido!\n");
        }
    } while (genero != 'F' && genero != 'M');

    do {
        printf("Idade: ");
        if (scanf("%d", &idade) != 1) {
            limparBuffer();
            idade = -1;
        }
        if (idade < 0 || idade > 120) {
            printf("Idade invalida!\n");
        }
    } while (idade < 0 || idade > 120);

    // gestante e lactante so perguntam para mulheres
    if (genero == 'F') {
        gestante = lerSimNao("Esta gestante?");
        lactante = lerSimNao("Esta lactante?");
    }
    especial = lerSimNao("Possui necessidade especial?");
    obeso = lerSimNao("Possui condicao de obesidade?");

    categoria = classificar(genero, idade, gestante, lactante, especial, obeso);
    gerarSenha(categoria);
}


// Modulo 3: registro de atendimento

// mostra qual sera a proxima senha, sem chamar
void consultarProxima() {
    int i;
    for (i = 0; i < 3; i++) {
        if (qtd[i] > 0) {
            printf("\nProxima senha: %s (%s)\n", fila[i][0].codigo, nomes[i]);
            return;
        }
    }
    printf("\nNao ha ninguem na fila.\n");
}

void chamarPaciente() {
    int i, j;

    if (emAtendimento == 1) {
        printf("\nJa existe um atendimento em andamento (%s). Finalize antes de chamar outro.\n", atual.codigo);
        return;
    }

    // procura da fila mais prioritaria para a menos prioritaria
    for (i = 0; i < 3; i++) {
        if (qtd[i] > 0) {
            atual = fila[i][0];
            emAtendimento = 1;

            // atualiza a fila: todo mundo anda uma posicao
            for (j = 0; j < qtd[i] - 1; j++) {
                fila[i][j] = fila[i][j + 1];
            }
            qtd[i]--;

            printf("\nChamando senha %s - %s\n", atual.codigo, nomes[i]);
            return;
        }
    }
    printf("\nNao ha ninguem na fila.\n");
}

void mostrarAtendimento() {
    if (emAtendimento == 0) {
        printf("\nNenhuma senha em atendimento.\n");
    } else {
        printf("\nSenha em atendimento: %s (%s)\n", atual.codigo, nomes[atual.categoria]);
    }
}

void finalizarAtendimento() {
    if (emAtendimento == 0) {
        printf("\nNao ha atendimento para finalizar.\n");
    } else {
        printf("\nAtendimento da senha %s finalizado.\n", atual.codigo);
        emAtendimento = 0;
        totalAtendidas++;
    }
}


// Modulo 4: painel

void mostrarPainel() {
    int i, j, mostradas = 0;

    printf("\n=============== PAINEL ===============\n");

    if (emAtendimento == 1) {
        printf("Senha chamada: %s (%s)\n", atual.codigo, nomes[atual.categoria]);
    } else {
        printf("Senha chamada: ---\n");
    }

    printf("\nProximas senhas:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < qtd[i] && mostradas < 5; j++) {
            printf("  %d) %s (%s)\n", mostradas + 1, fila[i][j].codigo, nomes[i]);
            mostradas++;
        }
    }
    if (mostradas == 0) {
        printf("  Nenhuma senha aguardando.\n");
    }

    printf("\nAguardando por categoria:\n");
    printf("  Urgente: %d\n", qtd[0]);
    printf("  Preferencial: %d\n", qtd[1]);
    printf("  Normal: %d\n", qtd[2]);

    printf("\nEmitidas: %d | Atendidas: %d\n", totalEmitidas, totalAtendidas);
    printf("======================================\n");
}
