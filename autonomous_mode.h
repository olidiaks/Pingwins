//
// Created by olidiaks on 10.12.2025.
//

#ifndef PROJECT_AUTONOMOUS_MODE_H
#define PROJECT_AUTONOMOUS_MODE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "GameState.h"

void readFile(char*[]);

void autonomous_placement(struct GameState *gameState, FILE * in_board, FILE * out_board);

void autonomous_movement(struct GameState *gameState, FILE * in_board, FILE * out_board);

#endif //PROJECT_AUTONOMOUS_MODE_H
