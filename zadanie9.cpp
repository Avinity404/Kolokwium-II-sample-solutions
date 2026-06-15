// Dopisz konstruktor przenoszący tej klasy. UWAGA: Klasa jest już napisana, zawiera deklarację konstruktora przenoszącego, brakuje tylko definicji tego konstruktora i tu należy ją napisać. proszę zaimplementować metodę get_vector() zwracającą tablicę tab. 

#include <iostream>
#include <initializer_list>

class Tablica
{
private:
    int *tab;
    int size;

public:
    Tablica(const std::initializer_list<int>& lista)
    {
        tab = new int[lista.size()];
        size = lista.size();

        int i = 0;

        for(auto el: lista)
        {
            tab[i++] = el;
        }
   }

   int* get_vector()
   {
        return tab;
   }

   Tablica(Tablica&& src)
   {
        size = src.size;
        tab = src.get_vector();

        src.tab = nullptr;
        src.size = 0;
   }


   // dodatek
   ~Tablica()
    {
        delete[] tab;
    }
};

int main()
{
    Tablica t1{1,2,3,4,5};

    // sprawdzenie
    
    std::cout << t1.get_vector() << '\n';

    Tablica t2 = std::move(t1);

    std::cout << t1.get_vector() << '\n';
    std::cout << t2.get_vector() << '\n';

    return 0;
}