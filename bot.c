#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//tamanho do tabuleiro (10x10)
#define SIZE 10  
// qtd de navios dele
#define NUM_NAVIOS 7

// Estrutura para armazenar a posição do navio
typedef struct {
    int x;
    int y;
} Coordenada;

void posicaoBot() {
    int x, y;
    int i = 0;
    srand(time(NULL)); // Números aeatorios

    while (i < NUM_NAVIOS) {
        x = rand() % SIZE; // Gera uma coordenada x aleatória
        y = rand() % SIZE; // Gera uma coordenada y aleatória
        int posLivre = 1;

        // Verifica se a posição já está ocupada
        for (int j = 0; j < i; j++) {
            if (navios[j].x == x && navios[j].y == y) {
                posLivre = 0;
                break;
            }
        }

        if (posLivre) {
            navios[i].x = x - 1;
            navios[i].y = y - 1;
            i++;
        }
    }
}

// ataque aleatório
void ataqueBot(Coordenada ataques[], int *numAtaques) {
    int x, y;
    int posLivre = 1;
    srand(time(NULL));

    do {
        posLivre = 1; //posição livre
        x = rand() % SIZE; // Gera uma coordenada x aleatória
        y = rand() % SIZE; // Gera uma coordenada y aleatória

        // Verifica se o ataque já foi feito
        for (int j = 0; j < *numAtaques; j++) {
            if (ataques[j].x == x && ataques[j].y == y) {
                posLivre = 0;
                break;
            }
        }
    } while (!posLivre);

    ataques[*numAtaques].x = x -1;
    ataques[*numAtaques].y = y-1;
    (*numAtaques)++;
}

