#ifndef LOGICA_JOGO_H
#define LOGICA_JOGO_H

#include <stdio.h> // Para FILE, printf, scanf, etc.
#include <string.h> // Para strlen

// --- Estrutura do Jogador ---
typedef struct {
    char nome[50];
    int palpite;
    int tentativas;
    int numero_aleatorio;
    int ganhou; // 1 para sim, 0 para nao
} Jogador;

// --- Protótipos das Funções da Lógica do Jogo ---

// Função para gerar número aleatório .
// Recebe um ponteiro para int para armazenar o número gerado.
void gerarNumero(int *numero_destino, int teste_semente, const char *nome_semente);

// Função para a lógica principal do jogo (palpites).
// Recebe o numeroSecreto por valor e a struct Jogador por referência.
// Retorna 1 se o jogador ganhou, 0 se perdeu.
int jogar(int numeroSecreto, Jogador *jogadorAtual);

#endif // LOGICA_JOGO_H
