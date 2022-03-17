#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cheltuieli.h"
#include "UI.h"
#include "Lista.h"
#include "Repo.h"
#include "Service.h"
#include "Validators.h"
#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h>
#include <crtdbg.h>

void tests();

int main()
{
    // definim lista 
    Lista lista_cheltuieli = init_Lista();

    // pornim aplicatia din UI
    tests();
    start_console(&lista_cheltuieli);
    _CrtDumpMemoryLeaks();
    return 0;
}

/*
    7. Administrator imobil
    Creati o aplicatie care petmite gestiunea de cheltuieli lunare pentru
    apartamentele dintr-un bloc.
    Fiecare cheltuiala are: numarul apartamentului, suma, tipul
    (apa, canal, incalzire, gaz).

    Aplicatia permite:
    a) Adaugarea de cheltuieli pentru un apartament
    b) Modificarea unei cheltuieli existente (tipul, suma)
    c) Stergere cheltuiala
    d) Vizualizare lista de cheltuieli filtrat dupa o proprietate
    (suma, tipul,apartament)
    e) Vizualizare lista de cheltuieli ordonat dupa suma sau tip
    (crescator/descrescator)
*/



void tests()
{
    /// <summary>
    /// Aceasta functie apeleaza toate functiile de teste din program
    /// </summary>

    test_Adauga_s();
    test_isType();
    test_Adauga();
    test_Modifica();
    test_Sterge();
    test_not_negative();
    test_Adauga_predefinite();
    test_Filtrare1();
    test_Filtrare2();
    test_Filtrare3();
    test_cmp();
    test_Sortare();
    test_sort1();
}
