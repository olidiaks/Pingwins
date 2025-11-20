//
// Created by theVo on 19/11/2025.
//

#ifndef PROJECT_MOVEMENT_H
#define PROJECT_MOVEMENT_H

#include <stdbool.h>
#include "playerActions.h"
#include "consoleVisualization.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void MovementPhase(void);

bool canAnyPenguinBeMoved(void);

int canCurrentPlayerMove(void);

void movePenguin(void);

#endif //PROJECT_MOVEMENT_H