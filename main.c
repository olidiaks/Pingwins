//
// Created by theVo on 19/11/2025.
//


#include "main.h"

#include <time.h>


int main(int argc, char *argv[]) {
    time_t tt;

    srand(time(&tt));

    gameState.teamName = "Pingwiniarze";

    switch (argc) {
        case 1: interactiveMode(&gameState);
            break;
        case 2:
            printf("%s", gameState.teamName);
            break;
        case 4:
            autonomousMovement(&gameState, argv[2], argv[3], gameState.teamName);
            break;
        case 5:
            autonomousPlacement(&gameState, argv[3], argv[4], gameState.teamName, argv[2]);
            break;
        default: printf("Too many arguments!\nAmount of given arguments: %d\n", argc);
            exit(5);
    }

    return 0;
}
