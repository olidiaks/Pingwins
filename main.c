//
// Created by theVo on 19/11/2025.
//


#include "main.h"


int main(int argc, char *argv[]) {
    srand(10);
    switch (argc) {
        case 1: interactive_mode(&gameState);
            break;
        case 2: printf("Wojownik_pospolity");
            break;
        case 3: autonomus_movement(&gameState);
            break;
        case 4: autonomus_placement(&gameState);
            break;
        default: printf("Too many arguments!");
            exit(5);
    }
    if (argc == 1) {
        interactive_mode(&gameState);
    } else {
        autonomus_placement(&gameState);
    }

    return 0;
}
