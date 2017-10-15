//
// Created by andresold on 10.10.17.
//

#include "MathSetList.h"
#include "workList.h"

MathSetList::MathSetList() {}

MathSetList::MathSetList(char name) : name(name) {}

MathSetList MathSetList::operator|(const MathSetList &rhs) const {
    MathSetList res;
    std::list<char>z;
    res.set_container = set_container;
    z=rhs.set_container;
    res.set_container.merge(z);//Объединение двух списков
    res.set_container.sort();//сортировка
    res.set_container.unique();//удаление повторяющихся рядом
    return res;
}

MathSetList MathSetList::operator&(const MathSetList &rhs) const {
    MathSetList C;
    for (auto fromSet:set_container) {
        for (auto fromRhs:rhs.set_container)
            if (fromSet == fromRhs) {
                C.set_container.push_back(fromSet);
                break;
            }
    }
    return (C);
}

MathSetList MathSetList::operator~() const {

    MathSetList A;
    for (auto fromUniversum:Universum) {
        bool check = true;
        for (auto fromSet:set_container) {
            if (fromSet == fromUniversum) {
                check = false;
                break;
            }
        }
        if (check)
            A.set_container.push_back(fromUniversum);
    }
    return (A);
}



std::ostream &operator<<(std::ostream &os, const MathSetList &list) {
    for(auto out:list.set_container)
    {
      os<<out;
    }
    return os;
}

char MathSetList::getName() const {
    return name;
}

void MathSetList::setSet(const std::list<char> &set) {
    MathSetList::set_container = set;
}

MathSetList::MathSetList(char name, const std::list<char> &set_container) : name(name), set_container(set_container) {}

const std::list<char> &MathSetList::getSet_container() const {
    return set_container;
}



