//
// Created by theVo on 09/01/2026.
//

#include "GameState.h"
#include "debug.h"

struct GameState snapshotGlobal[500] = {};
int snapshotCount = 0;

int generateSnapshot(struct GameState *gs) {

    struct GameState *cloned = deepCloneGameState(gs);
    snapshotGlobal[snapshotCount] = *cloned;
    snapshotCount++;

    return snapshotCount - 1;
};

void drawMoves() {

};