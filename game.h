#ifndef GAME_H
#define GAME_H

#define BOARD_SIZE 9
#define RUNNING 1
#define WIN_X 2
#define WIN_O 3

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char current_player;
    int status; // 游戏状态 RUNNING / WIN_X / WIN_O
} Game;

void game_init(Game* g);
void game_drop(Game* g, int r, int c);
int game_check_win(Game* g, int r, int c);

#endif