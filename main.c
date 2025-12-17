//
// Created by theVo on 19/11/2025.
//


#include "main.h"


int main(int argc, char *argv[]) {
    srand(10);

    switch (argc) {
        case 1: interactive_mode(&gameState);
            break;
        case 2: printf("Pingwiniarze");
            break;
        case 4:
            autonomousMovement(&gameState, argv[2], argv[3]);
            break;
        case 5: autonomousPlacement(&gameState, argv[2], argv[3]);
            break;
        default: printf("Too many arguments!\nAmount of gaven arguments: %d\n", argc);
            exit(5);
    }

    return 0;
}
