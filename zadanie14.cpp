// Dana jest klasa, której niekompletna deklaracja znajduje się poniżej:
// Dodaj do klasy przenoszący operator =
// UWAGA Klasa jest już napisana, zawiera (nie pokazana tu) deklaracje operatora przypisania, brakuje tylko definicji tego operatora i tu należy ją napisać.

#include <iostream>

class Tablica
{
private:
    int *tab_;
    int size_;

public:
    Tablica (const std::initializer_list<int>& lista)
    {
        size_ = lista.size();
        tab_ = new int[size_];
        int i = 0;

        for(auto it=lista.begin(); it!=lista.end(); it++)
        {
            tab_[i++]= *it;
        }
    }

    Tablica& operator=(Tablica&& t)
    {
        if (this == &t) return *this;

        delete[] tab_;

        size_ = t.size_;
        tab_ = t.tab_;

        t.tab_ = nullptr;
        t.size_ = 0;

        return *this;
    }

    // test
    int* get_adres() const
    {
        return tab_;
    }
};


int main()
{
    Tablica t1 {1,2,3,8,5,6};
    Tablica t2 {7,6};

    // sprawdzenie
    
    std::cout << t1.get_adres() << '\n';
    std::cout << t2.get_adres() << '\n';

    t2 = std::move(t1);

    std::cout << '\n';
    std::cout << t1.get_adres() << '\n';
    std::cout << t2.get_adres() << '\n';

    return 0;
}