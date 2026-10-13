#include "game.h"

// 四个检查方向：右，下，右下，左下
int dir[4][2] = {{0,1}, {1,0}, {1,1}, {1,-1}};

void game_init(Game* g)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            g->board[i][j] = '.';
        }
    }
    g->current_player = 'X';
    g->status = RUNNING;
}

void game_drop(Game* g, int r, int c)
{
    g->board[r][c] = g->current_player;

    // 落子后检测是否获胜
    if(game_check_win(g, r, c))
    {
        if(g->current_player == 'X')
            g->status = WIN_X;
        else
            g->status = WIN_O;
    }
    else
    {
        // 未胜利，切换玩家
        if (g->current_player == 'X')
            g->current_player = 'O';
        else
            g->current_player = 'X';
    }
}

// 判断(r,c)位置落子后，是否五子连珠
int game_check_win(Game* g, int r, int c)
{
    char ch = g->board[r][c];
    for(int d = 0; d < 4; d++)
    {
        int dr = dir[d][0];
        int dc = dir[d][1];
        int count = 1;

        // 正向延伸
        int nr = r + dr;
        int nc = c + dc;
        while(nr >=0 && nr < BOARD_SIZE && nc >=0 && nc < BOARD_SIZE && g->board[nr][nc]==ch)
        {
            count++;
            nr += dr;
            nc += dc;
        }
        // 反向延伸
        nr = r - dr;
        nc = c - dc;
        while(nr >=0 && nr < BOARD_SIZE && nc >=0 && nc < BOARD_SIZE && g->board[nr][nc]==ch)
        {
            count++;
            nr -= dr;
            nc -= dc;
        }
        if(count >=5)
        {
            return 1;
        }
    }
    return 0;
}