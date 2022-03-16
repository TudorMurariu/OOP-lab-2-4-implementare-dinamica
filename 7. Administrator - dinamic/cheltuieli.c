#include "cheltuieli.h"

cheltuiala init_cheltuiala()
{
	/// <summary>
	/// Initiem cheltuiala
	/// </summary>
	/// <returns></returns>
	cheltuiala c;
	c.tip = (char*)malloc(sizeof(char) * 21);
	c.tip[0] = '\0';
	return c;
}

void distruge_cheltuiala(cheltuiala* c)
{
	/// <summary>
	/// distrugem cheltuiala
	/// </summary>
	/// <param name="c"></param>
	free(c->tip);
}