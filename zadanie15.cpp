// Napisz szablon klasy Stos implementującej stos na prywatnej 100-elementowej tablicy tab. Oprócz tablicy potrzebna będzie zmienna wskazująca wierzchołek stosu.
// W klasie należy zaimplementować:
// - metodę push() wstawiajaca na stos,
// - metodę pop() pobierająca ze stosu(i zwracająca tę wartość) oraz
// - metodę is_empty() zwracająca true jeśli stos jest pusty.

#include <iostream>

template<typename T>
class Stos
{
private:
    T tab[5];
    int wierzcholek;

public:
    Stos() : wierzcholek(-1) {}

    void push(T elem)
    {
        if (wierzcholek < 4)
        {
            tab[++wierzcholek] = elem;
        }
    }

    T pop()
    {
        if (!is_empty())
        {
            return tab[wierzcholek--];
        }

        // tego moze nawet nie byc, jesli kompilator pusci
        throw std::runtime_error("Stos jest pusty!");
    }

    bool is_empty() const
    {
        return (wierzcholek == -1);
    }
};


int main()
{
    Stos<int> stosik;

    stosik.push(1);
    stosik.push(2);
    stosik.push(3);
    stosik.push(4);
    stosik.push(5);
    stosik.push(9);

    while(!stosik.is_empty())
    {
        std::cout << stosik.pop() << " ";
    }
    std::cout << '\n';


    Stos<char> styrta;

    styrta.push('a');
    styrta.push('b');

    std::cout << styrta.pop() << '\n';


    return 0;
}
