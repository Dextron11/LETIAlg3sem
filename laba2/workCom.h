
#include <vector>

namespace {

    const std::string Universum = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int inputStr(char name) {
        int res=0;
        std::cout << "Введите множество " << name << ": ";
        std::string input;
        std::cin >> input;
        int i = 0;
        for (auto fromUniversum:Universum) {
            for (auto fromInput:input) {
                if (fromUniversum == fromInput) {
                    res += 1 << i;
                    break;
                }
            }
            i++;
        }

        return res;
    }

    int randStr() {
        int res=0;
        for (int i = 0; i < Universum.size(); i++) {
            if(rand() % 2)
                res+=1<<i;
        }
        return res;
    }

}