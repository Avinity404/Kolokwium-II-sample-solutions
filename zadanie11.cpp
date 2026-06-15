// Napisz funkcję, która otrzymuje vector liczb typu double i zwraca vector pierwiastków tych liczb. Jeśli miałoby nastąpić liczenie pierwiastka z liczby ujemnej funkcja ma rzucić wyjątek typu zdefiniowanego powyżej z komunikatem "Pierwiastek z wartości ujemnej" oraz z indeksem pozycji na której ta wartość wystąpiła.

//Napisz drugą funkcję, która ma nazywać się serwis i ma mieć taki sam parametr jak pierwsza, ale nie ma nic zwracać. Ma wywołać pierwszą funkcję i wypisać jej wynik oraz obsłużyć rzucony wyjątek. Obsługa wyjątku ma polegać na wypisaniu komunikatu z obiektu wyjątku oraz pozycji na której wystąpiła wartość ujemna (wszystko w tej samej linii).

#include <iostream>
#include <vector>
#include <cmath>

class pierwiastekZero : public std::exception
{
private:
    std::string komunikat;
    size_t idx;

public:
    pierwiastekZero(std::string kom, size_t i) : komunikat(kom), idx(i) {}

    const char* what() const noexcept override
    {
        return komunikat.c_str();
    }

    size_t get_idx() const noexcept
    {
        return idx;
    }
};

std::vector<double> liczPierwiastki(std::vector<double> vec)
{
    std::vector<double> res(vec.size());

    for (size_t i = 0; i < vec.size(); i++)
    {
        if (vec.at(i) < 0) throw pierwiastekZero("Pierwiastek z wartosci ujemnej", i);
        
        res[i] = sqrt(vec[i]);
    }

    return res;
}

void serwis(std::vector<double> &vec)
{
    try
    {
        std::vector<double> odp = liczPierwiastki(vec);

        for (const auto &elem : odp)
        {
            std::cout << elem << " ";
        }
        std::cout << '\n';
    }
    catch(const pierwiastekZero& e)
    {
        std::cout << e.what() << " " << e.get_idx() << '\n';
    }
    
    
}

int main()
{
    std::vector<double> vec {4, 64, 13.6, 9.01, -121};

    serwis(vec);

    return 0;
}