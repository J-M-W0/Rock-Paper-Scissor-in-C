#include "game-pages.h"

void welcome_page() {
    printf("\t\e[3m1......Rules Explanation\e[0m\n");
    printf("\t\e[3m2......Start Game\e[0m\n");
    printf("\t\e[3m3......End   Game\e[0m\n");
    printf(">> ");
}

void rules_page() {
    printf("Rock  vs. Scissor -> Rock wins\n");
    printf("Rock  vs. Paper   -> Paper wins\n");
    printf("Paper vs. Scissor -> Scissor wins\n");
}

void game_page() {
    do {
        enum Shape player1 = rand() % NUM_SHAPES;
        printf("[Rock], [Paper], [Scissor], which one you give?\n");
        printf("[Quit] for quitting...\n");
        printf(">> ");
        char buf[BUF_SIZE];
        if (fgets(buf, sizeof(buf), stdin)) {
            
            int len = strlen(buf);
            to_lowercase(buf, len);
            if (buf[len-1] != '\n') {
                clear_input_buffer();
            }
            
            enum Shape player2;
            if (len == 5 && strcmp(buf, "rock\n") == 0) {
                player2 = Rock;
            } else if (len == 6 && strcmp(buf, "paper\n") == 0) {
                player2 = Paper;
            } else if (len == 8 && strcmp(buf, "scissor\n") == 0) {
                player2 = Scissor;
            } else if (len == 5 && strcmp(buf, "quit\n") == 0) {
                break;
            } else {
                printf("Invalid shape! Enter either 'Rock', 'Paper' or 'Scissor'!!\n");
                continue;
            }
            
            result_t result = rock_paper_scissor(player1, player2);
            if (result == win) {
                printf("You \e[1mwin\e[0m!!\n");
                win_count += 1;
            } else if (result == lose) {
                printf("You \e[1mlose\e[0m.\n");
            } else {
                // tie
                printf("It's a \e[1mtie\e[0m ~\n");
            }
        } else {
            if (feof(stdin)) {
                continue;
            } else {
                fprintf(stderr, "Some input error...\n");
                break;
            }
        }
    } while (1);
}

void update_page() {
    char choice;
    do {
        welcome_page();
        scanf("%c", &choice);
        clear_input_buffer();
        switch (choice) {
            case '1':
                rules_page();
                break;
            case '2': 
                game_page();
                break;
            case '3': 
                goto exit_game;
            default:
                printf("Invalid choice!!\n");
                break;
        }
    } while (1);

exit_game:
    return;
}

void end_page() {
    printf("End of the game. You've won %d times. Bye bye ~\n", win_count);
}
