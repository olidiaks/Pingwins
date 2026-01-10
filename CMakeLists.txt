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
        movementInteractive.c
        movementInteractive.h
        placementInteractive.c
        placementInteractive.h
        playerActions.c
        playerActions.h
        GameState.c
        GameState.h
        interactiveMode.c
        interactiveMode.h
        autonomousMode.c
        autonomousMode.h
        autonomusPlacement.h
        autonomusPlacement.c
        autonomusMovement.c
        autonomusMovement.h
        loadValidator.c
        loadValidator.h
        moveGen.c
        moveGen.h
        debug.c
        debug.h)
        moveGen.h
        binnaryTree.c
        binnaryTree.h)
