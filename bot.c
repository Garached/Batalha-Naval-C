#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "bot.h"  

void botPosicao() {
  int x,y; //coordenadas de onde ele tá
}


// 
void botAtaque(){
  int x,y; //coordenadas do ataque
  if (ELE ACERTAR) {
    printf("O BOT atacou em (%d, %d) e acertou um navio!\n", x, y);
    jogador->grid[x][y] = 'X';  // Já que ele atingiu um navio se fosse num papel teria um X na coordenada que ele acertou tlg?
    } 
  else {
    printf("O BOT atacou em (%d, %d) e acertou água... :(\n", x, y);
    jogador->grid[x][y] = 'A';  // Coloca um A na matriz indicando que essa coordenada já foi atacada e que foi água!
    }
}
