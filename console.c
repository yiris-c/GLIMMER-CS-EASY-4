#include "console.h"
#include <windows.h>
#include <stdio.h>

void console_draw_board(Game* g)
{
    system("cls");
    printf("===== GOBANG =====\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%c ", g->board[i][j]);
        }
        printf("\n");
    }
    if(g->status == RUNNING)
    {
        printf("Player turn: %c\n", g->current_player);
    }
    else if(g->status == WIN_X)
    {
        printf("==== X WON THE GAME! ====\n");
    }
    else if(g->status == WIN_O)
    {
        printf("==== O WON THE GAME! ====\n");
    }
}

void console_wait_click(int* row, int* col)
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD events;
    INPUT_RECORD record;

    DWORD mode;
    GetConsoleMode(hInput, &mode);
    mode |= ENABLE_MOUSE_INPUT;
    mode &= ~ENABLE_QUICK_EDIT_MODE;
    SetConsoleMode(hInput, mode);

    while (1)
    {
        ReadConsoleInput(hInput, &record, 1, &events);
        if (record.EventType == MOUSE_EVENT)
        {
            if (record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                int mouse_y = record.Event.MouseEvent.dwMousePosition.Y;
                int mouse_x = record.Event.MouseEvent.dwMousePosition.X;

                *row = mouse_y - 1;
                *col = mouse_x / 2;
                return;
            }
        }
    }
}

void console_close(void)
{
}