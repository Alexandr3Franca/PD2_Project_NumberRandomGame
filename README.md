# Projeto Jogo da Adivinhação em Linguagem C

## Descrição
Este repositório contém o projeto do "Jogo da Adivinhação", desenvolvido em Linguagem C como parte da disciplina Processamento de Dados II, da Universidade Federal do Recôncavo da Bahia (UFRB). O objetivo principal é aplicar os conhecimentos adquiridos em aula, incluindo a manipulação de structs, ponteiros, arquivos e a criação de uma interface de usuário em modo texto.

## Integrantes da Equipe (Grupo 1)
* ALEXANDRE SANTOS SILVA FRANCA 
* DANIEL BEZERRA MEDEIROS DE SOUZA
* HUGO PINA DE SOUZA
* MARCOS GABRIEL DE ALMEIDA FERREIRA BRITO

## Funcionalidades
O programa "Jogo da Adivinhação" oferece as seguintes funcionalidades:

1.  **Lógica Central do Jogo**:
    * O computador gera um número aleatório para ser adivinhado pelo jogador.
    * O jogador insere palpites até acertar o número ou esgotar as tentativas (se aplicável).
    * O sistema informa se o palpite foi alto, baixo ou correto.
    * Contagem do número de tentativas.
   

2.  **Interface com o Usuário (via `printf`)**:
    * Menu inicial para iniciar o jogo, ver histórico ou ranking.
    * Coleta do nome do jogador.
    * Exibição de mensagens durante o jogo (palpites, resultado).
    * Apresentação do histórico de jogos e do ranking de jogadores.
   

3.  **Gerenciamento de Dados do Jogador e Jogo**:
    * Utilização de `struct` para armazenar nome do jogador e número de tentativas.
    * Uso de ponteiros para passar o número aleatório e as tentativas por referência (conforme especificado).
   

4.  **Persistência de Dados (Arquivos)**:
    * Salvar o resultado final de cada partida em um arquivo `.txt` (ex: `historico.txt`).
    * Manter e atualizar um arquivo separado para o ranking dos jogadores, contendo nome e menor número de tentativas (ex: `ranking.txt`)[cite: 29].
 
5.  **Documentação e Apresentação**:
    * Criação de relatório explicativo do projeto (PDF) e apresentação de slides (PPTX).
    * Organização do código, comentários claros e explicativos.
 

## Restrições Técnicas
* Desenvolvido em Linguagem C.
* Não é permitido o uso de funções reservadas, exceto as principais e básicas das bibliotecas `<stdio.h>` e `<stdlib.h>`.
* Interface simulada com `printf`, sem bibliotecas gráficas externas.

## Organização do Projeto
* **Líder/Coordenador (opcional)**: ALEXANDRE SANTOS SILVA FRANÇA.
* **Desenvolvedores**: *ALEXANDRE SANTOS SILVA FRANÇA
* * DANIEL BEZERRA MEDEIROS DE SOUZA
* HUGO PINA DE SOUZA
* MARCOS GABRIEL DE ALMEIDA FERREIRA BRITO

## Como Executar o Programa
1.  Clone este repositório:
    ```bash
    git clone <URL-DO-SEU-REPOSITORIO-AQUI>
    ```
2.  Acesse o diretório do projeto:
    ```bash
    cd <NOME-DO-DIRETORIO-DO-PROJETO>
    ```
3.  Compile o programa (exemplo, ajuste conforme os nomes dos seus arquivos):
    ```bash
    gcc -o jogo_adivinhacao src/main.c src/logica_jogo.c src/interface.c src/arquivos.c -Wall
    ```
    (Ou, se tiver um Makefile: `make`)
4.  Execute o programa:
    ```bash
    ./jogo_adivinhacao
    ```
5.  Utilize o jogo:
    Siga as instruções exibidas no terminal para jogar, ver histórico ou ranking.

6. Para mais informações de como utilizar o jogo de maneira mais direta no vs code ou dev++ acesse a ultima página do relatorio.

## Contribuição
Este é um projeto acadêmico para a disciplina. Para contribuições dentro da equipe:
1.  Certifique-se de que sua branch local está atualizada com a branch principal remota.
2.  Crie uma branch para sua funcionalidade ou correção:
    ```bash
    git checkout -b feature/sua-nova-funcionalidade
    ```
3.  Faça as alterações e commits necessários.
4.  Envie as alterações para o repositório remoto na sua branch:
    ```bash
    git push origin feature/sua-nova-funcionalidade
    ```
5.  Abra um pull request para a branch principal do repositório do grupo.
