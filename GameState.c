//
// Created by olidiaks on 1.12.2025.
//

#include "GameState.h"


struct GameState gameState;

void init() {
    gameState.teamName = "Pingwiniarze";
    askInitQuestions();
    gameState.currentPlayer = 0;
    gameState.Players = malloc(gameState.numOfPlayers * sizeof(struct Player));
    for (int i = 0; i < gameState.numOfPlayers; i++) {
        gameState.Players[i].currentScore = 0;
        gameState.Players[i].currentPenguin = 0;
        gameState.Players[i].x = -1;
        gameState.Players[i].y = -1;
        gameState.Players[i].penguins = malloc(gameState.numOfPenguinsPerPlayer * sizeof(struct Penguin));
        if (gameState.Players[i].penguins == NULL) {
            printf("The field provided is too big. You do not have enough memory.\n");
            exit(4);
        }
    }
}

void askInitQuestions() {
    printf("How many players are there?: (from 2 to 9)\n");
    int numOfPlayers;
    while (!scanf("%d", &numOfPlayers) || numOfPlayers < 2 || numOfPlayers > 9) {
        printf("Please enter a number between 2 and 9.\n");
    }
    gameState.numOfPlayers = numOfPlayers;

    printf("How many penguins should each player have?: (from 1 to 9)\n");
    while (!scanf("%d", &gameState.numOfPenguinsPerPlayer) || gameState.numOfPenguinsPerPlayer < 1 ||
           gameState.numOfPenguinsPerPlayer > 9) {
        printf("Please enter a number between 1 and 9.\n");
    }
}

struct GameState *deepCloneGameState(struct GameState *gameState) {
    struct GameState copyOfGameState;
    copyOfGameState.teamName = gameState->teamName;
    copyOfGameState.currentPlayer = gameState->currentPlayer;
    copyOfGameState.numOfPlayers = gameState->numOfPlayers;
    copyOfGameState.numOfPenguinsPerPlayer = gameState->numOfPenguinsPerPlayer;
    copyOfGameState.xBoardSize = gameState->xBoardSize;
    copyOfGameState.yBoardSize = gameState->yBoardSize;
    copyOfGameState.Board = malloc(gameState->xBoardSize * sizeof(struct Field *));
    for (int x = 0; x < gameState->xBoardSize; x++) {
        copyOfGameState.Board[x] = malloc(gameState->yBoardSize * sizeof(struct Field));
        for (int y = 0; y < gameState->yBoardSize; y++) {
            struct Field *copyTile = &gameState->Board[x][y];
            struct Field *oldTile = &gameState->Board[x][y];
            copyTile->amountOfFish = oldTile->amountOfFish;
            copyTile->idPlayer = oldTile->idPlayer;
            copyTile->idPenguin = oldTile->idPenguin;
        }
    }
    copyOfGameState.Players = malloc(gameState->numOfPlayers * sizeof(struct Player));
    for (int i = 0; i < gameState->numOfPlayers; i++) {
        struct Player *copyPlayer = &copyOfGameState.Players[i];
        struct Player *oldPlayer = &gameState->Players[i];
        copyPlayer->currentScore = oldPlayer->currentScore;
        copyPlayer->currentPenguin = oldPlayer->currentPenguin;
        copyPlayer->x = oldPlayer->x;
        copyPlayer->y = oldPlayer->y;
        copyPlayer->penguins = malloc(gameState->numOfPenguinsPerPlayer * sizeof(struct Penguin));
        copyPlayer->name = oldPlayer->name;
        for (int j = 0; j < gameState->numOfPenguinsPerPlayer; j++) {
            struct Penguin *copyPenguin = &copyOfGameState.Players[i].penguins[j];
            struct Penguin *oldPenguin = &gameState->Players[i].penguins[j];
            copyPenguin->x = oldPenguin->x;
            copyPenguin->y = oldPenguin->y;
        }
    }

    return &copyOfGameState;
}
