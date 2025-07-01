#include "arquivos.h" // Inclui o próprio cabeçalho

// Inclui bibliotecas adicionais necessárias para as implementações aqui
#include <stdio.h>  // Para FILE, fopen, fclose, fprintf, fgets, printf

// --- Implementação das Funções de Manipulação de Arquivos ---

void salvarResultado(const Jogador *j) {
    FILE *arquivo;
    arquivo = fopen("historico.txt", "a"); // Abre no modo apêndice

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de historico para escrita!\n");
        return;
    }

    fprintf(arquivo, "Nome: %s | Tentativas: %d | Numero Secreto: %d | Palpite Final: %d | Resultado: %s\n",
            j->nome, j->tentativas, j->numero_aleatorio, j->palpite, j->ganhou ? "GANHOU" : "PERDEU");

    fclose(arquivo);
    printf(">> Resultado salvo no historico!\n");
}

void exibirConteudoHistorico() {
    FILE *arquivo;
    char linha[256]; // Buffer para ler cada linha

    arquivo = fopen("historico.txt", "r"); // Abre no modo leitura

    if (arquivo == NULL) {
        printf("\n----------- Historico de Jogos -----------\n");
        printf("Nenhum historico de jogos encontrado ainda.\n");
        printf("------------------------------------------\n");
        return;
    }

    printf("\n----------- Historico de Jogos -----------\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha); // fgets ja le a quebra de linha (\n)
    }
    printf("------------------------------------------\n");

    fclose(arquivo);
}