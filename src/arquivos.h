#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "logica_jogo.h" // Precisa da definição de Jogador

// --- Protótipos das Funções de Manipulação de Arquivos ---

// Função para salvar o resultado de um jogo no arquivo de histórico.
void salvarResultado(const Jogador *j);

// Função para exibir o conteúdo do arquivo de histórico na tela.
void exibirConteudoHistorico();

#endif // ARQUIVOS_H
