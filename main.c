//
// Created by theVo on 19/11/2025.
//


#include "main.h"

#include <time.h>


int main(int argc, char *argv[]) {
    time_t tt;

    srand(time(&tt));

    gameState.teamName = "Pingwiniarze";
    char *nameOfUs = gameState.teamName;

    switch (argc) {
        case 1: interactive_mode(&gameState);
            break;
        case 2:
            printf("%s", nameOfUs);
            break;
        case 4:
            autonomousMovement(&gameState, argv[2], argv[3], nameOfUs);
            break;
        case 5:
            autonomousPlacement(&gameState, argv[3], argv[4], nameOfUs);
            break;
        default: printf("Too many arguments!\nAmount of given arguments: %d\n", argc);
            exit(5);
    }

    return 0;
}
