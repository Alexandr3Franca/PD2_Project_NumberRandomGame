#include <stdio.h>  // Para operações básicas (printf, scanf).
#include <stdlib.h> // Para srand, e EXIT_SUCCESS (indicador de sucesso).
#include <time.h>   // Para time(), usada com srand.

// Incluímos os cabeçalhos de todos os nossos módulos.
// Isso permite que o 'main' chame as funções definidas neles.
#include "logica_jogo.h" // Módulo de lógica do jogo.
#include "interface.h"   // Módulo de interface com o usuário.
#include "arquivos.h"    // Módulo de manipulação de arquivos (histórico e ranking).

// --- A Função principal: Onde o jogo ganha vida ---
// Esta é a função 'main', o ponto de entrada do programa.
// Ela gerencia o fluxo geral, chamando as funções dos outros módulos conforme necessário.
int main() {
    // Inicializa o gerador de números aleatórios APENAS UMA VEZ no início.
    // Usar 'time(NULL)' garante que a sequência de números seja diferente a cada execução.
    srand(time(NULL));

    int select_menu;               // Guarda a opção selecionada no menu.
    int teste_semente_teclado;     // Entrada do usuário para a semente de geração do número.

    // Array para armazenar os 3 melhores jogadores do ranking.
    // É uma estrutura que existe enquanto o programa está rodando.
    Jogador ranking_top3[3];
    // Ao iniciar, tentamos carregar o ranking salvo em disco.
    carregarRanking(ranking_top3);

    // Loop principal do jogo: mantém o menu ativo até o usuário escolher sair.
    do {
      // --- CHAMA A FUNÇÃO mostrarMenu AQUI ---
        // Passamos o ENDEREÇO (&) de teste_semente_teclado para a função mostrarMenu.
        // A função vai preencher essa variável e retornar a opção do menu.
        select_menu = mostrarMenu(&teste_semente_teclado);

        // Estrutura 'switch' para lidar com as diferentes opções do menu.
        switch (select_menu) {
            case 1: { // Opção "Jogar": Inicia uma nova partida.
                Jogador jogador_atual;         // Declara a struct para o jogador desta rodada.
                jogador_atual.ganhou = 0;      // Por padrão, presume-se que não ganhou ainda.

                printf("\nDigite seu nome de usuario: ");
                scanf("%s", jogador_atual.nome); // Solicita o nome do jogador.

                // Chama a função do módulo 'logica_jogo' para gerar o número secreto.
                // Passa o endereço (&) para que a função escreva o número diretamente na struct.
                gerarNumero(&jogador_atual.numero_aleatorio, teste_semente_teclado, jogador_atual.nome);

                // Chama a função 'jogar' (do módulo 'logica_jogo') para iniciar a interação da partida.
                // Passa o número secreto e o endereço da struct do jogador para que suas tentativas e palpites sejam atualizados.
                int resultado_do_jogo = jogar(jogador_atual.numero_aleatorio, &jogador_atual);

                // Exibe uma mensagem final sobre o resultado do jogo.
                if (resultado_do_jogo == 1) { // Se o jogo retornou 1 (vitória).
                    printf("O numero aleatorio era: %d\n\n", jogador_atual.numero_aleatorio);
                } else { // Se o jogo retornou 0 (derrota).
                    printf("\n>>> VOCE PERDEU! <<<\n%s nao acertou o numero aleatorio em 5 tentativas.\nO numero aleatorio era: %d\n\n",
                        jogador_atual.nome, jogador_atual.numero_aleatorio);
                }

                // Salva os detalhes desta partida no arquivo de histórico.
                salvarResultado(&jogador_atual);
                // Tenta atualizar e salvar o ranking com o resultado do jogador desta rodada.
                atualizarESalvarRanking(&jogador_atual, ranking_top3);
                break;
            }

            case 2: // Opção "Ver Historico": Exibe todas as partidas jogadas.
                // Chama a função do módulo 'arquivos' para mostrar o histórico.
                exibirConteudoHistorico();
                break;

            case 3: // Opção "Ver Ranking": Exibe o TOP 3 dos jogadores.
                // Chama a função do módulo 'arquivos' para exibir o ranking.
                exibirRanking(ranking_top3);
                break;

            case 4: // Opção "Sair": Finaliza o programa.
                printf("\nSaindo do jogo... Ate a proxima!\n");
                break;

            default: // Caso o usuário digite uma opção inválida.
                printf("\nOpcao invalida! Por favor, digite 1, 2, 3 ou 4.\n");
                break;
        }

    } while (select_menu != 4); // O loop continua enquanto a opção "Sair" não for escolhida.

    return EXIT_SUCCESS; // Retorna 0, indicando que o programa foi executado com sucesso.
}