#include <iostream>
#include <limits>
#include "Plansza.h"

using namespace std;

int main()
{
	int rozmiar, rzad;
	system("cls");
	cout << "Podaj rozmiar planszy: ";
	cin >> rozmiar;
	cout << "Podaj ilosc symboli w rzedzie potrzebnych do wygrania: ";
	cin >> rzad;

	if (rozmiar < rzad)
	{
		system("cls");
		cout << "Podales bledna dana, ilosc symboli w rzedzie nie moze byc wieksza niz rozmiar" << endl;
		cout << "Podaj rzad planszy: ";
		cin >> rzad;
	}

	Plansza item(rozmiar,rzad);
	item.rozgrywka();

	system("pause");
	return 0;
}