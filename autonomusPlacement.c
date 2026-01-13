//
// Created by olidiaks on 17.12.2025.
//

#include "autonomusPlacement.h"

#include <math.h>

#include "autonomusMovement.h"
#include "placementInteractive.h"

void countPenguins(struct GameState *gameState, int numOfPengiuns) {
    int playerId = gameState->currentPlayer;
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

void autonomousPlacement(struct GameState *gameState, char inputFilePath[], char outputFilePath[], char nameOfUs[], char num_of_penguins[]) {
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
    long numThreads = sysconf(_SC_NPROCESSORS_ONLN);
    if (numThreads < 1)
        numThreads = 1;
    printf("Number of threads: %ld\n", numThreads);
    if (numThreads > gameState->xBoardSize)
        numThreads = gameState->xBoardSize;
    pthread_t threads[numThreads];
    struct ThreadData threadData[numThreads];

    int rowsPerThread = gameState->xBoardSize / numThreads;

    for (int i = 0; i < numThreads; ++i) {
        threadData[i].gameState = gameState;
        threadData[i].startX = i * rowsPerThread;
        threadData[i].threadId = i;

        if (i == numThreads - 1) {
            threadData[i].endX = gameState->xBoardSize;
        } else {
            threadData[i].endX = (i + 1) * rowsPerThread;
        }
        if (pthread_create(&threads[i], NULL, findBestMoveWorker, (void *) &threadData[i])) {
            printf("Error: unable to create thread, %d\n", i);
            exit(3);
        }
    }

    int bestScore = INT_MIN;
    int bestX = -1;
    int bestY = -1;


    for (int i = 0; i < numThreads; ++i) {
        pthread_join(threads[i], NULL);

        if (threadData[i].bestScore > bestScore) {
            bestScore = threadData[i].bestScore;
            bestX = threadData[i].x;
            bestY = threadData[i].y;
        }
    }

    if (bestScore > INT_MIN) {
        int current_player = gameState->currentPlayer;
        gameState->Players[current_player].x = bestX;
        gameState->Players[current_player].y = bestY;
        gameState->Board[bestX][bestY].idPlayer = current_player;
        collectFish(gameState);
        printf("Penguin has been placed successfully.\n"
               "X: %d\nY:%d\n",
               bestX, bestY);
    } else {
        printf("Didn't found any penguin to place.\n");
        exit(1);
    }
}

int scorePlacement(struct GameState *game_state, int x, int y, struct Node *binaryTree, int depth, int xStart, int yStart) {
    if (depth == 0) {
        return 0;
    }

    float distance = -(1 - 1 / sqrtf(powf(x - xStart, 2) + powf(y - yStart, 2))) * 70;
    printf("Distance: %f\n", distance);

    if (x < 0 || y < 0 || x >= game_state->xBoardSize || y >= game_state->yBoardSize)
        return -distance;

    int amountOfFish = game_state->Board[x][y].amountOfFish;

    if (game_state->Board[x][y].idPlayer != -1) {
        return -distance * 2;
    }

    if (amountOfFish == 0)
        return -distance;

    struct Field *value = &game_state->Board[x][y];
    if (searchNode(binaryTree, value) == value)
        return 0;

    insertNode(binaryTree, value);

    return scorePlacement(game_state, x - 1, y, binaryTree, depth - 1, xStart, yStart) +
           scorePlacement(game_state, x + 1, y, binaryTree, depth - 1, xStart, yStart) +
           scorePlacement(game_state, x, y - 1, binaryTree, depth - 1, xStart, yStart) +
           scorePlacement(game_state, x, y + 1, binaryTree, depth - 1, xStart, yStart) +
           amountOfFish * (1 - 1 / depth) * 2;
}
void *findBestMoveWorker(void *arg) {
    struct ThreadData *data = (struct ThreadData *) arg;
    data->bestScore = INT_MIN;
    data->x = -1;
    data->y = -1;

    for (int x = data->startX; x < data->endX; ++x) {
        for (int y = 0; y < data->gameState->yBoardSize; ++y) {
            if (data->gameState->Board[x][y].amountOfFish == 1) {
                struct Node *binaryTreeForMoves = insertNode(NULL, 0);
                int score = scorePlacement(data->gameState, x, y, binaryTreeForMoves, 200, x, y);
                freeTree(binaryTreeForMoves);
                if (score > data->bestScore) {
                    data->bestScore = score;
                    data->x = x;
                    data->y = y;
                }
            }
        }
    }
    printf("Thread: %d finished.\tScore: %d\tX: %d\tY: %d\n", data->threadId, data->bestScore, data->x, data->y);
    pthread_exit(NULL);
}
