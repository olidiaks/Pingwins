//
// Created by olidiaks on 10.12.2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(FILE* board)
{
    printf("%p \n", board);
}

FILE* open_input_file_and_handle_error(char* input_file_name)
{
    FILE* input_file = fopen(input_file_name, "r");
    if (input_file == NULL)
    {
        printf(
            "Error opening input file\nProbably path to gaven file is incorrect or program do not have enough permission for access.\n");
        exit(3);
    }
    return input_file;
}

FILE* open_output_file_and_handle_error(char* output_file_name)
{
    FILE* output_file = fopen(output_file_name, "w");
    if (output_file == NULL)
    {
        printf(
            "Error opening output file\nProbably path to gaven file is incorrect or program do not have enough permission for access.\n");
        exit(3);
    }
    return output_file;
}

void autonomous_placement(struct GameState* gameState, char input_file_name[], char output_file_name[])
{
    FILE* input_file = open_input_file_and_handle_error(input_file_name);

    FILE* output_file = open_output_file_and_handle_error(output_file_name);

    int c;
    while ((c = getc(input_file)) != EOF)
    {
        printf("%d \n", c);
    }
}

void autonomous_movement(struct GameState* gameState, char input_file_name[], char output_file_name[])
{
    FILE* input_file = open_input_file_and_handle_error(input_file_name);

    FILE* output_file = open_output_file_and_handle_error(output_file_name);
}
