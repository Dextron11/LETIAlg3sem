
#include <list>

namespace {

    const std::string Universum = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::list<char> inputStr(char name) {
        std::list<char> res;
        char temp;
        std::cout << "Введите множество " << name << ": ";
        do {
            temp = std::cin.get();//посимволный вывод
            if ((isprint(temp) && isupper(temp)))
                res.push_back(temp);
        } while (temp != '\n');
        res.sort();//сортировка
        res.unique();//удаление повторяющихся рядом
        return res;
    }

    std::list<char> randStr() {
       std::list<char> res;
        for (auto in:Universum)
            if (rand() % 2) {
                res.push_back(in);
            }

        return res;
    }

    void outputSet(MathSetList out) {
        std::cout << "Множество " << out.getName() << ": " << out << '\n';

    }

}