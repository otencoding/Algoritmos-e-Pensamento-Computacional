#include <stdio.h>
#include "operacoes.h"

int main() {
    int opcao;

    do {
        printf("\n===== CLINICA - SENHAS DE ATENDIMENTO =====\n");
        printf("1 - Cadastrar paciente (emitir senha)\n");
        printf("2 - Consultar proxima senha\n");
        printf("3 - Chamar paciente\n");
        printf("4 - Ver senha em atendimento\n");
        printf("5 - Finalizar atendimento\n");
        printf("6 - Painel de chamada\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');   // limpa o que foi digitado errado
            opcao = -1;
        }

        switch (opcao) {
            case 1: cadastrarPaciente(); break;
            case 2: consultarProxima(); break;
            case 3: chamarPaciente(); break;
            case 4: mostrarAtendimento(); break;
            case 5: finalizarAtendimento(); break;
            case 6: mostrarPainel(); break;
            case 0: printf("\nEncerrando...\n"); break;
            default: printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
