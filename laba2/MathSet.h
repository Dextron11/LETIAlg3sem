//
// Created by andresold on 10.10.17.
//
#ifndef LABALGK2_MATHSET_H
#define LABALGK2_MATHSET_H
#include <iostream>
#include <string>

class MathSet {
private:
    char name;//имя множества;

    std::string set_container;//множество

    MathSet();//конструктор по умолчанию
public:
    MathSet(char name);

    MathSet(char name, const std::string &set);

    friend std::ostream &operator<<(std::ostream &os, const MathSet &set);// вывод

    MathSet operator|(const MathSet &rhs) const;//Логическое "Или"

    MathSet operator&(const MathSet &rhs) const;//Логическое "И"

    MathSet operator~() const;//Логическое отрицание

    char getName() const;

    const std::string &getSet_container() const;

    void setSet(const std::string &set);

};


#endif //LABALGK2_MATHSET_H
