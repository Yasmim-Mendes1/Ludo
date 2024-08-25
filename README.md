# Jogo de Tabuleiro: Ludo

Este é um jogo de Ludo para dois jogadores, onde cada jogador possui quatro peões e o objetivo é movê-los pelo tabuleiro conforme as regras do dado. O código foi desenvolvido em C e simula o jogo de forma básica.

## Estrutura do Código

O código é composto por várias funções que gerenciam o estado do jogo e a interação com os jogadores. A seguir, descrevemos a função de cada parte principal do código.

### Estruturas de Dados

- **cadastro**: Estrutura que representa um peão com as seguintes propriedades:
  - `base`: Estado do peão (1 se estiver na base, 0 caso contrário).
  - `posicao`: Posição atual do peão no tabuleiro.
  - `casas_finais`: Número de casas finais que o peão já percorreu.

### Funções

- **Tabuleiro**: Exibe a posição atual dos peões no tabuleiro para ambos os jogadores.
  ```c
  void Tabuleiro(cadastro (*peao[2][4]));
