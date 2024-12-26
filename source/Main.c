#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "screen.h"
#include "game_logic.h"

int main() {
    int x = 25, y = 18; // �����l��m
    int score = 0;
    int x1 = -1, y1 = -1; // �ؼЪ�l��m
    char move;

    // �C���D�j��
    while (score < 1000) {
        clearScreen(); // �M���ù�
        printf("Score: %d\n", score);

        // ��s�ؼЦ�m
        updateTarget(&x1, &y1);

        // ø�s�C���e��
        drawScreen(x, y, x1, y1);

        // �P�_����O�_������ؼ�
        if (checkCollision(x, y, x1, y1)) {
            score += 100; // �W�[����
            resetTarget(&x1, &y1);
        }

        // Ū�����a��J�ç�s��m
        move = _getch();
        processInput(&x, &y, move);
    }

    clearScreen();
    printf("\n\n%20s", "You Win!!\n\n\n");
    system("pause");
    return 0;
}
