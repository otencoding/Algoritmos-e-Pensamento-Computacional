#ifndef OPERACOES_H
#define OPERACOES_H

#define MAX 100   

typedef struct {
    char codigo[5];   
    int categoria;    
} Senha;

void cadastrarPaciente();
void gerarSenha(int categoria);
int classificar(char genero, int idade, int gestante, int lactante, int especial, int obeso);
void consultarProxima();
void chamarPaciente();
void mostrarAtendimento();
void finalizarAtendimento();
void mostrarPainel();

#endif
