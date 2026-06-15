// Napisz własną klasę wyjątków, która ma dziedziczyć z std::exception. W konstruktorze, oprócz napisu wyjątek powinien dostawać i zapamiętywać liczbe calkowita. Napis i liczba powinny być prywatne, napis ma być zwracany przez metodę what() (tak jak to jest w standardowych wyjątkach), a liczbe calkowita przez inną metodę.

#include <iostream>

class myException : public std::exception
{
private:
    std::string napis;
    int liczba;

public:
    myException(std::string s, int n) : napis(s), liczba(n) {}
    
    const char* what() const noexcept override
    {
        return napis.c_str();
    }

    int innaMetoda() const
    {
        return liczba;
    }
};




int main()
{
    try
    {
        throw(myException("exception", 67));
    }
    catch(const myException &e)
    {
        std::cout << e.what() << " " << e.innaMetoda() << '\n';
    }

    return 0;
}