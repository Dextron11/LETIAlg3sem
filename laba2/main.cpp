#define __option __SET//Выбор способа


#define  __SET 1
#define __LIST 2
#define  __BIT 3
#define  __COM 4

#include <cstring>
#include <iostream>

#if __option == __SET
#include "MathSet.h"
#include "workSet.h"
#endif

#if __option == __LIST
#include "MathSetList.h"
#include "workList.h"
#endif


#if __option == __BIT
#include "MathSetBit.h"
#include <vector>
#include "workBit.h"
#endif


#if __option == __COM
#include "MathSetCom.h"
#include "workCom.h"
#endif

const int numExe = 1;//   количесвто выполнений

void menu1()//меню выбора способа ввода данных
{

    std::cout
            << "\n=========================================================================================================\n";
    std::cout << "Каким способом ввести данные?\n";
    std::cout << "1)Вручную\n";
    std::cout << "2)Рандом\n";
    std::cout << "0)Выход";
    std::cout
            << "\n=========================================================================================================\n";
}


int main() {

    long long t1 = 0, t2 = 0, T;
    int i = 0;
    int pointer = 1;
    while (true) {
        menu1();
    #if __option == __SET
            MathSet A('A'), B('B'), C('C'), D('D'), E('E');
    #endif
    #if __option == __LIST

            MathSetList A('A'),B('B'),C('C'),D('D'),E('E');
    #endif
    #if __option == __BIT
            MathSetBit A('A'),B('B'),C('C'),D('D'),E('E');
    #endif
    #if __option == __COM
            MathSetCom A('A'),B('B'),C('C'),D('D'),E('E');
    #endif
        do {
            std::cin >> pointer;
            switch (pointer) {
                case 1://ввод с консоли
                    # if __option== __LIST
                    std::cin.get();
                    #endif
                    A.setSet(inputStr(A.getName()));
                    B.setSet(inputStr(B.getName()));
                    C.setSet(inputStr(C.getName()));
                    D.setSet(inputStr(D.getName()));
                    break;
                case 2://рандом ввод
                    A.setSet(randStr());
                    B.setSet(randStr());
                    C.setSet(randStr());
                    D.setSet(randStr());
                    break;
                case 0:
                    exit(1);
                default:
                    std::cout << "Ошибка ввода!\nПопоробуйте еще раз: ";
            }
        } while ((pointer > 2) || (pointer < 0));
        i = 0;
        t1 = clock();
        while (i < numExe) {
            E.setSet(((A & (~(B | C | D))).getSet_container()));//обработка множества
            i++;
        }
        t2 = clock();
        std::cout << "Множество " << A.getName() << ": "<<A<<'\n';
        std::cout << "Множество " << B.getName() << ": "<<B<<'\n';
        std::cout << "Множество " << C.getName() << ": "<<C<<'\n';
        std::cout << "Множество " << D.getName() << ": "<<D<<'\n';
        std::cout << "Множество " << E.getName() << ": "<<E<<'\n';

        T = t2 - t1;
        std::cout << "\nВремя выполнения " << T << " тиков, выполнено " << numExe << " раз\n";
    }
    return 0;
}