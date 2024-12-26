#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "screen.h"

void updateTarget(int* x1, int* y1);
void resetTarget(int* x1, int* y1);
int checkCollision(int x, int y, int x1, int y1);
void processInput(int* x, int* y, char move);

#endif
