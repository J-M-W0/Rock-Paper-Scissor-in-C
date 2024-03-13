#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "game-shape.h"
#include "game-config.h"
#include "game-pages.h"
#include "game-utilities.h"

extern int win_count;

int main() {

    // init win counts.
    win_count = 0;
    
    // init random number generator.
    srand(time(NULL));
    
    printf("Welcome to the game Rock Paper Scissor.\n");
    
    update_page();

    end_page();

    return 0;
}
