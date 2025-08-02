#include <stdio.h>
#include <string.h>

#define TAM 10
#define TAM_HAB 5

// Função para inicializar o tabuleiro com 0
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) printf("~ ");
            else if (tabuleiro[i][j] == 3) printf("N ");
            else if (tabuleiro[i][j] == 5) printf("* ");
        }
        printf("\n");
    }
}

// Função para posicionar um navio (tamanho 3) em linha reta (H ou V)
int posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, char direcao) {
    for (int i = 0; i < 3; i++) {
        int r = linha + (direcao == 'V' ? i : 0);
        int c = coluna + (direcao == 'H' ? i : 0);
        if (r >= TAM || c >= TAM || tabuleiro[r][c] != 0)
            return 0; // posição inválida
    }

    for (int i = 0; i < 3; i++) {
        int r = linha + (direcao == 'V' ? i : 0);
        int c = coluna + (direcao == 'H' ? i : 0);
        tabuleiro[r][c] = 3;
    }

    return 1;
}

// Função para posicionar um navio diagonal (↘ ou ↙)
int posicionarNavioDiagonal(int tabuleiro[TAM][TAM], int linha, int coluna, char direcao) {
    for (int i = 0; i < 3; i++) {
        int r = linha + i;
        int c = direcao == 'D' ? coluna + i : coluna - i;
        if (r >= TAM || c < 0 || c >= TAM || tabuleiro[r][c] != 0)
            return 0;
    }

    for (int i = 0; i < 3; i++) {
        int r = linha + i;
        int c = direcao == 'D' ? coluna + i : coluna - i;
        tabuleiro[r][c] = 3;
    }

    return 1;
}

// Gera matriz cone 5x5
void gerarCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++)
        for (int j = 0; j < TAM_HAB; j++)
            matriz[i][j] = (i >= j && j >= TAM_HAB - 1 - i) ? 1 : 0;
}

// Gera matriz cruz 5x5
void gerarCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++)
        for (int j = 0; j < TAM_HAB; j++)
            matriz[i][j] = (i == TAM_HAB/2 || j == TAM_HAB/2) ? 1 : 0;
}

// Gera matriz octaedro 5x5 (losango)
void gerarOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++)
        for (int j = 0; j < TAM_HAB; j++)
            matriz[i][j] = (abs(i - TAM_HAB/2) + abs(j - TAM_HAB/2) <= TAM_HAB/2) ? 1 : 0;
}

// Aplica uma habilidade no tabuleiro a partir de um ponto de origem
void aplicarHabilidade(int tabuleiro[TAM][TAM], int hab[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int r = origemLinha - TAM_HAB/2 + i;
            int c = origemColuna - TAM_HAB/2 + j;
            if (r >= 0 && r < TAM && c >= 0 && c < TAM && hab[i][j] == 1 && tabuleiro[r][c] != 3)
                tabuleiro[r][c] = 5;
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);

    // Posiciona navios
    posicionarNavio(tabuleiro, 1, 1, 'H');
    posicionarNavio(tabuleiro, 4, 2, 'V');
    posicionarNavioDiagonal(tabuleiro, 0, 6, 'E'); // ↙
    posicionarNavioDiagonal(tabuleiro, 6, 0, 'D'); // ↘

    // Gera as matrizes de habilidade
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplica habilidades com origem em posições fixas
    aplicarHabilidade(tabuleiro, cone, 2, 2);       // cone no canto superior esquerdo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);   // octaedro no canto inferior direito

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
