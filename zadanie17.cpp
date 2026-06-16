//Dana jest klasa Książka. Obiekty klasy Książka posiadają trzy publiczne pola typu string: autor, tytuł, wydawca. 
// Napisz funkcję szukaj() z trzema parametrami: pierwszym jest vector obiektów klasy Książka,  drugim string, a trzecim wskaźnik na pole składowe Książka.
// Funkcja ma wyszukać w tablicy pierwsze wystąpienie obiektu, który we wskazanym polu zawiera podany string. Funkcja ma zwracać indeks znalezionego obiektu.
// Klasa Książka jest już napisana, nie trzeba jej definiować.

#include <iostream>
#include <vector>

class Ksiazka
{
public: 
    std::string autor;
    std::string tytul;
    std::string wydawca;

    Ksiazka(std::string a, std::string t, std::string w)
        : autor(a), tytul(t), wydawca(w) {}
};

int szukaj(std::vector<Ksiazka> vec, std::string szukana, std:: string Ksiazka::*wsk)
{
    int idx = 0;
    for (const auto &elem : vec)
    {
        if (elem.*wsk == szukana)
        {
            return idx;
        }
        idx++;
    }

    // jak nieznajdzie
    return -1;
}

int main()
{
    std::vector<Ksiazka> baza;

    baza.push_back(Ksiazka("Mick", "dziady I", "warszawa"));
    baza.push_back(Ksiazka("Mick", "dziady II", "warszawa"));
    baza.push_back(Ksiazka("Jan", "dzikus", "krakow"));
    baza.push_back(Ksiazka("Matejko", "mieczem i ananasem", "wroclaw"));

    std::cout << szukaj(baza, "dziady II", &Ksiazka::tytul) << '\n';

    return 0;
}
