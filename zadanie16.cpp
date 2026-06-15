// Stwórz klasę Zwierze posiadającą metodę wypisz() wypisującą komunikat "Jestem zwierzęciem".
// Następnie stwórz dwie klasy: Ssak i Ryba dziedziczące z Zwierze. Klasa Ssak niech posiada metodę wypisz() wypisującą komunikat "Ssę" a klasa Ryba metodę wypisz() wypisującą komunikat "Pływam".
// Jako czwartą stwórz klasę Delfin dziedziczącą po klasach Ssak i Ryba. Ta klasa nie ma posiadać "własnej" metody wypisz, jedynie dziedziczy ją po 'przodkach'.
// Na koniec napisz funkcję zwierzak(), w której utwórz obiekt klasy Delfin i za jego pomocą, używając jedynie metod wypisz() spowoduje wypisanie komunikatów (każdy w osobnej linii): "Ssę", "Pływam", "Jestem zwierzęciem".

#include <iostream>

class Zwierze
{
public:
    void wypisz()
    {
        std::cout << "Jestem zwierzeciem";
    }
};

class Ssak : public virtual Zwierze
{
public:
    void wypisz()
    {
        std::cout << "Sse";
    }
};

class Ryba : public virtual Zwierze
{
public:
    void wypisz()
    {
        std::cout << "Plywam";
    }
};

class Delfin : public Ssak, public Ryba {};

void zwierzak()
{
    Delfin delf;

    delf.Ssak::wypisz();
    std::cout << '\n';

    delf.Ryba::wypisz();
    std::cout << '\n';

    delf.Zwierze::wypisz();
    std::cout << '\n';
}

int main()
{
    zwierzak();

    return 0;
}