#include "interface.h" // Inclui as definições e protótipos para este módulo.
#include "arquivos.h"  // Precisamos chamar funções de arquivos aqui (ex: exibirConteudoHistorico).
#include <stdio.h>     // Para as operações de I/O básicas.

// Implementa a exibição do menu e a captura da escolha do usuário.
int mostrarMenu(int *teste_semente_teclado_ptr) {
    int select_menu;
    printf("\nTESTE DE TECLADO (Digite um numero para a semente do numero aleatorio): ");
    // Lê o valor e o armazena no endereço apontado por 'teste_semente_teclado_ptr'.
    // Assim, a variável original em 'main' será modificada.
    scanf("%d", teste_semente_teclado_ptr); // Sem '&' porque já é um ponteiro

    // Exibe as opções do menu principal.
    printf("\n----------- Jogo da Adivinhacao -----------\n");
    printf("Menu\n");
    printf("1 - Jogar\n");
    printf("2 - Ver Historico\n");
    printf("3 - Ver Ranking\n");
    printf("4 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &select_menu); // Lê a opção que o usuário digitou.
    return select_menu;         // Retorna a opção escolhida.
}