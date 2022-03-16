#include "Lista.h"

Lista init_Lista()
{
	/// <summary>
	/// Initiem lista
	/// </summary>
	/// <returns></returns>
	Lista l;
	l.len = 0;
	l.capacitate = 2;
	l.array = (cheltuiala*)malloc(sizeof(cheltuiala) * 2);
	return l;
}

void distroy_Lista(Lista* l)
{
	/// <summary>
	/// distrugem lista
	/// </summary>
	/// <param name="l"></param>
	for (int i = 0; i < l->len; i++)
		distruge_cheltuiala(&l->array[i]);
	free(l->array);
}
