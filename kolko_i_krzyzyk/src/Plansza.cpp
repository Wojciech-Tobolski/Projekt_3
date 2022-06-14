#include "Plansza.h"
#include <limits>
#include <iostream>

/*Implementacja Planszy*/
/*Algorytm pobiera rozmiar, oraz rzad wygrywajacy*/
/*Tworzy nowa macierz 2 wymiarowa oraz uzupelnia ja pustymi polami*/
Plansza::Plansza(int rozmiar, int rzad){
	rozmiar_Planszy = rozmiar;
	rzad_Planszy = rzad;
	plansza = new Gracz *[rozmiar];
	for (int i = 0; i < rozmiar; i++){
		plansza[i] = new Gracz[rozmiar];

		for (int j = 0; j < rozmiar; j++){
			plansza[i][j] = Gracz::nikt;
		}
	}
}

/*Funkcja zamienia wartosc enum na X- pionek komputera*/
/*O - pionek gracza, oraz puste pole*/
void Plansza::wyswietlKomorke(int wiersz, int kolumna){
	if (plansza[wiersz][kolumna] == komputer) cout << "X";
	else if (plansza[wiersz][kolumna] == czlowiek) cout << "O";
	else if (plansza[wiersz][kolumna] == nikt) cout << " ";
}

/*Funkcja wsywietla plansze, oraz stosowne opisy*/
void Plansza::rysuj(){
	system("cls");
	int zmienna = 0;
	int pomocnik = 0;
	cout << "Kolko i krzyzyk" << endl;
	cout << "Rozmiar planszy: " << rozmiar_Planszy << "x" << rozmiar_Planszy << "." << endl;
	cout << "Trzeba ulozyc: " << rzad_Planszy << " symboli w rzedzie." << endl << endl;

	for (int j = 0; j < rozmiar_Planszy; j++){
		cout << "    ";
		for (int i = 0; i < rozmiar_Planszy - 1; i++){
			wyswietlKomorke(pomocnik,i);
			cout << " | ";
		}

		wyswietlKomorke(pomocnik, rozmiar_Planszy - 1);
		cout << " " << endl;

		if (zmienna < rozmiar_Planszy - 1){
			cout << "   ---";
			for (int k = 0; k < rozmiar_Planszy - 1; k++){
				cout << "|---";
			}
			cout << endl;
			zmienna += 1;
		}
		pomocnik += 1;
	}
	cout << endl;
}

/*Funkcja sprawdza pokolei wartosci planszy*/
/*Jezeli w zadnej nie ma gracza albo komputera to wynikiem rozgrywki jest remis*/
bool Plansza::remis(){
	for (int i = 0; i < rozmiar_Planszy; i++)
	{
		for (int j = 0; j < rozmiar_Planszy; j++)
		{
			if (plansza[i][j] == Gracz::nikt)
				return false;
		}
	}
	return true;
}

	bool Plansza::wygrana(Gracz gracz){
    // DZIAŁA DOBRZE
    if (sprawdz_pion(gracz))
        return true;
    if (sprawdz_poziom(gracz))
        return true;
    if (sprawdz_przekatna(gracz))
        return true;
    return false;
	}

	bool Plansza::sprawdz_pion(Gracz gracz){
    for (int i = 0; i < rozmiar_Planszy; i++){
        int linia = 0;
        for (int j = 0; j < rozmiar_Planszy; j++){
            if (plansza[i][j] == gracz)
                linia += 1;
            else if (plansza[i][j] != gracz)
                linia = 0;
            else if (linia == 0 && rozmiar_Planszy - j < rzad_Planszy)
                break;
            if (linia >= rzad_Planszy)
                return true;
        }
    }
    return false;
}

