//
// Created by olidiaks on 1.12.2025.
//

#include "GameState.h"

#include <stdio.h>
#include <stdlib.h>

struct GameState gameState;

void init() {
    askInitQuestions();
    gameState.current_player = 0;
    gameState.Players = malloc(gameState.num_of_players * sizeof(struct Player));
    for (int i = 0; i < gameState.num_of_players; i++) {
        gameState.Players[i].current_score = 0;
        gameState.Players[i].current_penguin = 0;
        gameState.Players[i].x = -1;
        gameState.Players[i].y = -1;
        gameState.Players[i].penguins = malloc(gameState.num_of_penguins_per_player * sizeof(struct Penguin));
        if (gameState.Players[i].penguins == NULL) {
            printf("The field provided is too big. You do not have enough memory.\n");
            exit(4);
        }
    }
}

void askInitQuestions() {
    printf("How many players are there?: (from 2 to 9)\n");
    int num_of_players;
    while (!scanf("%d", &num_of_players) || num_of_players < 2 || num_of_players > 9) {
        printf("Please enter a number between 2 and 9.\n");
    }
    gameState.num_of_players = num_of_players;


    printf("How many penguins should each player have?: (from 1 to 9)\n");
    while (!scanf("%d", &gameState.num_of_penguins_per_player) || gameState.num_of_penguins_per_player < 1 || gameState.
           num_of_penguins_per_player > 9) {
        printf("Please enter a number between 1 and 9.\n");
    }
}
