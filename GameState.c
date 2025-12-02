//
// Created by olidiaks on 1.12.2025.
//

#include "GameState.h"

#include <stdlib.h>

struct GameState gameState;

void init() {
    gameState.num_of_players = 2;
    gameState.current_player = 0;
    gameState.num_of_penguins_per_player = 4;
    gameState.Players = malloc(gameState.num_of_players * sizeof(struct Player));
    for (int i = 0; i < gameState.num_of_players; i++) {
        gameState.Players[i].current_score = 0;
        gameState.Players[i].id = i;
        gameState.Players[i].penguins = malloc(gameState.num_of_penguins_per_player * sizeof(struct Penguin));
    }
}
