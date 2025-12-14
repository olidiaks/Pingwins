//
// Created by theVo on 19/11/2025.
//


#include "main.h"


int main(int argc, char* argv[])
{
    srand(10);

    // The file checking above has to be moved so that it doesn't trigger when the number of arguments is smaller than 2 and 3
    switch (argc)
    {
    case 1: interactive_mode(&gameState);
        break;
    case 2: printf("Pingwiniarze");
        break;
    case 3:
        autonomous_movement(&gameState, argv[2], argv[3]);
        break;
    case 4: autonomous_placement(&gameState, argv[2], argv[3]);
        break;
    default: printf("Too many arguments!\nAmount of gaven arguments: %d\n", argc);
        exit(5);
    }

    return 0;
}
