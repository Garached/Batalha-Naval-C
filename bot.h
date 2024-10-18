#ifndef bot_h
#define bot_h

#define SIZE 10
#define NUM_NAVIOS_BOT 10

typedef struct {
    int x;
    int y;
} Coordenada;

void botPosicao(Coordenada navios[], char tabuleiroBotInvisivel[SIZE][SIZE]);  // Declaração da função

void botAtaque(Coordenada ataques[], int *numAtaques);   // Declaração 

#endif
