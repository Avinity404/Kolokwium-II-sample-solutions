// Stwórz klasę Temperatura, która będzie posiadała pole prywatne stopnie typu double do przechowywania temperatury w skali Kelvina.
// W klasie stwórz konstruktor, który otrzymuje wartość double traktując jako temperatura w skali Celsjusza i konwertuje ją do Kelvinów zapisując po konwersji w prywatnym polu stopnie.
// Dodaj do klasy operator double, konwertujący obiekt Temperatura na wartość double będącą wartością temperatury w Celsjuszach.
// Dla przypomnienia: 0 K = -273,15ºC.
// Dla celów testowych dodaj do klasy metodę print, która wypisze na ekran wartość pola stopnie (samą wartość, bez żadnych dodatkowych tekstów).

#include <iostream>

class Temperatura
{
private:
    double stopnie;

public:
    Temperatura(double stopnieC)
    {
        stopnie = stopnieC + 273.15;
    }

    operator double() const
    {
        return stopnie - 273.15;
    }

    void print() const
    {
        std::cout << stopnie;
    }
};


int main()
{
    Temperatura t(100.0);
    t.print();
    std::cout << '\n';

    double c = t;
    std::cout << c << '\n';
}