#ifndef CONSOLE_H
#define CONSOLE_H

#include "game.h"

void console_draw_board(Game* g);
void console_wait_click(int* row, int* col);
void console_close(void);

#endif