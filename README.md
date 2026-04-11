# Penguins Game (Pingwiniarze)

A strategy board game implemented in C, inspired by the board game "Hey, That's My Fish!". Players take turns placing penguins on a board and moving them to collect as many fish as possible.

## Game Mechanics

1.  **Placement Phase:** Players take turns placing their penguins on any unoccupied tile that contains exactly one fish.
2.  **Movement Phase:** Players move one of their penguins in a straight line (any of the 4 cardinal directions) to an unoccupied tile.
    - When a penguin leaves a tile, the player collects the fish from that tile, and the tile disappears (becomes a hole).
    - Penguins cannot move through holes or other penguins.
3.  **End of Game:** The game ends when no player can make a move. The player with the most fish wins.

## Features

- **Interactive Mode:** Play directly in the console.
- **Autonomous Mode:** Automated gameplay designed for tournaments and grading systems.
- **AI Strategies:**
    - **Movement:** Employs Alpha-Beta pruning (Minimax optimization) to find the best move.
    - **Placement:** Uses a heuristic-based algorithm with multithreaded evaluation (pthreads) to identify optimal starting positions.
- **Save/Load:** Supports reading and writing game states from/to formatted text files.

## Project Structure

- `main.c`: Entry point, handles command-line arguments.
- `GameState.c/h`: Core data structures and state management.
- `boardGeneration.c/h`: Logic for generating new game boards.
- `consoleVisualization.c/h`: Visual representation of the board in the terminal.
- `loadValidator.c/h`: Validation and parsing of game state files.
- `autonomousMode.c/h`, `autonomusMovement.c/h`, `autonomusPlacement.c/h`: AI logic for automated phases.
- `interactiveMode.c/h`, `movementInteractive.c/h`, `placementInteractive.c/h`: Logic for human-played phases.
- `moveGen.c/h`: Move generation and validation.
- `playerActions.c/h`: Basic player actions like collecting fish and switching turns.

## File Format

The game state is stored in a text file with the following structure:

1.  **Header:** Two integers representing the board size: `[rows] [columns]`.
2.  **Board Data:** `rows` lines, each containing `columns` integers.
    - Each cell is a two-digit integer: `[FishAmount][PlayerID+1]`.
    - Example: `10` means 1 fish and no player, `21` means 2 fish and player 1, `01` means 0 fish and player 1.
3.  **Player Data:** Each player's information: `[PlayerName] [PlayerID] [Score]`.

## Compilation

You can compile the project using `gcc`:

```bash
gcc -o penguins *.c -lpthread -lm
```

## Usage

### Interactive Mode
To play the game manually in the console:
```bash
./penguins
```

### Autonomous Mode

#### 1. Phase: Placement
Automatically place a penguin on the board:
```bash
./penguins phase=placement penguins=[N] [input_file] [output_file]
```
- `[N]`: Total number of penguins each player should have.
- `[input_file]`: Path to the current game state file.
- `[output_file]`: Path where the updated game state will be saved.

#### 2. Phase: Movement
Automatically move a penguin:
```bash
./penguins phase=movement [input_file] [output_file]
```
- `[input_file]`: Path to the current game state file.
- `[output_file]`: Path where the updated game state will be saved.

#### Print Team Name
To print the team name:
```bash
./penguins name
```

## License

This project is licensed under the **GNU General Public License v2.0**. See the `LICENSE` file for details.
