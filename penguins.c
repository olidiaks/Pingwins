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
    srand(time(NULL));
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
    }

}



int main(){
    PlacementPhase();
    if(allPenguinsPlaced()){
        printf("Penguins were placed successfully.\n");
    }
    else printf("Error.\n");
    return 0;
}