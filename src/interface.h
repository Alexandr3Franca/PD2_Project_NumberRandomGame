#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h> // Para printf, scanf

// --- Protótipos das Funções da Interface ---

// Função para exibir o menu principal e obter a escolha do usuário.
int mostrarMenu(int teste_semente_teclado); // Adaptei para receber a semente do teclado

// Nota: A função mostrarHistorico agora não precisa ser declarada aqui
// porque ela será uma chamada para exibirConteudoHistorico() que vem de arquivos.h

#endif // INTERFACE_H
