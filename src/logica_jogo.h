#ifndef LOGICA_JOGO_H // Evita inclusões duplicadas do cabeçalho.
#define LOGICA_JOGO_H

#include <stdio.h>  // Necessário para tipos básicos como char para strings.
#include <string.h> // Para strlen, útil na geração do número.

// Estrutura que define um Jogador, seus dados e progresso no jogo.
typedef struct {
    char nome[50];             // Nome do jogador.
    int palpite;               // Último palpite feito.
    int tentativas;            // Quantas vezes o jogador tentou.
    int numero_aleatorio;      // O número secreto a ser adivinhado.
    int ganhou;                // 1 se venceu a rodada, 0 se perdeu.
} Jogador;

// Protótipos das funções de lógica do jogo.
// 'numero_destino': Ponteiro para onde o número gerado será armazenado.
// 'teste_semente', 'nome_semente': Valores usados na hora da geração do número.
void gerarNumero(int *numero_destino, int teste_semente, const char *nome_semente);

// 'numeroSecreto': O número que o jogador deve adivinhar.
// 'jogadorAtual': Ponteiro para a struct do jogador, permite atualizar suas tentativas e palpite.
// Retorna 1 se o jogador acertou, 0 se as tentativas acabaram.
int jogar(int numeroSecreto, Jogador *jogadorAtual);

#endif // LOGICA_JOGO_H