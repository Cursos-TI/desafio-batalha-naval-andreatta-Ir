#include <stdio.h>

#define TAMANHO 5
#define NAVIO 3

// Inicializa o tabuleiro preenchendo todas as posições com água (~)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // Define todas as posições como água (0)
        }
    }
}

// Exibe o tabuleiro de forma visualmente melhorada
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 0)
                printf("~ "); // Representa água
            else
                printf("N "); // Representa navio
        }
        printf("\n");
    }
}

// Posiciona um navio no tabuleiro, garantindo que ele fique dentro dos limites
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    if (direcao == 0) { // Horizontal
        if (coluna + NAVIO - 1 < TAMANHO) { // Garante que o navio não ultrapasse os limites
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[linha][coluna + i] = 1;
            }
        } else {
            printf("Erro: Não é possível posicionar o navio horizontalmente na posição (%d, %d)\n", linha, coluna);
        }
    } else if (direcao == 1) { // Vertical
        if (linha + NAVIO - 1 < TAMANHO) { // Garante que o navio não ultrapasse os limites
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[linha + i][coluna] = 1;
            }
        } else {
            printf("Erro: Não é possível posicionar o navio verticalmente na posição (%d, %d)\n", linha, coluna);
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Posicionar um navio horizontalmente na linha 2, coluna 1
    posicionarNavio(tabuleiro, 2, 1, 0);
    
    // Posicionar um navio verticalmente na linha 0, coluna 3
    posicionarNavio(tabuleiro, 0, 3, 1);

    // Exibir o tabuleiro atualizado
    exibirTabuleiro(tabuleiro);

    return 0;
}
