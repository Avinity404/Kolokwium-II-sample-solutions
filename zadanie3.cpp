//  Dana jest klasa Auto. Obiekty klasy Auto posiadają trzy publiczne pola typu string: marka, model i kolor.
// Napisz funkcję szukaj_auta() z trzema parametrami:
// - pierwszym jest vector obiektów klasy Auto,
// - drugim string
// - trzecim wskaźnik na pole składowe typu string klasy Auto.
// Funkcja ma wyszukać w wektorze pierwsze wystąpienie obiektu, który we wskazywanym polu zawiera podany string. Funkcja ma zwracać indeks znalezionego obiektu.


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


size_t szukaj_auta (std::vector<Auto> vec, std::string szukana, std::string Auto::* pole)
{
    size_t idx = 0;

    for (const auto& elem : vec)
    {
        if (elem.*pole == szukana)
        {
            return idx;
        }
        idx++;
    }

    // w poleceniu nie ma sprecyzowanej obslugi przypadku,
    // gdy nie znajdziemy elementu
    return idx;
}


int main()
{
    Auto a1{"Toyota", "Corolla", "czerwony"};
    Auto a2{"BMW", "M3", "rozowy"};

    std::vector<Auto> vec{a1, a2};

    std::cout << szukaj_auta(vec, "BMW", &Auto::marka) << '\n';
    std::cout << szukaj_auta(vec, "Corolla", &Auto::model) << '\n';
    std::cout << szukaj_auta(vec, "rozowy", &Auto::kolor) << '\n';
}