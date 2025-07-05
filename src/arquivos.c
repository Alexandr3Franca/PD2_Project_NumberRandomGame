#include "arquivos.h" // Inclui as definições e protótipos para este módulo.

#include <stdio.h>  // Essencial para operações de arquivo (fopen, fclose, fprintf, etc.).
#include <stdlib.h> // Para funções gerais.
#include <string.h> // Para strcpy e strcmp (manipulação de strings).

// Registra os detalhes de cada jogo no 'historico.txt'.
void salvarResultado(const Jogador *j) {
    FILE *arquivo;
    arquivo = fopen("historico.txt", "a"); // adiciona no final ou cria se não existe.

    if (arquivo == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo de historico para escrita!\n");
        return;
    }

    // Escreve os dados do jogador e da partida no arquivo.
    fprintf(arquivo, "Nome: %s | Tentativas: %d | Numero Secreto: %d | Palpite Final: %d | Resultado: %s\n",
            j->nome, j->tentativas, j->numero_aleatorio, j->palpite, j->ganhou ? "GANHOU" : "PERDEU");

    fclose(arquivo); // Fecha o arquivo.
    printf(">> Resultado salvo no historico!\n");
}

// Lê e imprime o conteúdo completo do 'historico.txt'.
void exibirConteudoHistorico() {
    FILE *arquivo;
    char linha[256]; // le cada linha.

    arquivo = fopen("historico.txt", "r"); // Abre em modo leitura.

    if (arquivo == NULL) {
        printf("\n----------- Historico de Jogos -----------\n");
        printf("Ainda nao ha historico de jogos para exibir.\n");
        printf("------------------------------------------\n");
        return;
    }

    printf("\n----------- Historico de Jogos -----------\n");
    // Lê e imprime cada linha até o fim do arquivo.
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }
    printf("------------------------------------------\n");

    fclose(arquivo); // Fecha o arquivo.
}

// Carrega o ranking TOP 3 do 'ranking.txt' para a memória do programa.
void carregarRanking(Jogador jogadores_ranking[3]) {
    FILE *arquivo = fopen("ranking.txt", "r"); // Tenta abrir o ranking para leitura.

    if (arquivo == NULL) {
        // Se o arquivo não existir, inicializa o ranking com slots vazios ("N/A", 999 tentativas).
        for (int i = 0; i < 3; i++) {
            strcpy(jogadores_ranking[i].nome, "N/A");
            jogadores_ranking[i].tentativas = 999;
            jogadores_ranking[i].ganhou = 0;
        }
        return;
    }

    // Lê os 3 (ou menos) melhores jogadores do arquivo.
    for (int i = 0; i < 3; i++) {
        // Formato esperado: "Nome;Tentativas\n".
        if (fscanf(arquivo, "%[^;];%d\n", jogadores_ranking[i].nome, &jogadores_ranking[i].tentativas) != 2) {
            // Se a leitura falhar para algum slot, preenche-o como vazio.
            strcpy(jogadores_ranking[i].nome, "N/A");
            jogadores_ranking[i].tentativas = 999;
            jogadores_ranking[i].ganhou = 0;
        }
    }
    fclose(arquivo); // Fecha o arquivo.
}

// Atualiza o ranking TOP 3 na memória e depois salva essa nova lista no 'ranking.txt'.
void atualizarESalvarRanking(const Jogador *novo_jogador, Jogador jogadores_ranking[3]) {
    // Apenas jogadores que ganharam podem entrar no ranking de tentativas.
    if (!novo_jogador->ganhou) {
        return;
    }

    // Lógica para inserir o novo jogador, priorizando MENOR número de tentativas.
    if (novo_jogador->tentativas < jogadores_ranking[0].tentativas) {
        jogadores_ranking[2] = jogadores_ranking[1]; // Move 2º para 3º
        jogadores_ranking[1] = jogadores_ranking[0]; // Move 1º para 2º
        jogadores_ranking[0] = *novo_jogador;        // Novo jogador é o 1º
    } else if (novo_jogador->tentativas < jogadores_ranking[1].tentativas) {
        jogadores_ranking[2] = jogadores_ranking[1]; // Move 2º para 3º
        jogadores_ranking[1] = *novo_jogador;        // Novo jogador é o 2º
    } else if (novo_jogador->tentativas < jogadores_ranking[2].tentativas) {
        jogadores_ranking[2] = *novo_jogador;        // Novo jogador é o 3º
    }

    // Agora, salva o ranking atualizado no arquivo (sobrescrevendo o antigo).
    FILE *arquivo = fopen("ranking.txt", "w"); // Abre em modo escrita: sobrescreve o arquivo.
    if (arquivo == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo de ranking para escrita!\n");
        return;
    }

    // Escreve os jogadores do TOP 3 (apenas os válidos) de volta no arquivo.
    for (int i = 0; i < 3; i++) {
        if (strcmp(jogadores_ranking[i].nome, "N/A") != 0 && jogadores_ranking[i].tentativas != 999) {
            fprintf(arquivo, "%s;%d\n", jogadores_ranking[i].nome, jogadores_ranking[i].tentativas);
        }
    }
    fclose(arquivo); // Fecha o arquivo.
    printf(">> Ranking atualizado e salvo!\n");
}

// Exibe o ranking TOP 3 formatado na tela.
void exibirRanking(const Jogador jogadores_ranking[3]) {
    printf("\n----------- TOP 3 JOGADORES -----------\n");
    for (int i = 0; i < 3; i++) {
        // Mostra o jogador ou indica que o slot está vazio.
        if (strcmp(jogadores_ranking[i].nome, "N/A") != 0 && jogadores_ranking[i].tentativas != 999) {
            printf("%d Lugar: %s - %d tentativas\n", i + 1, jogadores_ranking[i].nome, jogadores_ranking[i].tentativas);
        } else {
            printf("%d Lugar: -- Vazio --\n", i + 1);
        }
    }
    printf("-----------------------------------------\n");
}