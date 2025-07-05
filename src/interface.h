#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>

// Protótipos das funções de interface do usuário.

// Exibe o menu principal e coleta a opção escolhida pelo usuário.
// 'teste_semente_teclado_ptr': Ponteiro para onde o número de semente lido será armazenado.
// Retorna a opção numérica selecionada.
int mostrarMenu(int *teste_semente_teclado_ptr);

#endif // INTERFACE_H