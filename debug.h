//
// Created by theVo on 09/01/2026.
//

#ifndef PROJECT_DEBUG_H
#define PROJECT_DEBUG_H

#include "GameState.h"


/**
 * @struct snapshot
 * @brief Represents a snapshot of the current game state at a specific point in time.
 *
 * The snapshot struct is used to capture and store the state of the game, along with
 * an associated snapshot ID for reference or management purposes.
 *
 * @details
 * - The `gs` member is a pointer to a `GameState` struct, which represents the current
 *   status of the game, including player data, board configuration, and other relevant details.
 * - The `snapshotId` is an identifier that can be used to reference or track this specific
 *   snapshot for various operations like debugging, rollback, or analysis.
 */
struct snapshot {
    struct GameState *gs;
    int snapshotId;
};

/**
 * @brief Generates a snapshot of the given game state and stores it globally.
 *
 * This function creates a copy of the provided game state, stores it in a global
 * array for persistent reference, and returns the identifier of the newly
 * created snapshot. The snapshot ID can be used to retrieve or reference this
 * specific snapshot later.
 *
 * @param gs A pointer to the `GameState` structure representing the current game state to be captured.
 *
 * @return An integer representing the unique identifier of the created snapshot.
 *         This ID can be used to access the snapshot from the global storage.
 */
int generateSnapshot(struct GameState *gs);

/**
 * @fn drawMoves
 * @brief Outputs the available moves or actions for debugging purposes in the current game context.
 *
 * This function is used to display or log the valid moves or options available in the game,
 * primarily for diagnostic and debugging tasks carried out during development.
 *
 * @details
 * It processes the game state and outputs comprehensive information about possible moves
 * to assist developers in identifying inconsistencies or verifying game logic.
 */
void drawMoves();

#endif //PROJECT_DEBUG_H