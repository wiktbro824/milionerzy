#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <locale.h>
#include <windows.h>
#include <time.h>


using namespace std;


class pytanie1
{
    public:
    string tresc[12]; // tablica przechowujaca tesc pytania
    string odpA[12], odpB[12], odpC[12], odpD[12]; // tablice przechowujace odpowiedzi
    string poprawna[12]; // tablica przechowujaca poprawne odpowiedzi
    string odpowiedz; // odpowiedz gracza
    string potw; // potwierdzenie decyzji gracza
    int punkty[12]={500,1000,2000,5000,10000,20000,40000,75000,125000,250000,500000,1000000}; // wielkosci wygranej w kolejnych etapach
    int gwa_punkty[13]={0,0,0,0,0,10000,10000,10000,10000,10000,250000,250000,1000000}; // wielkosc gwarantowanej wygranej w kolejnych etapach
    int i;
    string Imie;

       void wczytaj() // funkcja wczytujaca pytania z pliku tekstowego
        {
            int nr_linii=1;
            string linia;
            int nr_pytania=0;

            fstream plik;
            plik.open("pytania.txt",ios::in); // otwieramy plik do odczytu

            if (plik.good()==false)
            {
                cout<<"Nie udalo sie otworzyc pliku!";
                exit(0);
            }

            while(getline(plik,linia)) // wczytuje linia po lini az napotka koniec pliku
            {
                switch(nr_linii) // wprowadzenie do tablicy danych wczytanych z pliku
                {
                    case 1: tresc[nr_pytania] = linia;       break;
                    case 2: odpA[nr_pytania] = linia;        break;
                    case 3: odpB[nr_pytania] = linia;        break;
                    case 4: odpC[nr_pytania] = linia;        break;
                    case 5: odpD[nr_pytania] = linia;        break;
                    case 6: poprawna[nr_pytania] = linia;    break;
                }

                if (nr_linii==6) {nr_linii=0; nr_pytania++;}
                nr_linii++;
            }

            plik.close(); // zamyka otwarty plik

        }
    char losujLitere() //losuje odpowiedź to koła ratunkowego
    {
        char litera;
        litera = rand() % 4 + 97;
        return litera;
    }

