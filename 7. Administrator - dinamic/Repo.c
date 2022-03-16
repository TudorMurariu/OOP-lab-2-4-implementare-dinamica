#include "Repo.h"

void Adauga(cheltuiala c, Lista* l)
{
	/// <summary>
	/// Functia adauga un element la finalul listei
	/// </summary>
	/// <param name="c"></param>
	/// <param name="l"></param> 
	
	if (l->capacitate <= l->len + 1)
	{
		int capacitate = 2 * l->capacitate;
		cheltuiala* array = (cheltuiala*)malloc(sizeof(cheltuiala) * capacitate);
		for (int i = 0; i < l->len; i++)
			array[i] = l->array[i];
		free(l->array);
		l->array = array;
		l->capacitate = capacitate;
	}
	l->array[l->len] = c;
	l->len++;
}

void Modifica(cheltuiala c, Lista* l)
{
	/// <summary>
	/// Functia modifica un element din lista daca acesta exista
	/// </summary>
	/// <param name="c"></param>
	/// <param name="l"></param>
	for (int i = 0; i < l->len; i++)
	{
		if (l->array[i].id == c.id)
		{
			l->array[i].suma = c.suma;
			strcpy_s(l->array[i].tip, 20, c.tip);
		}
	}
}

void Sterge(int id, Lista* l)
{
	/// <summary>
	/// Functia sterge un element din lista daca acesta exista
	/// </summary>
	/// <param name="id"></param>
	/// <param name="l"></param>
	int ok = 0;
	for (int i = 0; i < l->len; i++)
	{
		if (l->array[i].id == id)
		{
			ok = 1;
			distruge_cheltuiala(&l->array[i]);
		}

		if (ok && i < l->len - 1)
			l->array[i] = l->array[i + 1];
	}

	if (ok)
		l->len--;
}




Lista* Filtrare1(int id, Lista* l)
{
	/// <summary>
	/// Filtram lista data dupa un id dat
	/// returnneaza o lista in care toate elementele au acelasi id cu id ul dat.
	/// </summary>
	Lista new_L = init_Lista();

	for (int i = 0; i < l->len; i++)
	{
		if (l->array[i].id == id)
		{
			cheltuiala c1 = init_cheltuiala();
			c1.id = l->array[i].id;
			c1.suma = l->array[i].suma;
			strcpy_s(c1.tip,20, l->array[i].tip);
			Adauga(c1, &new_L);
		}
	}

	return &new_L;
}

Lista* Filtrare2(int suma, Lista* l)
{
	/// <summary>
	/// Filtram dupa suma
	/// </summary>
	/// <param name="suma"></param>
	/// <param name="l"></param>
	/// <returns>o lista raspuns in care toate elementele au suma egala cu suma data</returns>
	Lista new_L = init_Lista();

	for (int i = 0; i < l->len; i++)
	{
		if (l->array[i].suma == suma)
		{
			cheltuiala c1 = init_cheltuiala();
			c1.id = l->array[i].id;
			c1.suma = l->array[i].suma;
			strcpy_s(c1.tip, 20, l->array[i].tip);
			Adauga(c1, &new_L);
		}
	}

	return &new_L;
}

Lista* Filtrare3(char tip[21], Lista* l)
{
	/// <summary>
	/// Filtram dupa tip
	/// </summary>
	/// <param name="tip"></param>
	/// <param name="l"></param>
	/// <returns>o lista raspuns in care toate elementele au tipul dat</returns>
	Lista new_L = init_Lista();

	for (int i = 0; i < l->len; i++)
	{
		if (strcmp(l->array[i].tip, tip) == 0)
		{
			cheltuiala c1 = init_cheltuiala();
			c1.id = l->array[i].id;
			c1.suma = l->array[i].suma;
			strcpy_s(c1.tip, 20, l->array[i].tip);
			Adauga(c1, &new_L);
		}
	}

	return &new_L;
}

int cmp(cheltuiala a,cheltuiala b,int x,int mod)
{
	if (x == 1)
	{
		/// suma
		if (mod == 1)
			return a.suma > b.suma;
		return a.suma < b.suma;
	}
	else if (x == 2)
	{
		/// tip
		if (mod == 1)
			return strcmp(a.tip,b.tip) >= 1;
		return strcmp(a.tip, b.tip) < 0;
	}
	return -1;
}

