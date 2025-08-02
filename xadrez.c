#include <stdio.h>

int main() {
    // -----------------------------
    // Movimento da Torre (FOR)
    // -----------------------------
    int movimentosTorre = 5;
    printf("Movimento da Torre:\n");
    // A torre se move horizontalmente para a direita
    for (int i = 1; i <= movimentosTorre; i++) {
        printf("Direita\n");
    }

    // -----------------------------
    // Movimento do Bispo (WHILE)
    // -----------------------------
    int movimentosBispo = 5;
    int contadorBispo = 0;
    printf("\nMovimento do Bispo:\n");
    // O bispo se move na diagonal para cima e à direita
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
    // A rainha se move para a esquerda
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha < movimentosRainha);

    return 0;
}
