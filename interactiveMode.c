//
// Created by olidiaks on 10.12.2025.
//

#include "interactiveMode.h"


void interactiveMode(struct GameState *gameState) {
    init();
    placementInteractiveMode(gameState);
    if (isEveryPenguinsPlaced(gameState)) {
        printf("- - - - - - - - - - \nCommencing movement phase. \n- - - - - - - - - -\n");
        movementPhaseInteractiveMode(gameState);
        showBoard(gameState);
        printf("No players can make any further moves.\n");
        if (gameState->Players[0].currentScore > gameState->Players[1].currentScore) {
            printf("Congratulations, Player 1! You have won.\n");
        } else if (gameState->Players[0].currentScore < gameState->Players[1].currentScore) {
            printf("Congratulations, Player 2! You have won.\n");
        } else {
            printf("Unfortunately or not, it's a tie!\n");
        }
    } else {
        printf("Not all penguins were placed.\n");
        exit(1);
    }
}
