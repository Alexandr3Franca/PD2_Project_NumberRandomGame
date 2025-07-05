#include "logica_jogo.h" // Inclui as definições e protótipos para este módulo.
#include <time.h>   // Para time(), fundamental na semente do número.
#include <math.h>   // Para fabs(), sin(), cos(), usados na geração do número.

// Implementa a geração do número aleatório, usando dados do jogador para variar.
void gerarNumero(int *numero_destino, int teste_semente, const char *nome_semente) {
    int valor_base = 0;
    // Calcula um valor base a partir do nome do jogador.
    for (int i = 0; i < strlen(nome_semente); i++) {
        valor_base += nome_semente[i];
    }
    time_t tempo = time(NULL); // Pega o tempo atual para a semente.

    // Geração do número secreto entre 1 e 100, baseado nas sementes.
    // O '*' aqui atribui o valor ao local de memória apontado por 'numero_destino'.(ponteiro)
    *numero_destino = (int)(fabs(sin(teste_semente + valor_base + tempo) * cos(valor_base + tempo) * 10000)) % 100 + 1;
}

// Implementa o fluxo de um jogo, incluindo palpites e feedback.
int jogar(int numeroSecreto, Jogador *jogadorAtual) {
    jogadorAtual->tentativas = 1; // Começa a contagem de tentativas.
    int palpite_local;            // Variável temporária para o palpite.

    printf("\nJogo iniciado! Tente adivinhar o numero entre 1 e 100.\n");

    // Loop principal para as 5 tentativas do jogador.
    while (jogadorAtual->tentativas <= 5) {
        printf("\nTentativa %d de 5 - Digite seu palpite: ", jogadorAtual->tentativas);
        scanf("%d", &palpite_local);
        jogadorAtual->palpite = palpite_local; // Atualiza o palpite na struct do jogador (via ponteiro '->').

        // Compara o palpite com o número secreto e dá feedback.
        if (palpite_local > numeroSecreto) {
            printf(">> Tente um numero mais baixo.\n");
        } else if (palpite_local < numeroSecreto) {
            printf(">> Tente um numero mais alto.\n");
        } else {
            // Condição de vitória.
            printf("\n>>> PARABENS! VOCE ACERTOU EM %d TENTATIVAS! <<<\n", jogadorAtual->tentativas);
            jogadorAtual->ganhou = 1; // Marca o jogador como vencedor.
            return 1;                 // Encerra a função, indicando vitória.
        }
        (jogadorAtual->tentativas)++; // Incrementa o contador de tentativas.
    }

    jogadorAtual->ganhou = 0; // Se o loop terminou, o jogador perdeu.
    return 0;                 // Encerra a função, indicando derrota.
}