#ifndef ARQUIVOS_H // Evita inclusões duplicadas.
#define ARQUIVOS_H

#include "logica_jogo.h" // Precisamos da struct 'Jogador'.

// Protótipos das funções de manipulação de arquivos.

// Salva os detalhes de uma partida no histórico ('historico.txt').
void salvarResultado(const Jogador *j);

// Exibe todo o conteúdo do arquivo de histórico.
void exibirConteudoHistorico();

// Carrega o ranking TOP 3 do arquivo ('ranking.txt') para a memória.
// 'jogadores_ranking': Vetor de 3 Jogadores que será preenchido.
void carregarRanking(Jogador jogadores_ranking[3]);

// Atualiza o ranking com o resultado do 'novo_jogador' e salva no arquivo.
// 'novo_jogador': Dados do jogador da rodada atual.
// 'jogadores_ranking': O ranking atual na memória.
void atualizarESalvarRanking(const Jogador *novo_jogador, Jogador jogadores_ranking[3]);

// Exibe o ranking TOP 3 na tela.
// 'jogadores_ranking': O array do ranking a ser exibido.
void exibirRanking(const Jogador jogadores_ranking[3]);

#endif // ARQUIVOS_H