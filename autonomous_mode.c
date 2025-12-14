//
// Created by olidiaks on 10.12.2025.
//

#include <stdio.h>
#include <string.h>

void readFile(FILE * board) {
    printf("%p \n", board);
}

void autonomous_placement(struct GameState *gameState, FILE * in_board, FILE * out_board) {
    int c;
    while ((c = getc(in_board)) != EOF) {
        printf("%d \n",c);
    }
}

void autonomous_movement(struct GameState *gameState, FILE * in_board, FILE * out_board) {
}

