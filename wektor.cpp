#include <bits/stdc++.h>
using namespace std;

struct osoba
{
    string imie, nazwisko;
    int wiek;
};

bool comp(osoba a, osoba b)
{
    return a.wiek < b.wiek;
}

class populacja
{
    fstream plik;
    vector <osoba> tablica;
    public:
        populacja()
        {
            plik.open("a.txt", ios::in);
            if(plik.good())
            {
                while(!plik.eof())
                {
                    string a, b;
                    int c;
                    plik >> a >> b >> c;
                    if(a != "" && b != "")
                        tablica.push_back({a, b, c});
                }
            }
        }
        ~populacja()
        {
            plik.close();
        }
        void sortuj()
        {
            sort(tablica.begin(), tablica.end(), comp);
        }
        void wypiszJSON()
        {
            char x = '#'-1;
            if(tablica.size() > 0)
            {
                cout << "[\n";
                for(int i = 0; i < tablica.size(); i++)
                {

                    cout << " {\n";
                    cout << "  " << x << "title" << x << ": " << x << tablica[i].imie << " " << tablica[i].nazwisko << x << ",\n";
                    cout << "  " << x << "subtitle" << x << ": " << tablica[i].wiek << "\n";
                    cout << " }";
                    if(i+1 < tablica.size())
                        cout << ",";
                    cout << "\n";
                }
                cout << "]";
            }
        }
};

int main() {
    cout << "Content-Type:application/json;charset=UTF-8" << (char)13 << (char)10;

    populacja P;
    P.sortuj();
    P.wypiszJSON();

    return 0;
}
