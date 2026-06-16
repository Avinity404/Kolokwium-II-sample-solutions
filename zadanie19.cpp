// Napisz interfejs (klasę Figura) zawierający metodę pole() zwracającą liczbę rzeczywistą typu double. Następnie zdefiniuj klasy Koło i Kwadrat, które posiadają mają dziedziczenie Figura. Jako wartość stałej pi należy przyjąć 3.14

// Napisz funkcję figury(), która nie ma parametrów i nic nie zwraca. W funkcji:
// - utwórz tablicę (w postaci vector) inteligentnych, unikalnych wskaźników na klasę Figura.
// - dodaj do tablicy kwadrat o boku 4 a następnie koło o promieniu 3
// - wypisz (po jednym w linii) pola obu figur przechodząc w pętli po tablicy figur

#include <iostream>
#include <vector>
#include <memory>

#define PI 3.14

class Figura
{
public:
    virtual double pole() const = 0;
    virtual ~Figura() = default;
};

class Kolo : public Figura
{
private:
    double r;

public:
    Kolo(double promien) : r(promien) {}
    ~Kolo() override {};

    double pole() const override
    {
        return PI * r * r;
    }
};

class Kwadrat : public Figura
{
private:
    double a;

public:
    Kwadrat(double bok) : a(bok) {}
    ~Kwadrat() override {};

    double pole() const override
    {
        return a * a;
    }
};



void figury()
{
    std::vector<std::unique_ptr<Figura>> zbior;

    zbior.push_back(std::make_unique<Kwadrat>(4.0));
    zbior.push_back(std::make_unique<Kolo>(3.0));

    for (const auto &elem : zbior)
    {
        std::cout << elem->pole() << '\n';
    }
}


int main()
{
    figury();
    return 0;
}
