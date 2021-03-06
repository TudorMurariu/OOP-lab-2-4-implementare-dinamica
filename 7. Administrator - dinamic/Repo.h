#pragma once
#include "Lista.h"
#include <assert.h>
#include "Service.h"
#include "UI.h"

void Adauga(cheltuiala c, Lista* l);
void Modifica(cheltuiala c, Lista* l);
void Sterge(int id, Lista* l);

Lista* Filtrare1(int id, Lista* l);
Lista* Filtrare2(int suma, Lista* l);
Lista* Filtrare3(char tip[21], Lista* l);

int cmp(cheltuiala a, cheltuiala b, int x, int mod);
Lista Sortare(Lista l, int x, int mod);

void test_Adauga();
void test_Modifica();
void test_Sterge();

void test_Filtrare1();
void test_Filtrare2();
void test_Filtrare3();

void test_cmp();
void test_Sortare();
void sort1(Lista* l, int x, int mod);
void test_sort1();