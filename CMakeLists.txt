cmake_minimum_required(VERSION 4.0)
project(project C)

set(CMAKE_C_STANDARD 11)

add_executable(project
        BoardGeneration.c
        BoardGeneration.h
        ConsoleVisualization.c
        ConsoleVisualization.h
        main.c
        main.h
        Movement.c
        Movement.h
        Placement.c
        Placement.h
        PlayerActions.c
        PlayerActions.h)
