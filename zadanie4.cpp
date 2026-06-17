// Dane są klasy Koło i Kwadrat, które posiadają publiczną metodę pole() zwracającą pole danej figury jako liczba rzeczywista typu double (klasy są już zdefiniowane łącznie z metodami pole).
// Zadaniem jest napisanie klasy Figura (będącej interfejsem), z której dziedziczą klasy Koło i Kwadrat.
// Klasa ma posiadać czysto abstrakcyjną metodę pole(), która jest nadpisywana w klasach pochodnych

class Figura
{
public:
    virtual double pole() const = 0;
    virtual ~Figura() {}
};