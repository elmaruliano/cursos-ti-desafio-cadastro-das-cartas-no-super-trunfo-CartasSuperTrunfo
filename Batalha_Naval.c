#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define MAR 0
#define NAVIO 3

/* ----------------------------------------
   Função para inicializar o tabuleiro com água (0)
   ---------------------------------------- */
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = MAR;
        }
    }
}

/* ----------------------------------------
   Função para imprimir o tabuleiro
   ---------------------------------------- */
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\nTabuleiro:\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

/* ----------------------------------------
   Função para posicionar navio horizontal
   ---------------------------------------- */
int posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (coluna + TAM_NAVIO > TAM_TABULEIRO) return 0; // fora do limite

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != MAR) return 0; // sobreposição
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }

    return 1;
}

/* ----------------------------------------
   Função para posicionar navio vertical
   ---------------------------------------- */
int posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO) return 0; // fora do limite

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != MAR) return 0; // sobreposição
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }

    return 1;
}

/* ----------------------------------------
   Função principal do desafio Batalha Naval
   ---------------------------------------- */
void desafioBatalhaNaval() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Definindo coordenadas diretamente no código
    int linhaH = 2, colunaH = 3; // navio horizontal
    int linhaV = 5, colunaV = 6; // navio vertical

    // Tenta posicionar os navios e valida
    if (!posicionarNavioHorizontal(tabuleiro, linhaH, colunaH)) {
        printf("Erro: Navio horizontal fora do limite ou sobreposto.\n");
    }

    if (!posicionarNavioVertical(tabuleiro, linhaV, colunaV)) {
        printf("Erro: Navio vertical fora do limite ou sobreposto.\n");
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);
}

