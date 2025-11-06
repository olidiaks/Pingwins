//
// Created by olidiaks on 6.11.2025.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef PROJECT_PENGUINS_H
#define PROJECT_PENGUINS_H

void PlacementPhase(void);

bool allPenguinsPlaced(void);

void MovementPhase(void);

bool canAnyPenguinBeMoved(void);

int CurrentPlayer;

#endif //PROJECT_PENGUINS_H