// Napisz własną klasę wyjątków, która ma dziedziczyć z std::exception. W konstruktorze, oprócz napisu wyjątek powinien dostawać i zapamiętywać liczbę całkowitą. Napis i liczba powinny być prywatne, napis ma być zwracany przez metodę what() (tak jak to jest w standardowych wyjątkach), a liczbę całkowitą przez inną metodę. 

#include <iostream>

class myException : public std::exception
{
private:
    std::string napis;
    int liczba;

public: 
    myException(std::string s, int l) : napis(s), liczba(l) {}

    const char* what() const noexcept override 
    {
        return napis.c_str();
    }

    int get_num() const noexcept
    {
        return liczba;
    }
};


int main()
{

    return 0;
}