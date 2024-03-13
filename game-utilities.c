#include "game-utilities.h"

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void to_lowercase(char * s, int len) {
    if (len <= 0) {
        return;
    }
    
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
}

result_t rock_paper_scissor(enum Shape player1, enum Shape player2) {
    printf("=> The computer gives: ");
    display_shape(player1);
    printf("=> You          give : ");
    display_shape(player2);
    
    if (player1 == player2) {
        return tie;
    }

    if (player1 == Rock) {
        if (player2 == Paper) {
            return win;
        } else {
            return lose;
        }
    } else if (player1 == Paper) {
        if (player2 == Scissor) {
            return win;
        } else {
            return lose;
        }
    } else {
        // player1 == Scissor
        if (player2 == Rock) {
            return win;
        } else {
            return lose;
        }
    }
}

void display_shape(enum Shape shape) {
    switch (shape) {
        case Rock:
            printf("\e[1;31mrock\e[0m\n");
            break;
        case Paper:
            printf("\e[1;33mpaper\e[0m\n");
            break;
        case Scissor:
            printf("\e[1;34mscissor\e[0m\n");
            break;
        default:
            fprintf(stderr, "Unknown error...\n");
            break;
    }
}





