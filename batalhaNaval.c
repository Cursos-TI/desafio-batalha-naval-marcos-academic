#include <stdio.h>

#define TAMANHO_TABULEIRO 10   // Tamanho fixo do tabuleiro
#define TAMANHO_NAVIO 3        // Tamanho fixo dos navios
#define AGUA 0                 // Representa água
#define NAVIO 3                // Representa parte de navio

int main() {
    // Declara a matriz do tabuleiro (10x10) e inicializa com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais do navio horizontal (linha e coluna)
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    // Coordenadas iniciais do navio vertical (linha e coluna)
    int linhaVertical = 5;
    int colunaVertical = 7;

    // ======================== POSICIONANDO NAVIO HORIZONTAL ========================
    // Verifica se o navio horizontal cabe no tabuleiro e não ultrapassa os limites
    if (colunaHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se já existe outro navio na posição (evita sobreposição)
            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] == AGUA) {
                tabuleiro[linhaHorizontal][colunaHorizontal + i] = NAVIO;
            } else {
                printf("Erro: Sobreposição detectada ao posicionar navio horizontal!\n");
                return 1;
            }
        }
    } else {
        printf("Erro: Navio horizontal ultrapassa os limites do tabuleiro!\n");
        return 1;
    }

    // ======================== POSICIONANDO NAVIO VERTICAL ========================
    // Verifica se o navio vertical cabe no tabuleiro e não ultrapassa os limites
    if (linhaVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se já existe outro navio na posição (evita sobreposição)
            if (tabuleiro[linhaVertical + i][colunaVertical] == AGUA) {
                tabuleiro[linhaVertical + i][colunaVertical] = NAVIO;
            } else {
                printf("Erro: Sobreposição detectada ao posicionar navio vertical!\n");
                return 1;
            }
        }
    } else {
        printf("Erro: Navio vertical ultrapassa os limites do tabuleiro!\n");
        return 1;
    }

    // ======================== EXIBINDO O TABULEIRO ========================
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n");

    // Percorre cada linha do tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        // Percorre cada coluna da linha atual
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe 0 (água) ou 3 (navio)
        }
        printf("\n"); // Nova linha ao final de cada linha do tabuleiro
    }

    return 0;
}
