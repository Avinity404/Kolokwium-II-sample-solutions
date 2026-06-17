// Napisz funkcję suma_wektorow, która przyjmuje dwa wektory typu double i zwraca nowy wektor, zawierający sumy odpowiadających sobie elementów.
// Jeżeli wektory mają różne rozmiary, funkcja powinna rzucać wyjątek typu std::runtime_error z odpowiednim komunikatem.
// Następnie napisz funkcję serwis, która przyjmuje jeden wektor typu double i nie zwraca żadnej wartości. Funkcja ta powinna próbować wywołać suma_wektorow z tym samym wektorem jako oba argumenty, a w przypadku wystąpienia wyjątku powinna go obsłużyć, wypisując komunikat błędu na standardowe wyjście.

#include <iostream>
#include <vector>
#include <stdexcept>

std::vector<double> suma_wektorow(const std::vector<double>& first, const std::vector<double>& second)
{
    if (first.size() != second.size())
    {
        throw std::runtime_error("Wektory roznych rozmiarow");
    }

    std::vector<double> odp(first.size());

    for (size_t i = 0; i < first.size(); i++)
    {
        odp[i] = first[i] + second[i];
    }

    return odp;
}

void serwis(const std::vector<double>& vec)
{
    try
    {
        std::vector<double> odp = suma_wektorow(vec, vec);

        for (const auto& elem : odp)
        {
            std::cout << elem << " ";
        }
        std::cout << '\n';
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << '\n';
    }
    
}


int main()
{
    std::vector<double> vec_1{1.0, 2.0, 3.0, 9.0};
    std::vector<double> vec_2{7.0, 4.4, 1.17};

    serwis(vec_1);


    try
    {
        std::vector<double> test = suma_wektorow(vec_1, vec_2);
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}