#include <stdio.h>

#define TAMANHO 5
#define NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // Define todas as posições como água (0)
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int i = 0; i < NAVIO; i++) {
        if (direcao == 0 && coluna + NAVIO <= TAMANHO) {
            tabuleiro[linha][coluna + i] = 1; // Navio horizontal
        } else if (direcao == 1 && linha + NAVIO <= TAMANHO) {
            tabuleiro[linha + i][coluna] = 1; // Navio vertical
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Posicionar um navio horizontal (linha 2, coluna 1)
    posicionarNavio(tabuleiro, 2, 1, 0);
    
    // Posicionar um navio vertical (linha 0, coluna 3)
    posicionarNavio(tabuleiro, 0, 3, 1);

    // Exibir o tabuleiro com os navios
    exibirTabuleiro(tabuleiro);

    return 0;
}
