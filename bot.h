#ifndef bot_h
#define bot_h

#define SIZE 10
#define NUM_NAVIOS 7

typedef struct {
    int x;
    int y;
} Coordenada;

void botPosicao(Coordenada navios[]);  // Declaração da função

void botAtaque(Coordenada ataques[], int *numAtaques);   // Declaração 

#endif
