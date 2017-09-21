#include <iostream>
#include <cstring>
//**********************************************************************************************************************
struct Set //односвязный список
{
    char el;
    Set *next;

    Set(char s, Set *n = nullptr) ://Конструктор
            el(s), next(n) {};
};
const int U = 27;//универсум для прописных букв анг. языка + 1 для \0
char Universum[] = "abcdefghijklmnopqrstuvwxyz";//допустимые значения множества
const int numExe = 1000000;//количесвто выполнений
#include "output.h" //Функции вывода
#include "arr.h"//Функции для работы с массивом char
#include "list.h"// Функции для работы с односвязным списком
#include "arrBitAndComWord.h"//функции для работы с массивом битов и машинным словом
#include "input.h"//Функции ввода

//**********************************************************************************************************************
int main() {
    char A[U] = {'\0'}, B[U] = {'\0'}, C[U] = {'\0'}, D[U] = {'\0'};
    int point=1;
    while (point) {
        point=1;
        menu1();
        inputArr(A,B,C,D);
        while (point!=5) {
            menu2();
            std::cin >> point;
            switch (point) {
                case 1: {

                    wayArr(A,B,C,D);
                    break;
                }
                case 2: {
                    wayList(A,B,C,D);
                    break;
                }
                case 3: {
                   wayArrBit(A,B,C,D);
                    break;
                }
                case 4: {
                  wayComWord(A,B,C,D);
                    break;
                }
                case 5 :
                    break;
                default:
                    std::cout << "Ошибка!" << std::endl;
                    break;
            }
        }
    }
    return 0;
}
