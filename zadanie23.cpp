// Dana jest klasa Auto, której obiekty posiadają trzy publiczne pola typu std::string:
// marka, model oraz kolor.
// Napisz funkcję znajdz_pole, która przyjmuje trzy argumenty:
// – std::vector<Auto*>, czyli wektor wskaźników na obiekty klasy Auto,
// – std::string, reprezentujący wartość, której należy szukać,
// – wskaźnik do pola klasy Auto typu std::string (np. &Auto::model).
// Funkcja ma przeszukać pola wskazywanych obiektów i zwrócić wskaźnik do pola std::string, które zawiera zadaną wartość. Jeżeli żaden obiekt nie zawiera takiej wartości w podanym polu, funkcja powinna zwrócić nullptr.

#include <iostream>
#include <string>
#include <vector>

// klasa ktora jest dana
class Auto
{
public:
    std::string marka;
    std::string model;
    std::string kolor;
};

std::string Auto::* znajdz_pole(std::vector<Auto*> vec, std::string szukana, std::string Auto::*pole)
{
    for (const auto& samochod : vec)
    {
        if (samochod->*pole == szukana)
        {
            return pole;
        }
    }

    return nullptr;
}


int main()
{
    Auto a1{"Toyota", "Corolla", "czerwony"};
    Auto a2{"BMW", "M3", "rozowy"};

    std::vector<Auto*> vec{&a1, &a2};

    auto wynik = znajdz_pole(vec, "Toyota", &Auto::marka);

    if (wynik)
    {
        std::cout << wynik;
    }

    return 0;
}