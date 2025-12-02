//
// Created by olidiaks on 1.12.2025.
//

#include "GameState.h"

struct GameState gameState;

void init() {
    gameState.num_of_players = 2;
    gameState.current_player = 0;
    for (int i = 0; i < gameState.num_of_players; i++) {
        gameState.Players[i].current_score = 0;
        gameState.Players[i].id = i;
    }
}
