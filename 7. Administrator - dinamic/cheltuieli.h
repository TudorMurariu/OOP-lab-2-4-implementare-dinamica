#pragma once
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;

    int suma;

    char *tip;
}cheltuiala;

cheltuiala init_cheltuiala();
void distruge_cheltuiala(cheltuiala* c);