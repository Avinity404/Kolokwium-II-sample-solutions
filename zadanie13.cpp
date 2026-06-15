// Napisz funkcję, która otrzymuje dwa vectory liczb typu double I zwraca vector wyników dzielenia liczb z pierwszego wektora przez liczby z drugiego. Jeśli miałoby nastąpić dzielenie przez zero, funkcja ma rzucić wyjątek typu zdefiniowanego powyżej Z komunikatem "dzielenie przez zero" oraz z indeksem pozycji na której to zero wystąpiło.
// Napisz druga funkcje ma nazywać się serwis i ma mieć takie same parametry jak pierwsza, ale nie ma nic zwracać. Ma wywołać pierwsza funkcje I wypisać jej wynik oraz obsłużyć rzucony wyjątek. Obsługa wyjątku ma polegać na wypisaniu komunikatu Z obiektu wyjątku oraz pozycji na której wystąpiło zero (wszystko w tej samej linii).


#include <iostream>
#include <vector>
#include <string>

class dzielenieZero : public std::exception
{
private:
    std::string komunikat;
    size_t idx;

public:
    dzielenieZero(std::string s, size_t i) : komunikat(s), idx(i) {}

    const char* what() const noexcept override
    {
        return komunikat.c_str();
    }

    size_t get_idx() const noexcept
    {
        return idx;
    }

};

std::vector<double> dzielenieWectorow(const std::vector<double>& first, const std::vector<double>& second)
{
    std::vector<double> odp(first.size());

    for (size_t i = 0; i < first.size(); i++)
    {
        if (second[i] == 0) throw dzielenieZero("dzielenie przez zero", i);

        odp[i] = first[i] / second[i];
    }

    return odp;

}

void serwis(std::vector<double> &first, std::vector<double> &second)
{
    try
    {
        std::vector<double> odp = dzielenieWectorow(first, second);

        for (const auto &elem : odp)
        {
            std::cout << elem << " ";
        }
        std::cout << '\n';

    }
    catch(const dzielenieZero &e)
    {
        std::cout << e.what() << " " << e.get_idx() << '\n';
    }
}


int main()
{
    std::vector<double> vec_1{2, 4, 8, 10, 16};
    std::vector<double> vec_2{1, 2, 4, 5, 8};
    std::vector<double> vec_3{2, 0, 8, 10, 8};

    serwis(vec_1, vec_2);

    serwis(vec_1, vec_3);

    return 0;
}