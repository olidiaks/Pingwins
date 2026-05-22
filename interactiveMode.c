//
// Created by olidiaks on 10.12.2025.
//

#include "interactiveMode.h"


void interactiveMode(struct GameState *gameState) {
    init();
    placementInteractiveMode(gameState);
    if (isEveryPenguinsPlaced(gameState)) {
        movementPhaseInteractiveMode(gameState);
        showBoard(gameState);
        printf("No players can make any further moves.\n");
        show_winner_announcement(gameState);
    } else {
        printf("Not all penguins were placed.\n");
        exit(1);
    }
}

void show_winner_announcement(struct GameState *gameState) {
    printf("- - - - - - - - - - Announcing winner!!! - - - - - - - - - -\n\n");

    bool isTie = false;
    int winningPlayer = 0;
    int winningFish = 0;
    for (int i = 0; i < gameState->numOfPlayers; i++) {
        int current_score = gameState->Players[i].currentScore;
        if (current_score > winningFish) {
            winningFish = current_score;
            printf("Player %d has %d", i + 1, current_score);
            isTie = false;
        }
        else {
            isTie = true;
        }
    }
    if (isTie) {
        printf("Unfortunately or not, it's a tie!\n");
    } else {
printf("Player %d won with %d fish!\n", winningPlayer + 1, winningFish);
    }
}