bool Plansza::sprawdz_poziom(Gracz gracz){
    for (int j = 0; j < rozmiar_Planszy; j++)
    {
        int linia= 0;
        for (int i = 0; i < rozmiar_Planszy; i++)
        {
            if (plansza[i][j] == gracz)
                linia += 1;
            else if (plansza[i][j] != gracz)
                linia = 0;
            else if (linia == 0 && rozmiar_Planszy - i < rzad_Planszy)
                break;
            if (linia >= rzad_Planszy)
                return true;
        }
    }
    return false;
}

bool Plansza::sprawdz_tablice(Gracz gracz, char *przekatna, int j){
    for (int i = j; i < j + rzad_Planszy; i++){
        if (!(gracz == przekatna[i]))
            return false;
    }
    return true;
}

bool Plansza::sprawdz_przekatna(Gracz gracz){
    char przekatna[rozmiar_Planszy + rzad_Planszy];
    int x;
    int y;
    int idx;

    for (int i = 0; i < (rozmiar_Planszy - rzad_Planszy + 1); i++){

        x = i;
        y = 0;
        idx = 0;
        for (int j = 0; j < rozmiar_Planszy - i; j++){
            przekatna[idx] = plansza[x][y];
            idx++;
            x += 1;
            y += 1;
        }
        for (int j = 0; j < sizeof(przekatna) - rzad_Planszy + 1; j++){
            if (sprawdz_tablice(gracz, przekatna, j))
                return true;
        }

        x = 0;
        y = i;
        idx = 0;
        for (int j = 0; j < rozmiar_Planszy - i; j++){
            przekatna[idx] = plansza[x][y];
            idx++;
            x += 1;
            y += 1;
        }
        for (int j = 0; j < sizeof(przekatna) - rzad_Planszy + 1; j++){
            if (sprawdz_tablice(gracz, przekatna, j))
                return true;
        }

        x = rozmiar_Planszy - 1 - i;
        y = 0;
        idx = 0;
        for (int j = 0; j < rozmiar_Planszy - i; j++){
            przekatna[idx] = plansza[x][y];
            idx++;
            x -= 1;
            y += 1;
        }
        for (int j = 0; j < sizeof(przekatna) - rzad_Planszy + 1; j++){
            if (sprawdz_tablice(gracz, przekatna, j))
                return true;
        }

        x = rozmiar_Planszy - 1;
        y = 0 + i;
        idx = 0;
        for (int j = 0; j < rozmiar_Planszy - i; j++){
            przekatna[idx] = plansza[x][y];
            idx++;
            x -= 1;
            y += 1;
        }
        for (int j = 0; j < sizeof(przekatna) - rzad_Planszy + 1; j++){
            if (sprawdz_tablice(gracz, przekatna, j))
                return true;
        }
    }
    return false;
}

/*Algorytm minimax zwraca wspolrzedne nastepnego ruchu komputera*/
Ruch Plansza::minimax(int poziom, int alpha, int beta){	

	/*Wartosc sluzy jako infinity do porownywania*/
	int wartosc = numeric_limits<int>::max();;
	Ruch ruch;
	/*Wszystkie elementy tablicy, jezeli element jest pusty to podstaw komputer*/
	for (int i = 0; i < rozmiar_Planszy; i++){
		for (int j = 0; j < rozmiar_Planszy; j++){
			if (plansza[i][j] == Gracz::nikt){
				plansza[i][j] = Gracz::komputer;
				/*podstawia najwieksza wartosc*/
				int pom = alphabeta(0,alpha,beta,1);
				if (pom < wartosc){
					wartosc = pom;
					ruch.wiersz = i;
					ruch.kolumna = j;
				}
				/*Zamienia znowu komputer na pusty*/
				plansza[i][j] = Gracz::nikt;
			}
		}

	}
	/*Zwraca ruch*/
	return ruch;
}	

