#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int CurrentPlayer;

void ReadBoardDimensions(){
    printf("Reading board dimensions...\n");
}

void SetCurrentPlayer(){
    CurrentPlayer = 0;
}

void GenerateRandomBoard(){
    printf("Generating random board...\n");
}

int canPlayerPlacePenguin(){
    int chance = rand() % 20;
    return chance >= 1;
}

void ShowBoard(){
    printf("Displaying the board.\n");
}

void askCoordinates(){

}

int ValidCoordinates(){
    srand(time(NULL));
    int chance = rand() % 5;
    return chance >= 1;
}

void placePenguin(){
    printf("Player %d 's penguin has been placed.\n",CurrentPlayer+1);
}

void collectFish(){
    printf("Player %d has collected fish.\n",CurrentPlayer+1);

}

void changeCurrentPlayer(){
    CurrentPlayer = !CurrentPlayer;
    printf("Changing players...\n");
}

int allPenguinsPlaced(){
    srand(time(NULL));
    int chance = rand() % 2;
    return chance == 1;
}

void PlacementPhase(){
    ReadBoardDimensions();
    SetCurrentPlayer();
    GenerateRandomBoard();
    while (canPlayerPlacePenguin()){
        ShowBoard();
        do{
            askCoordinates();
            ValidCoordinates();
        } while (!ValidCoordinates());
        placePenguin();
        collectFish();
        canPlayerPlacePenguin();
        allPenguinsPlaced();
        changeCurrentPlayer();
    }

}

int canAnyPenguinBeMoved(){
    srand(time(NULL));
    int chance = rand() % 50;
    return chance >= 1;
}

int canCurrentPlayerMove(){
    srand(time(NULL));
    int chance = rand() % 2;
    return chance == 1;
}

void inputMovementCoordinates(){

}

int ValidMovementCoordinates(){

}

void movePenguin(){
    printf("Player %d 's penguin has been moved.\n",CurrentPlayer+1);
}

void MovementPhase(){
    while(canAnyPenguinBeMoved()){
        ShowBoard();
        while(canCurrentPlayerMove()){
            do {
                inputMovementCoordinates();
            } while (!ValidMovementCoordinates());
            movePenguin();
            collectFish();
            changeCurrentPlayer();

        }
    }
}



int main(){
    srand(time(NULL));
    PlacementPhase();
    if(allPenguinsPlaced()){
        printf("Penguins were placed successfully. Moving onto the Movement Phase.\n");
        MovementPhase();
        if(!canAnyPenguinBeMoved()){
            printf("The game has ended.\n");
        }

    }
    else printf("Error.\n");
    return 0;
}