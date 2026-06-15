// Stwórz klasę Transport posiadającą metodę wypisz() wypisującą komunikat "Jestem środkiem transportu". Następnie stwórz dwie klasy: Samochód i Statek dziedziczące z Transport. Klasa Samochód niech posiada metodę wypisz() wypisującą komunikat "Jestem samochodem" , a klasa Statek metodę wypisz() wypisującą komunikat "Jestem statkiem". Jako czwartą stwórz klasę Amfibia dziedziczącą po klasach Samochód i Statek. Ta klasa nie ma posiadać "własnej" metody wypisz, jedynie dziedziczy ją po 'przodkach'. Na koniec napisz funkcję transport(), w której utwórz obiekt klasy Amfibia i za jego pomocą, używając jedynie metod wypisz() spowoduj wypisanie komunikatów (każdy w osobnej linii): "Jestem samochodem", "Jestem statkiem", "Jestem środkiem transportu".


#include <iostream>

class Transport
{
public:
    void wypisz()
    {
        std::cout << "Jestem srodkiem transportu\n";
    }
};


class Samochod : public virtual Transport
{
public:
    void wypisz() 
    {
        std::cout << "Jestem samochodem\n";
    }
};

class Statek : public virtual Transport
{
public:
    void wypisz() 
    {
        std::cout << "Jestem statkiem\n";
    }
};

class Amfibia : public Samochod, public Statek {};

void transport()
{
    Amfibia amf;

    amf.Transport::wypisz();
    amf.Samochod::wypisz();
    amf.Statek::wypisz();
}

int main()
{
    transport();

    return 0;
}