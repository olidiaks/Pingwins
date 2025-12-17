//
// Created by olidiaks on 1.12.2025.
//

#include "GameState.h"


struct GameState gameState;

void init() {
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
    while (!scanf("%d", &gameState.numOfPenguinsPerPlayer) || gameState.numOfPenguinsPerPlayer < 1 || gameState.
           numOfPenguinsPerPlayer > 9) {
        printf("Please enter a number between 1 and 9.\n");
    }
}
