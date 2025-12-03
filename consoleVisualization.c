//
// Created by theVo on 19/11/2025.

#include "consoleVisualization.h"


void showBoard(struct GameState *gameState) {
    printf("Displaying the board.\n");

    char horChr, vertChr;
    unsigned short int horMul, vertMul;

    for (int x = 0; x <= gameState->x_Board_size; x++) {
        for (int y = 0; y <= gameState->y_Board_size; y++) {

            horChr = 64 + y%26;
            horMul = y / 26 + 1;

            vertChr = 64 + 32 + x%26;
            vertMul = x / 26 + 1;

            if (x == 0 && y == 0) {
                printf("\t");
            }

            if (x == 0 && y != 0)  {
                printf("%c%d\t", horChr, horMul);
            }
            else if (y == 0 && x != 0) {
                printf("%c%d\t", vertChr, vertMul);
            }
            else if (x != 0 && y != 0) {
                if((gameState->Players[0].penguins->x == x) && (gameState->Players[0].penguins->y == y)){
                    printf("X   |\t");
                }
                else if((gameState->Players[1].penguins->x == x) && (gameState->Players[1].penguins->y == y)){
                    printf("Y   |\t");
                }
                else{
                    printf("%d   |\t", gameState->Board[x-1][y-1].amount_of_fish);
                }
                //}
                //else {
                //    printf("%d\t", gameState->Board[x-1][y-1].amount_of_fish);
                //}

            }
        }
        printf("\n\t");
        for (int x = 0; x < gameState->y_Board_size; x++) {
            printf("========");
        }
        printf("\n");
    }
}



// if (x==0) {
//     if (y==0) {
//         printf(" \t");
//     }
//     else {
//         printf("%c%d\t", c, extra);
//     }
// }
// else {
//     if (y==0) {
//         if (x == 1) {
//             c = 65 + 32;
//         }
//
//         printf("%c%d\t", c, extra);
//     }
//     else {
//         printf("%d\t", gameState->Board[x-1][y-1].amount_of_fish);
//     }
// }