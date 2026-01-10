//
// Created by olidiaks on 17.12.2025.
//

#include "autonomusPlacement.h"

#include "autonomusMovement.h"
#include "placementInteractive.h"

void countPenguins(struct GameState *gameState, int numOfPengiuns) {
    int playerId = gameState->currentPlayer + 1;
    int counter = 0;

    for (int x = 0; x < gameState->xBoardSize; ++x) {
        for (int y = 0; y < gameState->yBoardSize; ++y) {
            if (gameState->Board[x][y].idPlayer == playerId) {
                counter++;
                if (counter == numOfPengiuns) {
                    printf("All penguins placed.\n");
                    exit(1);
                }
            }
        }
    }
}

void autonomousPlacement(struct GameState *gameState, char inputFilePath[], char outputFilePath[], char nameOfUs[],
                         char num_of_penguins[]) {
    char c = num_of_penguins[9];
    int num_of_penguins_int = atoi(&c);

    FILE *inputFile = openInputFileAndHandleError(inputFilePath);
    fclose(inputFile);

    inputFile = fopen(inputFilePath, "r");
    loadBoard(inputFile, gameState);
    fclose(inputFile);

    inputFile = fopen(inputFilePath, "r");
    loadPlayers(gameState, inputFile);
    fclose(inputFile);

    loadPenguins(gameState);

    countPenguins(gameState, num_of_penguins_int);

    placePenguinAutomatically(gameState);
    FILE *outputFile = openOutputFileAndHandleError(outputFilePath);
    writeBoardToFile(outputFile, gameState);
    printf("File has been written into.\n");
    fclose(outputFile);
}

void placePenguinAutomatically(struct GameState *gameState) {
    pthread_t threads[NUM_THREADS];
    struct ThreadData threadData[NUM_THREADS];

    int rowsPerThread = gameState->xBoardSize / NUM_THREADS;

    for (int i = 0; i < NUM_THREADS; ++i) {
        threadData[i].gameState = gameState;
        threadData[i].startX = i * rowsPerThread;
        threadData[i].threadId = i;

        if (i == NUM_THREADS - 1) {
            threadData[i].endX = gameState->xBoardSize;
        } else {
            threadData[i].endX = (i + 1) * rowsPerThread;
        }
        if (pthread_create(&threads[i], NULL, findBestMoveWorker, (void *) &threadData[i])) {
            printf("Error: unable to create thread, %d\n", i);
            exit(3);
        }
    }

    int bestScore = 0;
    int bestX = -1;
    int bestY = -1;


    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);

        if (threadData[i].bestScore > bestScore) {
            bestScore = threadData[i].bestScore;
            bestX = threadData[i].x;
            bestY = threadData[i].y;
        }
    }

    if (bestScore != -1) {
        int current_player = gameState->currentPlayer;
        gameState->Players[current_player].x = bestX;
        gameState->Players[current_player].y = bestY;
        gameState->Board[bestX][bestY].idPlayer = current_player + 1;
        collectFish(gameState);
        printf("Penguin has been placed successfully.\n"
               "X: %d\nY:%d\n",
               bestX, bestY);
    } else {
        printf("Didn't found any penguin to place.\n");
        exit(1);
    }
}

int scorePlacement(struct GameState *game_state, int x, int y, struct Node *binaryTree, int depth) {
    if (depth == 0) {
        return 0;
    }

    if (x < 0 || y < 0 || x >= game_state->xBoardSize || y >= game_state->yBoardSize)
        return 0;

    int amountOfFish = game_state->Board[x][y].amountOfFish;
    if (amountOfFish == 0)
        return 0;

    if (insertNode(binaryTree, &game_state->Board[x][y]) != binaryTree)
        return 0;

    return scorePlacement(game_state, x - 1, y, binaryTree, depth - 1) +
           scorePlacement(game_state, x + 1, y, binaryTree, depth - 1) +
           scorePlacement(game_state, x, y - 1, binaryTree, depth - 1) +
           scorePlacement(game_state, x, y + 1, binaryTree, depth - 1) + amountOfFish;
}
