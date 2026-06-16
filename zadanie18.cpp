// Napisz szablon funkcji o nazwie maksimum, znajdującej największa wartość w tablicy. Funkcja otrzymuje tablice w postaci wskaźnika oraz jej rozmiar i zwraca znalezioną wartość

#include <iostream>

template<typename T>
T maksimum(T *tablica, size_t rozmiar)
{
    T max = tablica[0];

    for (size_t i = 1; i < rozmiar; i++)
    {
        if (tablica[i] > max)
        {
            max = tablica[i];
        }
    }

    return max;
}

int main()
{
    int tab[] = {4,1,7,6,4,1,8};

    std::cout << maksimum<int>(tab, 7) << '\n';

    char tab2[] = {'x', 'a', 'f', 'c'};

    std::cout << maksimum<char>(tab2, 4) << '\n';

    return 0;
}
