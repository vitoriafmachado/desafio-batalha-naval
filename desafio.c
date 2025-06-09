#include <stdio.h>

#define TAB_SIZE 10
#define HAB_SIZE 5

// Função para inicializar tabuleiro com água (0) e alguns navios (3)
void inicializarTabuleiro(int tab[TAB_SIZE][TAB_SIZE]) {
    for (int i = 0; i < TAB_SIZE; i++)
        for (int j = 0; j < TAB_SIZE; j++)
            tab[i][j] = 0;

    // Colocar alguns navios para exemplo (3)
    tab[2][3] = 3;
    tab[2][4] = 3;
    tab[2][5] = 3;
    tab[5][5] = 3;
    tab[6][5] = 3;
    tab[7][5] = 3;
}

// Cria matriz Cone (5x5) apontando pra baixo
void criarCone(int cone[HAB_SIZE][HAB_SIZE]) {
    // Zera matriz
    for(int i=0; i<HAB_SIZE; i++)
        for(int j=0; j<HAB_SIZE; j++)
            cone[i][j] = 0;

    // Condição para formar o cone
    // A ideia é que na linha 0 só o centro (col 2) é 1,
    // linha 1: cols 1 a 3 = 1,
    // linha 2: cols 0 a 4 = 1,
    // só para formar o cone expandindo para baixo
    for(int i=0; i<HAB_SIZE; i++){
        int start = 2 - i; // esquerda do cone
        int end = 2 + i;   // direita do cone
        if (start < 0) start = 0;
        if (end > HAB_SIZE-1) end = HAB_SIZE-1;
        for(int j=start; j<=end; j++){
            cone[i][j] = 1;
        }
    }
}

// Cria matriz Cruz (5x5) com ponto central no meio
void criarCruz(int cruz[HAB_SIZE][HAB_SIZE]) {
    // Zera matriz
    for(int i=0; i<HAB_SIZE; i++)
        for(int j=0; j<HAB_SIZE; j++)
            cruz[i][j] = 0;

    int mid = HAB_SIZE / 2; // centro (2)

    for(int i=0; i<HAB_SIZE; i++){
        for(int j=0; j<HAB_SIZE; j++){
            // Condição cruz: mesma linha ou mesma coluna do centro
            if(i == mid || j == mid)
                cruz[i][j] = 1;
        }
    }
}

// Cria matriz Octaedro (losango) (5x5) com centro no meio
void criarOctaedro(int octaedro[HAB_SIZE][HAB_SIZE]) {
    // Zera matriz
    for(int i=0; i<HAB_SIZE; i++)
        for(int j=0; j<HAB_SIZE; j++)
            octaedro[i][j] = 0;

    int mid = HAB_SIZE / 2;

    for(int i=0; i<HAB_SIZE; i++){
        for(int j=0; j<HAB_SIZE; j++){
            // Losango: abs(i - mid) + abs(j - mid) <= mid
            int dist = (i > mid) ? (i - mid) : (mid - i);
            int dist2 = (j > mid) ? (j - mid) : (mid - j);
            if(dist + dist2 <= mid)
                octaedro[i][j] = 1;
        }
    }
}

// Função para aplicar a habilidade no tabuleiro
// Marca com 5 as posições afetadas (se não for navio)
void aplicarHabilidade(int tab[TAB_SIZE][TAB_SIZE], int hab[HAB_SIZE][HAB_SIZE], int origemLinha, int origemColuna) {
    int offset = HAB_SIZE / 2;

    for(int i=0; i<HAB_SIZE; i++){
        for(int j=0; j<HAB_SIZE; j++){
            int tabLinha = origemLinha - offset + i;
            int tabColuna = origemColuna - offset + j;

            // Verifica limites do tabuleiro
            if(tabLinha >=0 && tabLinha < TAB_SIZE && tabColuna >=0 && tabColuna < TAB_SIZE){
                if(hab[i][j] == 1){
                    // Só marca área afetada se não for navio (3)
                    if(tab[tabLinha][tabColuna] != 3){
                        tab[tabLinha][tabColuna] = 5;
                    }
                }
            }
        }
    }
}

// Função para imprimir tabuleiro com símbolos
void imprimirTabuleiro(int tab[TAB_SIZE][TAB_SIZE]) {
    for(int i=0; i<TAB_SIZE; i++){
        for(int j=0; j<TAB_SIZE; j++){
            if(tab[i][j] == 0)
                printf("~ "); // água
            else if(tab[i][j] == 3)
                printf("N "); // navio
            else if(tab[i][j] == 5)
                printf("* "); // área afetada pela habilidade
            else
                printf("? "); // qualquer outro valor
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAB_SIZE][TAB_SIZE];
    int cone[HAB_SIZE][HAB_SIZE];
    int cruz[HAB_SIZE][HAB_SIZE];
    int octaedro[HAB_SIZE][HAB_SIZE];

    // Inicializa tabuleiro e habilidades
    inicializarTabuleiro(tabuleiro);
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Definir pontos de origem fixos para cada habilidade
    int origemConeLinha = 1, origemConeColuna = 2;
    int origemCruzLinha = 5, origemCruzColuna = 5;
    int origemOctaedroLinha = 7, origemOctaedroColuna = 7;

    // Aplicar habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, origemConeLinha, origemConeColuna);
    aplicarHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzColuna);
    aplicarHabilidade(tabuleiro, octaedro, origemOctaedroLinha, origemOctaedroColuna);

    // Mostrar tabuleiro com habilidades
    printf("Tabuleiro com areas de efeito das habilidades especiais:\n\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
