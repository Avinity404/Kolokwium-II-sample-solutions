// Napisz szablon klasy Stos implementującej stos na prywatnej tablicy tab typu vector. W klasie wystarczy zaimplementować metodę push() wstawiającą na stos. 

#include <iostream>
#include <vector>

template<typename T>
class Stos
{
private:
    std::vector<T> tab;

public:
    void push(T element)
    {
        tab.push_back(element);
    }
};

int main()
{
    Stos<int> stosik;

    stosik.push(0);
    stosik.push(21);
    stosik.push(37);

    return 0;
}