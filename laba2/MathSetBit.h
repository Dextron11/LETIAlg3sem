//
// Created by andresold on 12.10.17.
//

#ifndef LABALGK2_MATHSETBIT_H
#define LABALGK2_MATHSETBIT_H

#include <iostream>
#include <vector>

class MathSetBit {
private:
    char name;//имя множества;
    std::vector<int> set_container;//множество
    MathSetBit();//конструктор
public:

    MathSetBit(char name);//конструктор по умолчанию

    MathSetBit(char name, const std::vector<int> &set);

    friend std::ostream &operator<<(std::ostream &os, const MathSetBit &bit);

    MathSetBit operator|(const MathSetBit &rhs) const;//Логическое "Или"

    MathSetBit operator&(const MathSetBit &rhs) const;//Логическое "И"

    MathSetBit operator~() const;//Логическое отрицание

    char getName() const;

    const std::vector<int> &getSet_container() const;

    void setSet(const std::vector<int> &set_container);

};


#endif //LABALGK2_MATHSETBIT_H
