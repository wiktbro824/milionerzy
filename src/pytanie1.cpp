#include "pytanie1.h"

pytanie1::pytanie1(int i)
{
    string tresc[12]; // tablica przechowujaca tesc pytania
    string odpA[12], odpB[12], odpC[12], odpD[12]; // tablice przechowujace odpowiedzi
    string poprawna[12]; // tablica przechowujaca poprawne odpowiedzi
    string odpowiedz; // odpowiedz gracza
    string potw; // potwierdzenie decyzji gracza
    int punkty[12]={500,1000,2000,5000,10000,20000,40000,75000,125000,250000,500000,1000000}; // wielkosci wygranej w kolejnych etapach
    int gwa_punkty[13]={0,0,0,0,0,10000,10000,10000,10000,10000,250000,250000,1000000}; // wielkosc gwarantowanej wygranej w kolejnych etapach
    int i;
}

void pytanie1::wczytaj() // funkcja wczytujaca pytania z pliku tekstowego
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
//pytanie1::~wczytaj()

void pytanie1::pytanie(int i) // funkcja wyslwieta pytanie
        {
            cout<<" Pytanie za "<<punkty[i]<<" z³. Jeœli odpowiesz prawid³owo masz zagwarntowane "<<gwa_punkty[i+1]<<" z³."<<endl;
            cout<<"----------------------------------------------------------------------------------------"<<endl;
            cout<<endl<<tresc[i]<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"A. "<<odpA[i]<<endl;
            cout<<"B. "<<odpB[i]<<endl;
            cout<<"C. "<<odpC[i]<<endl;
            cout<<"D. "<<odpD[i]<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"E. Ko³o ratunkowe"<<endl;
            cout<<"F. Koñczê gre"<<endl;
            cout<<"----------------------------------------------------------------------------------------"<<endl;
            do{

                cout<<"Twoja odpowiedz: ";
                cin>>odpowiedz;
                cout<<"Jesteœ pewny swojej odpowiedzi? (t/n)";
                cin>>potw;
                transform(odpowiedz.begin(), odpowiedz.end(), odpowiedz.begin(), ::tolower); //zamienia duze litery na male

            }
            while (potw!="t"); // jesli odpowie twierdzaco przechodzi dalej
            system("cls"); // czysci ekran

            if (odpowiedz==poprawna[i])
            {
                cout<<"----------------------------------------------------------------------------------------"<<endl;
                cout<<"Dobrze! Wygrywasz!"<<punkty[i]<<" z³"<<endl;
                cout<<"----------------------------------------------------------------------------------------"<<endl<<endl;

            }
            else if (odpowiedz=="e")
            {
                cout<<"Wybra³eœ kolo ratunkowe"<<endl;
            }
            else if (odpowiedz=="f")
            {
                cout<<"----------------------------------------------------------------------------------------"<<endl;
                cout<<"Gratuluje zakoñczy³eœ gre z wygran¹ "<<punkty[i]<<" z³."<<endl;
                cout<<"----------------------------------------------------------------------------------------"<<endl;
                throw;
            }
            else{
                {
                cout<<"----------------------------------------------------------------------------------------"<<endl;
                cout<<"Zle! Poprawna odpowiedz: "<<poprawna[i]<<endl;
                cout<<"Koniec gry. Wygraleœ: "<<gwa_punkty[i]<<" z³"<<endl;
                cout<<"----------------------------------------------------------------------------------------"<<endl;
                throw;
                }
            }
        }
//pytanie1::~pytanie()
