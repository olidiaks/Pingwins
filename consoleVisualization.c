//
// Created by theVo on 19/11/2025.

#include "consoleVisualization.h"


void showBoard(struct GameState* gameState)
{
    printf("Displaying the board.\n\n");

    char horChr, vertChr;
    unsigned short int horMul, vertMul;

    for (int x = -1; x < gameState->x_Board_size; x++)
    {
        for (int y = -1; y < gameState->y_Board_size; y++)
        {
            horChr = 65 + y % 26;
            horMul = y / 26 + 1;

            vertChr = 65 + 32 + x % 26;
            vertMul = x / 26 + 1;

            if (x == -1 && y == -1)
            {
                printf("\t|\t");
            }

            else if (x == -1)
            {
                printf("%c%d\t|\t", horChr, horMul);
            }
            else if (y == -1)
            {
                printf("%c%d\t|\t", vertChr, vertMul);
            }
            else
            {
                int id_player = gameState->Board[x][y].id_player;
                if (id_player != -1)
                {
                    int id_penguin = gameState->Board[x][y].id_penguin;
                    printf("%d %d\t|\t", id_player + 1, id_penguin + 1);
                }
                else
                {
                    printf("%d\t|\t", gameState->Board[x][y].amount_of_fish);
                }
            }
        }
        printf("\n\t");
        for (int x = 0; x < gameState->y_Board_size; x++)
        {
            printf("================");
        }
        printf("=\n");
    }
}
