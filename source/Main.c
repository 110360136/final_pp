#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "screen.h"
#include "game_logic.h"

int main() {
    int x = 25, y = 18; // 角色初始位置
    int score = 0;
    int x1 = -1, y1 = -1; // 目標初始位置
    char move;

    // 遊戲主迴圈
    while (score < 1000) {
        clearScreen(); // 清除螢幕
        printf("Score: %d\n", score);

        // 更新目標位置
        updateTarget(&x1, &y1);

        // 繪製遊戲畫面
        drawScreen(x, y, x1, y1);

        // 判斷角色是否捕捉到目標
        if (checkCollision(x, y, x1, y1)) {
            score += 100; // 增加分數
            resetTarget(&x1, &y1);
        }

        // 讀取玩家輸入並更新位置
        move = _getch();
        processInput(&x, &y, move);
    }

    clearScreen();
    printf("\n\n%20s", "You Win!!\n\n\n");
    system("pause");
    return 0;
}
