#include "game_logic.h"
#include <stdlib.h>

void updateTarget(int* x1, int* y1) {
    if (*x1 == -1 && *y1 == -1) {
        *x1 = rand() % SCREEN_WIDTH;
        *y1 = rand() % SCREEN_HEIGHT;
    }
}

void resetTarget(int* x1, int* y1) {
    *x1 = -1;
    *y1 = -1;
}

int checkCollision(int x, int y, int x1, int y1) {
    return x == x1 && y == y1;
}

void processInput(int* x, int* y, char move) {
    switch (move) {
    case 'w': // 向上
        if (*y > 0) (*y)--;
        break;
    case 's': // 向下
        if (*y < SCREEN_HEIGHT - 1) (*y)++;
        break;
    case 'a': // 向左
        if (*x > 0) (*x)--;
        break;
    case 'd': // 向右
        if (*x < SCREEN_WIDTH - 1) (*x)++;
        break;
    default:
        break; // 忽略其他輸入
    }
}
