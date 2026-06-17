// Utwórz klasę Osoba, która posiada prywatne pola string imie oraz string nazwisko, konstruktor przyjmujący oba te pola oraz publiczną metodę wypisz(), która wypisuje dane osoby.
// Następnie utwórz klasę Pracownik, dziedziczącą po klasie Osoba, która dodatkowo zawiera prywatne pole string stanowisko, konstruktor przyjmujący imię, nazwisko i stanowisko, a także nadpisaną metodę wypisz(), która wypisuje wszystkie dane, łącznie ze stanowiskiem.
// Utwórz funkcję test, która tworzy wektor wskaźników do obiektów klasy Osoba, dodaje do niego obiekty:
// – "Jan", "Kowalski" jako obiekt klasy Osoba,
// – "Jakub", "Nowak", "Dyrektor" jako obiekt klasy Pracownik,
// Następnie w pętli wywołuje metodę wypisz() dla każdego elementu wektora. Pamiętaj o zwolnieniu zaalokowanych obiektów.

#include <iostream>
#include <string>
#include <vector>

class Osoba
{
private:
    std::string imie;
    std::string nazwisko;

public:
    Osoba(std::string im, std::string nazw) : imie(im), nazwisko(nazw) {}

    virtual void wypisz() const
    {
        std::cout << imie << " " << nazwisko << " ";
    }

    virtual ~Osoba() {}
};

class Pracownik : public Osoba
{
private:
    std::string stanowisko;

public:
    Pracownik(std::string im, std::string nazw, std::string stan)
    : Osoba(im, nazw), stanowisko(stan) {}

    void wypisz() const override
    {
        Osoba::wypisz();
        std::cout << stanowisko;
    }

};


void test()
{
    std::vector<Osoba*> vec;

    vec.push_back(new Osoba("Jan", "Kowalski"));
    vec.push_back(new Pracownik("Jakub", "Nowak", "Dyrektor"));

    for (const auto& osoba : vec)
    {
        osoba->wypisz();
        std::cout << '\n';
    }

    delete vec[0];
    delete vec[1];
}

int main()
{
    test();

    return 0;
}