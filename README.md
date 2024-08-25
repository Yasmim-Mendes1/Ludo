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
- **RolarDado**: Simula o lançamento de um dado e retorna um número entre 1 e 6.
  ```c
  int RolarDado();
- **TresSeis**: Lança o dado e verifica se o jogador tirou um, dois ou três seis consecutivos.
  ```c
  int TresSeis(int *dado);
- **TrocarJogador**: Alterna entre o jogador 0 e o jogador 1.
  ```c
  int TrocarJogador(int *jogador_atual);
- **MoverPeoes**: Esta função ainda não está implementada. É responsável por mover os peões de acordo com a regra do dado.
  ```c
  int MoverPeoes(cadastro *peoes, int *base, int dado, int jogador_atual);
- **CasasFinais**: Verifica se o peão chegou às casas finais e atualiza a posição conforme necessário.
  ```c
  void CasasFinais(cadastro *peao[2][4], int jogador_atual, int peao_escolhido);
- **MoverCF**: Move o peão para as casas finais, se necessário, de acordo com o número tirado no dado.
  ```c
  void MoverCF(cadastro *peao[2][4], int jogador_atual, int peao_escolhido, int dado);

## Fluxo Principal

1. Inicializa o tabuleiro e os peões para ambos os jogadores.
2. Em um loop contínuo, o jogo pede ao jogador atual para rolar o dado e mover os peões.
3. Dependendo do resultado do dado, o jogo executa as seguintes ações:
   - Caso o jogador tire um ou mais seis, ele pode mover seus peões ou tirar peões da base.
   - Se três seis consecutivos forem rolados, a vez do jogador termina e o jogo é encerrado.
   - Caso o jogador não tire seis, o peão é movido conforme o número do dado.
4. Alterna para o próximo jogador após cada rodada.

## Compilação e Execução

Para compilar e executar o código, siga os passos abaixo:

1. **Compilação**:
   ```bash
   gcc -o ludo ludo.c
2. **Execução**:
   ```bash
   ./ludo

## Requisitos

- Compilador C (por exemplo, `gcc`)
- Sistema operacional compatível com a compilação de C

## Contribuições

Contribuições para melhorar o código e adicionar novas funcionalidades são bem-vindas. Para contribuir, por favor, abra um pull request ou entre em contato comigo!
