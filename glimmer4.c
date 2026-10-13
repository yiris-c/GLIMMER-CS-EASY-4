#include <stdio.h>
#include "game.h"
#include "console.h"

int main(void)
{
    Game game;
    game_init(&game);
    int row, col;

    while (game.status == RUNNING)
    {
        console_draw_board(&game);
        console_wait_click(&row, &col);

        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE)
        {
            if (game.board[row][col] == '.')
            {
                game_drop(&game, row, col);
            }
        }
    }
    console_draw_board(&game);
    return 0;
}