//
// Created by theVo on 19/11/2025.
//

#include "main.h"


int main(){
    srand(10);
    init();
    placementPhase(&gameState);
    if (isEveryPenguinsPlaced(&gameState)) {
        printf("- - - - - - - - - - \nCommencing movement phase. \n- - - - - - - - - -\n");
        movementPhase(&gameState);
        printf("No players can make any further moves.\n");
        if(gameState.Players[0].current_score > gameState.Players[1].current_score){
            printf("Congratulations, Player 1! You have won.\n");
        }
        else if(gameState.Players[0].current_score < gameState.Players[1].current_score){
            printf("Congratulations, Player 2! You have won.\n");
        }
        else{
            printf("Unfortunately or not, it's a tie!\n");
        } 
    }
    else {
        printf("Not all penguins were placed.\n");
        return 1;
    }
    return 0;
}