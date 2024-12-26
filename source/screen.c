#include "screen.h"
#include <stdio.h>
#include <windows.h>

void clearScreen() {
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}

void drawScreen(int x, int y, int x1, int y1) {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            if (i == y && j == x) {
                printf("*"); // ¨¤¦â
            }
            else if (i == y1 && j == x1) {
                printf("+"); // ¥Ø¼Ð
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
