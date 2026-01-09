//
// Created by theVo on 09/01/2026.
//

#ifndef PROJECT_DEBUG_H
#define PROJECT_DEBUG_H

#include "GameState.h"


struct snapshot {
    struct GameState *gs;
    int snapshotId;
};

int generateSnapshot(struct GameState *gs);

void drawMoves();

#endif //PROJECT_DEBUG_H