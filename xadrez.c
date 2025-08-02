#include <stdio.h>

/* ----------------------------------------
   Função Recursiva - Torre (Direita)
   ---------------------------------------- */
void moverTorre(int casasRestantes) {
    if (casasRestantes <= 0) return;
    printf("Direita\n");
    moverTorre(casasRestantes - 1);
}

/* ----------------------------------------
   Função Recursiva + Loops Aninhados - Bispo
   Diagonal para cima e à direita
   ---------------------------------------- */
void moverBispoRecursivo(int casasRestantes) {
    if (casasRestantes <= 0) return;

    // Lógica de recursividade (imprime e chama recursivamente)
    printf("Cima Direita\n");

    // Extra: loops aninhados simulando "componentes" da diagonal
    for (int i = 0; i < 1; i++) { // movimento vertical
        for (int j = 0; j < 1; j++) { // movimento horizontal
            // Estas seriam operações adicionais se estivéssemos alterando posições
            // Aqui apenas imprimimos para representar o passo duplo
            // O printf real está acima
        }
    }

    moverBispoRecursivo(casasRestantes - 1);
}

/* ----------------------------------------
   Função Recursiva - Rainha (Esquerda)
   ---------------------------------------- */
void moverRainha(int casasRestantes) {
    if (casasRestantes <= 0) return;
    printf("Esquerda\n");
    moverRainha(casasRestantes - 1);
}

/* ----------------------------------------
   Movimento Complexo do Cavalo (Loops Aninhados)
   2 casas para cima + 1 casa para direita
   ---------------------------------------- */
void moverCavaloComplexo() {
    int movimentosVerticais = 2;
    int movimentosHorizontais = 1;

    printf("Movimento do Cavalo:\n");

    for (int i = 1; i <= movimentosVerticais; i++) {
        // Simula movimento para cima
        if (i == 2) {
            printf("Cima\n");
            for (int j = 1; j <= movimentosHorizontais; j++) {
                if (j == 1) {
                    printf("Direita\n");
                    break; // Cavalo só precisa de um passo horizontal nesse "L"
                }
            }
        } else {
            // Primeiro passo para cima
            printf("Cima\n");
            continue;
        }
    }
}

/* ----------------------------------------
   Função principal
   ---------------------------------------- */
int main() {
    // -------------------------------
    // Torre - 5 movimentos para direita (Recursiva)
    // -------------------------------
    printf("Movimento da Torre:\n");
    moverTorre(5);

    // -------------------------------
    // Bispo - 5 movimentos em diagonal (Recursiva + Loops Aninhados)
    // -------------------------------
    printf("\nMovimento do Bispo:\n");
    moverBispoRecursivo(5);

    // -------------------------------
    // Rainha - 8 movimentos para esquerda (Recursiva)
    // -------------------------------
    printf("\nMovimento da Rainha:\n");
    moverRainha(8);

    // -------------------------------
    // Cavalo - movimento em "L" (Loops aninhados complexos)
    // -------------------------------
    printf("\n");
    moverCavaloComplexo();

    return 0;
}
