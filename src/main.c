#include <stdio.h>  // Para printf, scanf (embora a maioria esteja na interface)
#include <stdlib.h> // Para EXIT_SUCCESS, EXIT_FAILURE 
#include <time.h>   // Para srand, time 

// Inclui os cabeçalhos dos módulos que serão utilizados
#include "logica_jogo.h"
#include "interface.h"
#include "arquivos.h"

int main() {
    // É uma boa prática inicializar o gerador de números aleatórios APENAS UMA VEZ

    int select_menu;
    int teste_semente_teclado; // Para passar para a função de menu/geração

    do {
        // A função mostrarMenu agora também obtém o teste_semente_teclado e a opção do menu
        // Você precisa passar o endereço de teste_semente_teclado se o mostrarMenu for alterar
        // ele diretamente, mas pelo que vimos, o scanf no mostrarMenu já altera a variável
        // que você passa o endereço (&). A forma mais simples é retornar a opção.
        // E o teste_semente_teclado pode ser lido dentro do loop, como você já faz,
        // ou ser uma função separada. Vamos manter no main por enquanto para teste.

        printf("\nTESTE DE TECLADO (Digite um numero para a semente do numero aleatorio): ");
        scanf("%d", &teste_semente_teclado); // Mantido aqui para demonstração

        printf("\n----------- Jogo da Adivinhacao -----------\n");
        printf("Menu\n");
        printf("1 - Jogar\n");
        printf("2 - Ver Historico\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &select_menu);

        switch (select_menu) {
            case 1: {
                Jogador jogador_atual;
                jogador_atual.ganhou = 0; // Inicializa como não ganhou

                printf("\nDigite seu nome de usuario: ");
                scanf("%s", jogador_atual.nome);

                // Geração do numero aleatório usando a função de logica_jogo
                gerarNumero(&jogador_atual.numero_aleatorio, teste_semente_teclado, jogador_atual.nome);

                // Lógica do jogo usando a função de logica_jogo
                int resultado_do_jogo = jogar(jogador_atual.numero_aleatorio, &jogador_atual);

                // Exibe a mensagem final do jogo (parte da interface)
                if (resultado_do_jogo == 1) { // Ganhou (já exibido dentro de jogar)
                    printf("O numero aleatorio era: %d\n\n", jogador_atual.numero_aleatorio);
                } else { // Perdeu
                    printf("\n>>> VOCE PERDEU! <<<\n%s nao acertou o numero aleatorio em 5 tentativas.\nO numero aleatorio era: %d\n\n",
                        jogador_atual.nome, jogador_atual.numero_aleatorio);
                }

                // Salva o resultado no histórico usando a função de arquivos
                salvarResultado(&jogador_atual);
                break;
            }

            case 2:
                // Chama a função de arquivos para exibir o histórico
                exibirConteudoHistorico();
                break;

            case 3:
                printf("\nSaindo do jogo... Ate a proxima!\n");
                break;

            default:
                printf("\nOpcao invalida! Por favor, digite 1, 2 ou 3.\n");
                break;
        }

    } while (select_menu != 3);

    return EXIT_SUCCESS; // Retorna 0 para indicar sucesso
}
