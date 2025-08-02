#include <stdio.h>

// Tamanho fixo do tabuleiro e dos navios
#define TAM 10
#define NAVIO 3
#define OCUPADO 3

// Função que verifica se o espaço está livre para o navio
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < NAVIO; i++) {
        int l = linha + (direcao == 1 ? i : (diagonal == 1 ? i : (diagonal == 2 ? -i : 0)));
        int c = coluna + (direcao == 0 ? i : (diagonal == 1 ? i : (diagonal == 2 ? i : 0)));

        if (l < 0 || l >= TAM || c < 0 || c >= TAM || tabuleiro[l][c] != 0) {
            return 0; // Fora dos limites ou já ocupado
        }
    }
    return 1;
}

// Função que posiciona o navio
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < NAVIO; i++) {
        int l = linha + (direcao == 1 ? i : (diagonal == 1 ? i : (diagonal == 2 ? -i : 0)));
        int c = coluna + (direcao == 0 ? i : (diagonal == 1 ? i : (diagonal == 2 ? i : 0)));
        tabuleiro[l][c] = OCUPADO;
    }
}

// Função para imprimir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Inicializa com água (0)

    // Posicionar navio horizontal (linha 1, coluna 1)
    if (podePosicionar(tabuleiro, 1, 1, 0, 0)) {
        posicionarNavio(tabuleiro, 1, 1, 0, 0);
    }

    // Posicionar navio vertical (linha 5, coluna 2)
    if (podePosicionar(tabuleiro, 5, 2, 1, 0)) {
        posicionarNavio(tabuleiro, 5, 2, 1, 0);
    }

    // Posicionar navio diagonal ↘ (linha 3, coluna 3)
    if (podePosicionar(tabuleiro, 3, 3, 0, 1)) {
        posicionarNavio(tabuleiro, 3, 3, 0, 1);
    }

    // Posicionar navio diagonal ↙ (linha 6, coluna 1)
    if (podePosicionar(tabuleiro, 6, 1, 0, 2)) {
        posicionarNavio(tabuleiro, 6, 1, 0, 2);
    }

    // Exibir tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
