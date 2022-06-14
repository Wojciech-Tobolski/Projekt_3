#include <iostream>
//#include <iomanip>
//#include <algorithm>
#include <limits>

using namespace std;

enum Gracz
{
	komputer = 'X',
	czlowiek = 'O',
	nikt = '0'
};

struct Ruch
{
	int wiersz;
	int kolumna;
};

class Plansza
{

	Gracz ** plansza;
	int rozmiar_Planszy;
	int rzad_Planszy;

public:
	Plansza(int rozmiar, int rzad);
	
	void wyswietlKomorke(int wiersz, int kolumna);
	void rysuj();
	bool remis();
	bool wygrana(Gracz gracz);
	bool sprawdz_pion(Gracz gracz);
	bool sprawdz_poziom(Gracz gracz);
	bool sprawdz_tablice(Gracz gracz, char *przekatna, int j);
	bool sprawdz_przekatna(Gracz gracz);
	int alphabeta(int poziom, int alpha, int beta,bool komputer);
	Ruch minimax(int poziom, int alpha, int beta);
	void rozgrywka();
	~Plansza();
};