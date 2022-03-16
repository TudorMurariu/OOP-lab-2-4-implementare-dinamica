#pragma once
#include "cheltuieli.h"

typedef struct {
	int len;
	int capacitate;
	cheltuiala *array;
}Lista;

Lista init_Lista();
void distroy_Lista(Lista* l);
