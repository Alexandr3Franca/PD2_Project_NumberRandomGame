#include "interface.h" // Inclui o próprio cabeçalho
#include "arquivos.h"  // Precisa para chamar exibirConteudoHistorico()
#include <stdio.h>     // Para printf, scanf

// --- Implementação das Funções da Interface ---

int mostrarMenu(int teste_semente_teclado) { // Recebe a semente para o prompt
    int select_menu;
    printf("\nTESTE DE TECLADO (Digite um numero para a semente do numero aleatorio): ");
    scanf("%d", &teste_semente_teclado); // Lê a semente aqui

    printf("\n----------- Jogo da Adivinhacao -----------\n");
    printf("Menu\n");
    printf("1 - Jogar\n");
    printf("2 - Ver Historico\n");
    printf("3 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &select_menu);
    return select_menu; // Retorna a opção escolhida
}

// A função mostrarHistorico() que estava antes no main.c
// agora chama a função de arquivos para fazer a exibição real.
// Poderíamos ter uma função aqui que apenas mostra o título e chama a de arquivos.
// Por simplicidade, a chamada será direta de main para exibirConteudoHistorico.
// Se você quiser uma função `mostrarHistorico` em interface.c que apenas
// "inicia" a exibição, ela seria assim:
/*
void mostrarHistorico() {
    exibirConteudoHistorico(); // Chama a função que faz o trabalho real de arquivo
}
*/