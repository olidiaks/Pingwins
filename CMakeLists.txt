cmake_minimum_required(VERSION 4.0)
project(project C)

set(CMAKE_C_STANDARD 11)

add_executable(project
        boardGeneration.c
        boardGeneration.h
        consoleVisualization.c
        consoleVisualization.h
        main.c
        main.h
        movement.c
        movement.h
        placement.c
        placement.h
        playerActions.c
        playerActions.h
        GameState.c
        GameState.h
        interactive_mode.c
        interactive_mode.h)
