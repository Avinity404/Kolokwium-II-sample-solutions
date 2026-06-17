// Napisz szablon funkcji średnia, która przyjmuje dwa argumenty:
// - wskaźnik do tablicy dowolnego typu liczbowego
// - liczbę elementów w tej tablicy.
// Funkcja ma obliczać i zwracać średnią arytmetyczną elementów jako wartość typu double.
// Jeśli tablica jest pusta (rozmiar równy 0), funkcja powinna zwracać 0.0.

#include <iostream>

template<typename T>
double srednia(T* tablica, size_t rozmiar)
{
    if (rozmiar == 0)
    {
        return 0.0;
    }

    double suma = 0;

    for (size_t i = 0; i < rozmiar; i++)
    {
        suma += tablica[i];
    }

    return (suma / rozmiar);
}


int main()
{
    float tab_1[] = {2.2, 2.3, 2.6, 2.2, 2.1};
    int tab_2[] = {67, 2137, 41, 911, 69};
    
    std::cout << srednia<float>(tab_1, (sizeof(tab_1)/sizeof(tab_1[0])) ) << '\n';
    
    std::cout << srednia(tab_2, (sizeof(tab_2)/sizeof(tab_2[0])) ) << '\n';

    return 0;
}