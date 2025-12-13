//
// Created by theVo on 19/11/2025.
//


#include "main.h"


int main(int argc, char *argv[]) {
    srand(10);
    FILE *p1, *p2;
    if ((p1 = fopen(*++argv,"r")) == NULL) {
        return 5;
    }
    if ((p2 = fopen(*argv,"a")) == NULL) {
        return 5;
    }
    // The file checking above has to be moved so that it doesn't trigger when the number of arguments is smaller than 2 and 3
    switch (argc) {
        case 1: interactive_mode(&gameState);
            break;
        case 2: printf("Pingwiniarze");
            break;
        case 3:
            autonomous_movement(&gameState,p1,p2);
            break;
        case 4: autonomous_placement(&gameState,p1,p2);
            break;
        default: printf("Too many arguments!");
            exit(5);
    }
    if (argc == 1) {
        interactive_mode(&gameState);
    } else {
        autonomous_placement(&gameState,p1,p2);
    }

    return 0;
}
