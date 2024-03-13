#ifndef __GAME_UTILITIES_H
#define __GAME_UTILITIES_H
#include <stdio.h>

#include "game-shape.h"
#include "game-config.h"

void clear_input_buffer();
void to_lowercase(char * s, int len);
result_t rock_paper_scissor(enum Shape player1, enum Shape player2);
void display_shape(enum Shape shape);


#endif // __GAME_UTILITIES_H
