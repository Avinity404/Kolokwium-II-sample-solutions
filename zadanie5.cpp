// Napisz dwie funkcje.
// Pierwsza niech dostaje dwie liczby typu double i zwraca wynik dzielenia drugiej przez pierwszą.
// Jeśli pierwsza liczba wynosi zero, funkcja ma rzucić wyjątek std::runtime_error z komunikatem "Dzielenie przez zero".
// Druga funkcja ma nazywać się serwis i ma mieć takie same parametry jak pierwsza, ale nie ma nic zwracać.
// Ma wywołać pierwszą funkcję i wypisać jej wynik oraz obsłużyć rzucony wyjątek. Obsługa wyjątku ma polegać na wypisaniu komunikatu z obiektu wyjątku.

#include <iostream>
#include <stdexcept>

double dzielenie(double a, double b)
{
    if (b == 0)
    {
        throw std::runtime_error("Dzielenie przez zero");
    }

    return a / b;
}

void serwis(double a, double b)
{
    try
    {
        std::cout << dzielenie(a, b) << '\n';
    }
    catch(std::runtime_error& e)
    {
        std::cout << e.what() << '\n';
    }
}

int main()
{
    serwis(5.0, 2.5);
    serwis(69.67, 0);
    serwis(12.0, 37.0);

    return 0;
}