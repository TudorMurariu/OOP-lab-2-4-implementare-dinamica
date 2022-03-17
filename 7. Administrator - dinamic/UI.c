#include "UI.h"

void Afisare(Lista lista_cheltuieli)
{
	/// <summary>
	/// Functia Afiseaza elementele unei liste si numarul de elemente din lista data.
	/// </summary>
	/// <param name="lista_cheltuieli"></param>
	printf("Numarul de elemente este : %d\n", lista_cheltuieli.len);
	for (int i = 0; i < lista_cheltuieli.len; i++)
	{
		printf("%d ", lista_cheltuieli.array[i].id);
		printf("%d %s\n", lista_cheltuieli.array[i].suma, lista_cheltuieli.array[i].tip);
	}
}

cheltuiala citire()
{
	cheltuiala c = init_cheltuiala();
	printf("ID-ul : ");
	scanf_s("%d", &c.id);

	printf("suma : ");
	scanf_s("%d", &c.suma);

	printf("tipul : ");
	scanf_s("%s", c.tip, 20);

	return c;
}


void start_console(Lista* lista_cheltuieli)
{
	/// <summary>
	/// Aceasta Funtie este responsabila de aproape tot UI-ul
	/// </summary>
	/// <param name="lista_cheltuieli"></param>
	printf("Scrieti 6 pentru a vedea toate comenzile.\n");
	while (1)
	{
		int command;
		printf("\nScrieti o comanda : ");
		scanf_s("%d", &command);
		printf("\n");

		cheltuiala c1;
		int id;
		int ok;
		int x , mod;

		switch (command)
		{
			// Exit
		case 0:
			distroy_Lista(lista_cheltuieli);
			return;
			break;

			// Adaugare 
		case 1:
			c1 = citire();
			ok = 1;

			if (!not_negative(c1.id))
				printf("ID incorect!\n"), ok = 0;
			
			if (!not_negative(c1.suma))
				printf("suma incorecta!\n"), ok = 0;

			if (!isType(c1.tip))
				printf("Tip incorect!\n"), ok = 0;

			if (ok)
			{
				ok = Adauga_s(c1, lista_cheltuieli);
				if (!ok)
					printf("ID-ul exista deja");
			}
			
			break;

			// Modificare
		case 2:
			//c = Citire_UI(*lista_cheltuieli);
			ok = 1;
			c1 = citire();

			if (!not_negative(c1.id))
				printf("ID incorect!\n"), ok = 0;

			if (!not_negative(c1.suma))
				printf("suma incorecta!\n"), ok = 0;

			if (!isType(c1.tip))
				printf("Tip incorect!\n"), ok = 0;
			
			if (ok)
			{ 
				Modifica(c1, lista_cheltuieli);
			}
			
			break;

			// Stergere
		case 3:
			printf("Id-ul : ");
			scanf_s("%d", &id);
			// stergem cheltuiala
			Sterge(id, lista_cheltuieli);
			
			break;

			// Filtrare
		case 4:
			printf("Dupa ce vreti sa filtrati lista?\n");
			printf("1 - dupa id\n");
			printf("2 - dupa suma\n");
			printf("3 - dupa tip\n");

			scanf_s("%d", &x);

			if (x == 1)
			{
				int id_x;
				scanf_s("%d", &id_x);
				Lista* new_L = Filtrare1(id_x, lista_cheltuieli);
				Afisare(*new_L);
				distroy_Lista(new_L);
			}
			else if (x == 2)
			{
				int suma_x;
				scanf_s("%d", &suma_x);
				Lista* new_L = Filtrare2(suma_x, lista_cheltuieli);
				Afisare(*new_L);
				distroy_Lista(new_L);
			}
			else if (x == 3)
			{
				char type_x[21];
				scanf_s("%s", type_x, 20);
				Lista* new_L = Filtrare3(type_x, lista_cheltuieli);
				Afisare(*new_L);
				distroy_Lista(new_L);
			}
			else
				printf("Aceasta nu este o optiune.");

			break;

			// Sortare
		case 5:
			printf("Dupa ce vreti sa sortati lista?\n");
			printf("1 - dupa suma\n");
			printf("2 - dupa tip\n");

			scanf_s("%d", &x);

			printf("1 - Crescator\n2 - Descrescator\n");
			scanf_s("%d", &mod);

			Afisare(Sortare(*lista_cheltuieli, x, mod));

			break;
		case 6:
			printf("0 pentru a inchide programul\n");
			printf("1 pentru a adauga o cheltuiala in lista\n");
			printf("2 pentru a modifica o cheltuiala existenta\n");
			printf("3 pentru a sterge o cheltuiala existenta\n");
			printf("4 Vizualizare lista de cheltuieli filtrat dupa o proprietate (suma, tipul, id)\n");
			printf("5 Vizualizare lista de cheltuieli ordonat dupa suma sau tip (crescator/descrescator)\n");
			printf("6 pentru a vedea toate comenzile\n");
			printf("7 pentru a vedea toate cheltuielile\n");
			printf("8 pentru a adauga in lista niste cheltuieli predefinite.\n");
			printf("9 sortare noua");
			break;
		case 7:
			Afisare(*lista_cheltuieli);
			break;
		case 8:
			Adauga_predefinite(lista_cheltuieli);
			printf("Cheltuielile au fost adaugate.\n");
			break;
		case 9:
			printf("Dupa ce vreti sa sortati lista?\n");
			printf("1 - dupa suma\n");
			printf("2 - dupa tip\n");

			scanf_s("%d", &x);

			printf("1 - Crescator\n2 - Descrescator\n");
			scanf_s("%d", &mod);

			sort1(lista_cheltuieli, x, mod);
			Afisare(*lista_cheltuieli);
			break;
		default:
			break;
		}
	}
}