//
// Created by theVo on 19/11/2025.

#include "consoleVisualization.h"


void showBoard(struct GameState *gameState) {
    printf("Displaying the board.\n\n");

    char horChr, vertChr;
    unsigned short int horMul, vertMul;

    for (int x = -1; x < gameState->xBoardSize; x++) {
        for (int y = -1; y < gameState->yBoardSize; y++) {
            horChr = 65 + y % 26;
            horMul = y / 26 + 1;

            vertChr = 65 + 32 + x % 26;
            vertMul = x / 26 + 1;

            if (x == -1 && y == -1) {
                printf("\t|\t");
            } else if (x == -1) {
                printf("%c%d\t|\t", horChr, horMul);
            } else if (y == -1) {
                printf("%c%d\t|\t", vertChr, vertMul);
            } else {
                int id_player = gameState->Board[x][y].idPlayer;
                if (id_player != -1) {
                    int id_penguin = gameState->Board[x][y].idPenguin;
                    printf("P%dp%d\t|\t", id_player + 1, id_penguin + 1);
                } else {
                    printf("%d\t|\t", gameState->Board[x][y].amountOfFish);
                }
            }
        }
        printf("\n\t");
        for (int x = 0; x < gameState->yBoardSize; x++) {
            printf("================");
        }
        printf("=\n");
    }
}

void printGameInfo(struct GameState *gameState) {
    int current_player = gameState->currentPlayer;
    printf("Current player is player number: %d.\n", current_player + 1);
    printf("Current penguin is penguin number: %d.\n", gameState->Players[current_player].currentPenguin + 1);

    for (int i = 0; i < gameState->numOfPlayers; ++i) {
        printf("Player %d has %d fish.\n", i + 1, gameState->Players[i].currentScore);
    }
}

void printGameInfoMovement(struct GameState *gameState) {
    int currentPlayer = gameState->currentPlayer;
    printf("Current player is player number: %d.\n", currentPlayer + 1);

    for (int i = 0; i < gameState->numOfPlayers; ++i) {
        printf("Player %d has %d fish.\n", i + 1, gameState->Players[i].currentScore);
    }
}