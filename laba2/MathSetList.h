//
// Created by andresold on 10.10.17.
//

#ifndef LABALGK2_MATHSETLIST_H
#define LABALGK2_MATHSETLIST_H


#include <iostream>
#include <list>

class MathSetList {
private:
    char name;//имя множества

    std::list<char> set_container;//множество

    MathSetList();//конструктор по умолчанию
public:
    MathSetList(char name);//конструктор

    MathSetList(char name, const std::list<char> &set_container);

    MathSetList operator|(const MathSetList &rhs) const;//Логическое "Или"

    friend std::ostream &operator<<(std::ostream &os, const MathSetList &list);

    MathSetList operator&(const MathSetList &rhs) const;//Логическое "И"

    MathSetList operator~() const;//Логическое отрицание

    char getName() const;

    const std::list<char> &getSet_container() const;

    void setSet(const std::list<char> &set_container);
};


#endif //LABALGK2_MATHSETLIST_H