/*Algorytm do znajdywania wartosci z najwieksza szansa wygranej z cieciami alpha beta*/
int Plansza::alphabeta(int poziom,int alpha,int beta,bool komputer){
	int wart = 0;
	/*Glebokosc maksymalna ustawiona na 5*/
	if(poziom<5){
		
				if(komputer){
						if (wygrana(Gracz::czlowiek)) { return 10; }
						else if (wygrana(Gracz::komputer)) { return -10; }
						else if (remis()) { return 0; }

						/*Wartosc do porownania*/
						int wartosc = numeric_limits<int>::min();

						for (int i = 0; i < rozmiar_Planszy; i++){
							for (int j = 0; j < rozmiar_Planszy; j++){
								/*Sprawdza czy puste*/
								if (plansza[i][j] == Gracz::nikt){
									/*Podstawia czlowieka*/
									/*maksymalizuje wartosci*/
									plansza[i][j] = Gracz::czlowiek;
									wartosc =  max(wartosc,alphabeta(poziom + 1, alpha, beta,0));
									alpha = max(alpha, wartosc);
									plansza[i][j] = Gracz::nikt;
									if (wartosc >= beta){
										break;
									}
								}
							}
						}
						/*Zwraca maksymalna wartosc*/
						return wartosc;
				}
				else{
					if (wygrana(Gracz::czlowiek)) { return 10; }
					else if (wygrana(Gracz::komputer)) { return -10; }
					else if (remis()) { return 0; }

					/*Wartosc do porownania sluzy jako infinity*/
					int wartosc = numeric_limits<int>::max();

					for (int i = 0; i < rozmiar_Planszy; i++){
						for (int j = 0; j < rozmiar_Planszy; j++){
							/*Jezeli element pusty*/
							if (plansza[i][j] == Gracz::nikt){
								/*Podklada komputer szuka największej wartosci*/
								plansza[i][j] = Gracz::komputer;
								wartosc = min(wartosc,alphabeta(poziom + 1, alpha, beta,1));
								beta = min(beta, wartosc);
								plansza[i][j] = Gracz::nikt;
								if (wartosc <= alpha){
									break;
								}
							}
						}
					}
					return wartosc;
				}
		}
		else return wart;
	}

/*Algorytm do przeprowadzenia ruchow, wyswietla */
void Plansza::rozgrywka(){
	int numer_Ruchu;
	int wiersz, kolumna;

	system("cls");
	cout << endl;
	cout << "   Kto zaczyna?   " << endl;
	cout << "   0 gracz   " << endl;
	cout << "   1 komputer   " << endl;
	cin >> numer_Ruchu;

	rysuj();
	while (1)
	{
		if ((numer_Ruchu % 2) == 0)
		{
			cout << "Twoj ruch" << endl;;
			cout << "Podaj wiersz i kolumne: ";
			cin >> wiersz >> kolumna;

			if ((wiersz - 1 < rozmiar_Planszy) && (kolumna - 1 < rozmiar_Planszy) && plansza[wiersz - 1][kolumna - 1] == Gracz::nikt){
				plansza[wiersz - 1][kolumna - 1] = Gracz::czlowiek;
				numer_Ruchu += 1;

				if (wygrana(Gracz::czlowiek)){
					rysuj();
					cout << "Wygrales" << endl;
					break;
				}
			}
			else{
				cout << "Bledny ruch" << endl;
				numer_Ruchu -= 2;
			}
		}

		else if ((numer_Ruchu % 2) == 1){
			int alpha = numeric_limits<int>::min();
			int beta = numeric_limits<int>::max();
			Ruch komputer = minimax(0,alpha,beta);
			plansza[komputer.wiersz][komputer.kolumna] = Gracz::komputer;
			numer_Ruchu += 1;

			if (wygrana(Gracz::komputer)){
				rysuj();
				cout << "Wygral komputer" << endl;
				break;
			}
		}

		if (remis()){
			rysuj();
			cout << "Remis" << endl;
			break;
		}
		rysuj();
	}
}

Plansza::~Plansza(){
	for (int i = 0; i < rozmiar_Planszy; i++) delete[] plansza[i];
	delete[] plansza;
}