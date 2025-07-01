#include "logica_jogo.h" // Inclui o próprio cabeçalho

// Inclui bibliotecas adicionais necessárias para as implementações aqui

#include <time.h>   // Para time()
#include <math.h>   // Para fabs(), sin(), cos()

// --- Implementação das Funções da Lógica do Jogo ---

void gerarNumero(int *numero_destino, int teste_semente, const char *nome_semente) {
    int valor_base = 0;
    for (int i = 0; i < strlen(nome_semente); i++) {
        valor_base += nome_semente[i];
    }
    time_t tempo = time(NULL);
    *numero_destino = (int)(fabs(sin(teste_semente + valor_base + tempo) * cos(valor_base + tempo) * 10000)) % 100 + 1;
}

int jogar(int numeroSecreto, Jogador *jogadorAtual) {
    jogadorAtual->tentativas = 1; // Inicializa as tentativas para esta rodada
    int palpite_local;

    printf("\nJogo iniciado! Tente adivinhar o numero.\n");

    while (jogadorAtual->tentativas <= 5) {
        printf("\nTentativa %d de 5 - Digite seu palpite: ", jogadorAtual->tentativas);
        scanf("%d", &palpite_local);
        jogadorAtual->palpite = palpite_local; // Atualiza o ultimo palpite na struct

        if (palpite_local > numeroSecreto) {
            printf(">> Tente um numero mais baixo.\n");
        } else if (palpite_local < numeroSecreto) {
            printf(">> Tente um numero mais alto.\n");
        } else {
            printf("\n>>> PARABENS! VOCE ACERTOU EM %d TENTATIVAS! <<<\n", jogadorAtual->tentativas);
            jogadorAtual->ganhou = 1; // Marca que ganhou
            return 1; // Jogador ganhou
        }
        (jogadorAtual->tentativas)++; // Incrementa o contador de tentativas
    }
    jogadorAtual->ganhou = 0; // Marca que perdeu
    return 0; // Jogador perdeu (atingiu o limite de tentativas)
}
