cmake_minimum_required(VERSION 3.12)
project(Proyecto4 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Proyecto4
        List.c
        List.h
        Map.c
        Map.h
        UseTDAEditor.c
        "TDA Editor.c"
        "TDA Editor.h"
        Archivos.c
        Archivos.h)
