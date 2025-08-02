#include <stdio.h>

int main() {
    // -----------------------------
    // Movimento da Torre (FOR)
    // -----------------------------
    int movimentosTorre = 5;
    printf("Movimento da Torre:\n");
    for (int i = 1; i <= movimentosTorre; i++) {
        printf("Direita\n");
    }

    // -----------------------------
    // Movimento do Bispo (WHILE)
    // -----------------------------
    int movimentosBispo = 5;
    int contadorBispo = 0;
    printf("\nMovimento do Bispo:\n");
    while (contadorBispo < movimentosBispo) {
        printf("Cima Direita\n");
        contadorBispo++;
    }

    // -----------------------------
    // Movimento da Rainha (DO-WHILE)
    // -----------------------------
    int movimentosRainha = 8;
    int contadorRainha = 0;
    printf("\nMovimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha < movimentosRainha);

    // -----------------------------
    // Movimento do Cavalo (FOR + WHILE)
    // -----------------------------
    // O Cavalo se move em "L": 2 para baixo, 1 para esquerda
    // Vamos usar um FOR para o movimento para baixo (2 vezes)
    // E um WHILE aninhado para o movimento à esquerda (1 vez)
    int movimentosBaixo = 2;
    int movimentosEsquerda = 1;

    printf("\nMovimento do Cavalo:\n");

    for (int i = 0; i < movimentosBaixo; i++) {
        printf("Baixo\n");

        // WHILE aninhado será executado somente na última repetição do FOR
        if (i == movimentosBaixo - 1) {
            int j = 0;
            while (j < movimentosEsquerda) {
                printf("Esquerda\n");
                j++;
            }
        }
    }

    return 0;
}
