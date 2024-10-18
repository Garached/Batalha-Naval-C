#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define NUM_NAVIOS_BOT_BOT 10 // AUMENTEI PRA 10

// Estrutura para armazenar a posição do navio
typedef struct {
    int x;
    int y;
} Coordenada;



// Função para gerar a posição aleatória dos navios do bot
void posicaoBot(Coordenada navios[], char tabuleiroBotInvisivel[SIZE][SIZE]) {
    int x, y;
    int i = 0;
    srand(time(NULL)); 

    while (i < NUM_NAVIOS_BOT) {
        x = rand() % SIZE; // Gera uma coordenada x aleatória
        y = rand() % SIZE; // Gera uma coordenada y aleatória
        int posLivre = 1;

        // Verifica se a posição já está ocupada
        if (tabuleiroBotInvisivel[x][y] == 'X') {
            posLivre = 0;
        }

        if (posLivre) {
            navios[i].x = x;
            navios[i].y = y;
                tabuleiroBotInvisivel[x][y] = 'X'; // Marca a posição do navio no tabuleiro vulgo na matriz
            i++;
        }
    }
}

// Função para o bot atacar (jogar aleatoriamente)
void ataqueBot(Coordenada ataques[], int *numAtaques) {
    int x, y;
    int posLivre = 1;
    srand(time(NULL));

    do {
        posLivre = 1;
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

    ataques[*numAtaques].x = x;
    ataques[*numAtaques].y = y;
    (*numAtaques)++;
}