Lista Sortare(Lista l, int x, int mod)
{
	/// <summary>
	/// Sortam lista data dupa suma in modul dat
	/// x = 1 => dupa suma
	/// x = 2 => dupa tip
	/// mod = 1 => Crescator
	/// mod = 0 => Descrescator
	/// </summary>
	/// <param name="l"></param>
	/// <param name="mod"></param>
	/// <returns> Lista sortata </returns>
	int ok = 1;
	while (ok)
	{
		ok = 0;
		for (int i = 0; i < l.len - 1; i++)
			if (cmp(l.array[i], l.array[i + 1], x, mod))
			{
				cheltuiala aux = l.array[i];
				l.array[i] = l.array[i + 1];
				l.array[i + 1] = aux;
				ok = 1;
			}
	}
	return l;
}



/// Teste

void test_Adauga()
{
	Lista l1 = init_Lista();
	cheltuiala c1 = init_cheltuiala();
	c1.id = 1321;
	c1.suma = 15;
	strcpy_s(c1.tip, 20, "apa");

	Adauga(c1, &l1);
	assert(l1.len == 1);
	assert(l1.array[0].id == 1321);
	assert(l1.array[0].suma == 15);
	assert(strcmp(l1.array[0].tip, "apa") == 0);
	distroy_Lista(&l1);
}

void test_Modifica()
{
	Lista l1 = init_Lista();
	cheltuiala c1 = init_cheltuiala();
	c1.id = 1321;
	c1.suma = 15;
	strcpy_s(c1.tip, 20, "apa");
	Adauga(c1, &l1);

	c1.id = 1321;
	c1.suma = 722;
	strcpy_s(c1.tip, 20, "canal");
	Modifica(c1, &l1);

	assert(l1.len == 1);
	assert(l1.array[0].id == 1321);
	assert(l1.array[0].suma == 722);
	assert(strcmp(l1.array[0].tip, "canal") == 0);

	distroy_Lista(&l1);
}

void test_Sterge()
{
	Lista l1 = init_Lista();
	cheltuiala c1 = init_cheltuiala();
	c1.id = 1321;
	c1.suma = 15;
	strcpy_s(c1.tip, 20, "apa");
	Adauga(c1, &l1);
	cheltuiala c2 = init_cheltuiala();
	c1.id = 98;
	c1.suma = 15;
	strcpy_s(c1.tip, 20, "apa");
	Adauga(c2, &l1);
	Sterge(1321, &l1);

	assert(l1.len == 1);
	distroy_Lista(&l1);
}


void test_Filtrare1()
{
	Lista l = init_Lista();
	Adauga_predefinite(&l);
	Lista* new_l = Filtrare1(5, &l);
	assert(new_l->array[0].suma == 8);
	assert(strcmp(new_l->array[0].tip,"gaz") == 0);
	distroy_Lista(new_l);
	distroy_Lista(&l);
}
void test_Filtrare2()
{
	Lista l = init_Lista();
	Adauga_predefinite(&l);
	Lista* new_l = Filtrare2(8, &l);
	assert(new_l->array[0].id == 2);
	assert(strcmp(new_l->array[0].tip, "canal") == 0);
	distroy_Lista(new_l);
	distroy_Lista(&l);
}
void test_Filtrare3()
{
	Lista l = init_Lista();
	Adauga_predefinite(&l);
	Lista* new_l = Filtrare3("apa", &l);
	assert(new_l->array[0].suma == 377);
	assert(new_l->array[0].id == 1);
	distroy_Lista(new_l);
	distroy_Lista(&l);
}

void test_cmp() 
{
	cheltuiala c1 = init_cheltuiala();
	cheltuiala c2 = init_cheltuiala();
	c1.suma = 15;
	c2.suma = 77;
	strcpy_s(c1.tip, 20, "apa");
	strcpy_s(c1.tip, 20, "gaz");

	assert(cmp(c1, c2, 1, 1) == 0);
	assert(cmp(c1, c2, 1, 2) == 1);
	assert(cmp(c1, c2, 2, 1) == 1);
	assert(cmp(c1, c2, 2, 2) == 0);
	assert(cmp(c1, c2, 7, 1) == -1);

	distruge_cheltuiala(&c1);
	distruge_cheltuiala(&c2);
}
void test_Sortare()
{
	Lista l = init_Lista();
	Adauga_predefinite(&l);
	Lista l1 = Sortare(l, 1, 1);
	assert(l1.array[2].id == 1);
	assert(l1.array[2].suma == 377);
	distroy_Lista(&l);
}