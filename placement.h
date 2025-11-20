//
// Created by theVo on 19/11/2025.
//

#ifndef PROJECT_PLACEMENT_H
#define PROJECT_PLACEMENT_H

#include <stdbool.h>
#include "main.h"
#include "playerActions.h"
#include "boardGeneration.h"
#include "consoleVisualization.h"

#include <stdio.h>
#include <stdlib.h>

void placementPhase(void);

int canPlayerPlacePenguin(void);

void placePenguin(void);

bool isEveryPenguinsPlaced(void);

#endif //PROJECT_PLACEMENT_H