      void pytanie(int i, string imie) // funkcja wyslwieta pytanie
        {
            cout<<" Pytanie za "<<punkty[i]<<" zł. Jeśli odpowiesz prawidłowo masz zagwarntowane "<<gwa_punkty[i+1]<<" zł."<<endl;
            cout<<"----------------------------------------------------------------------------------------"<<endl;
            cout<<endl<<tresc[i]<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"A. "<<odpA[i]<<endl;
            cout<<"B. "<<odpB[i]<<endl;
            cout<<"C. "<<odpC[i]<<endl;
            cout<<"D. "<<odpD[i]<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"E. Koło ratunkowe"<<endl;
            cout<<"F. Kończę gre"<<endl;
            cout<<"----------------------------------------------------------------------------------------"<<endl;
            do{

           licz:     cout<<"Twoja odpowiedz: ";
                cin>>odpowiedz;
                cout<<"Jesteś pewny swojej odpowiedzi? (t/n)";
                cin>>potw;
                transform(odpowiedz.begin(), odpowiedz.end(), odpowiedz.begin(), ::tolower); //zamienia duze litery na male

            }
            while (potw!="t"); // jesli odpowie twierdzaco przechodzi dalej
            system("cls"); // czysci ekran

            if (odpowiedz==poprawna[i])
            {
                cout<<"----------------------------------------------------------------------------------------"<<endl;
                cout<<"Dobrze! Wygrywasz!"<<punkty[i]<<" zł"<<endl;
                cout<<"----------------------------------------------------------------------------------------"<<endl<<endl;

            }
            else if (odpowiedz=="e")
            {
                cout<<"Wybrałeś kolo ratunkowe!"<<endl; // TU TRZEBA DOROBIĆ KOLA RATUNKOWE !!!
                kolo: cout<<"Które wybierasz?"<<endl;
                cout<<"A. Telefon do przyjaciela"<<endl;
                cout<<"B. Pytanie do publicznosci "<<endl;
                cin>>odpowiedz;

                if (odpowiedz=="A")
                {
                    cout<<"W takim razie dzwonimy do przyjaciela!!"<<endl;
                    Sleep(500);
                    cout<<"Przyjaciel:   Cześć ! W czym Ci pomóc?" <<endl;
                    Sleep(500);
                    cout<<imie<<":   Cześć, biorę udział w grze milionerzy i utknąłem na jednym pytaniu. Oto jego treść: " <<endl;
                    Sleep(500);
                    cout<<tresc[i]<<endl;
                    Sleep(500);
                    cout<<imie<<":   A odpowiedzi to:"<<endl;
                    Sleep(500);
                    cout<<"A. "<<odpA[i]<<endl;
                    cout<<"B. "<<odpB[i]<<endl;
                    cout<<"C. "<<odpC[i]<<endl;
                    cout<<"D. "<<odpD[i]<<endl;
                    Sleep(500);
                    cout<<":   Pomożesz?"<<endl;
                    Sleep(2000);
                    cout<<"Przyjaciel:   Myślę, że będzie to odpowiedź "<<losujLitere()<<". Ale nie jestem pewny!" <<endl;
                    Sleep(500);
                    cout<<":   Bardzo Ci dziękuję za pomoc."<<endl;
                    Sleep(500);
                    cout<<"----------------------------------------------------------------------------------------"<<endl;
                    cout<<"Chcesz użyć jeszcze jedno koła ratunkowego?"<<endl;
                    cin>>odpowiedz;
                        if (odpowiedz=="nie")
                        {
                            goto licz;
                        }
                        else
                        {
                            goto kolo;
                        }
                    cout<<"Jesteś pewny swojej odpowiedzi? (t/n)";
                    cin>>potw;
                    transform(odpowiedz.begin(), odpowiedz.end(), odpowiedz.begin(), ::tolower);
                    while (potw!="t"); // jesli odpowie twierdzaco przechodzi dalej
                    system("cls"); // czysci ekran

                }
                else
                {

                }


            }
            else if (odpowiedz=="f")
            {
                cout<<"----------------------------------------------------------------------------------------"<<endl;
                cout<<"Gratuluje zakończyłeś gre z wygraną "<<punkty[i]<<" zł."<<endl;
                cout<<"----------------------------------------------------------------------------------------"<<endl;
                throw;
            }
            else{

                cout<<"----------------------------------------------------------------------------------------"<<endl;
                cout<<"Zle! Poprawna odpowiedz: "<<poprawna[i]<<endl;
                cout<<"Koniec gry. Wygraleś: "<<gwa_punkty[i]<<" zł"<<endl;
                cout<<"----------------------------------------------------------------------------------------"<<endl;
                throw;

            }
        }

};

string poczatek(){
    cout << "* * * * * * * * * * * * * *" << endl;
    cout << "* Witaj w grze Milionerzy!*" << endl;
    cout << "* * * * * * * * * * * * * *" << endl;

    cout << "Naciśnij enter by rozpocząć quiz .. "<< endl;
    cin.get();

    string Imie;

    cout <<"Jak masz na imię?" << endl;
    cin >> Imie;
    cout << endl;

    string Odpowiedz;
    cout << "Jesteś gotowy by rozpocząć quiz " << Imie << "? tak/nie" << endl;
    cin >> Odpowiedz;
    if (Odpowiedz == "tak")
    {
        cout << endl;
        cout << "okej, w takim razie powodzenia!" << endl;
    }
    else {
        cout << "okej, żegnaj!" << endl;
        throw;
    }
    return Imie;
}


int main()
{
    srand(time(NULL));
    setlocale(LC_CTYPE, "Polish");
    pytanie1 pyt;
	string imie=poczatek();
    pyt.wczytaj();

    for (int i=0; i<=11; i++)  {
       pyt.pytanie(i,imie);
    }

    return 0;
}
