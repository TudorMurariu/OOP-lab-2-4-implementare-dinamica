#include "Service.h"

void Adauga_predefinite(Lista* l)
{
	/// Adaugam in lista cheltuieli predefinite
	
	cheltuiala c1 = init_cheltuiala();
	c1.id = 1;
	c1.suma = 377;
	strcpy_s(c1.tip, 20, "apa");
	cheltuiala c2 = init_cheltuiala();
	c2.id = 2;
	c2.suma = 8;
	strcpy_s(c2.tip, 20, "canal");
	cheltuiala c3 = init_cheltuiala();
	c3.id = 3;
	c3.suma = 989;
	strcpy_s(c3.tip, 20, "apa");
	cheltuiala c4 = init_cheltuiala();
	c4.id = 4;
	c4.suma = 12345;
	strcpy_s(c4.tip, 20, "apa");
	cheltuiala c5 = init_cheltuiala();
	c5.id = 5;
	c5.suma = 8;
	strcpy_s(c5.tip, 20, "gaz");

	Adauga(c1, l);
	Adauga(c2, l);
	Adauga(c3, l);
	Adauga(c4, l);
	Adauga(c5, l);
}

int Adauga_s(cheltuiala c1,Lista* lista_cheltuieli)
{
	/// <summary>
	/// Verificam daca adaugarea este valida
	/// </summary>
	/// <param name="c1"></param>
	/// <param name="lista_cheltuieli"></param>
	/// <returns></returns>
	 
	for (int i = 0; i < lista_cheltuieli->len; i++)
		if (lista_cheltuieli->array[i].id == c1.id)
			return 0;

	Adauga(c1, lista_cheltuieli);
	return 1;
}

void test_Adauga_s()
{
	Lista l = init_Lista();
	cheltuiala c1 = init_cheltuiala();

	assert(1 == Adauga_s(c1, &l));
	assert(0 == Adauga_s(c1, &l));

	distroy_Lista(&l);
}

void test_Adauga_predefinite()
{
	Lista l = init_Lista();
	Adauga_predefinite(&l);
	assert(l.array[0].id == 1);
	assert(l.array[5].suma == 8);
	assert(l.array[4].id == 4);
}