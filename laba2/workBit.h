
#include <vector>

namespace {

    const std::string Universum = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::vector<int> inputStr(char name) {
        std::vector<int> res(Universum.size(),0);
        std::cout << "Введите множество " << name << ": ";
        std::string input;
        std::cin >> input;
        for (int i = 0; i <Universum.size(); i++) {
            if ((input.find(Universum[i])) != std::string::npos) {
                res[i] = 1;
            }
        }
        return res;
    }

    std::vector<int> randStr() {
        std::vector<int> res(Universum.size(),0);
        for (int i = 0; i < Universum.size(); i++)
            if (rand() % 2) {
                res[i] = 1;
            }
        return res;
    }

}