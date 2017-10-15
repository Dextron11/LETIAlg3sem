//
// Created by andresold on 10.10.17.
//

#include <cstring>
#include "MathSet.h"
#include "workSet.h"



MathSet::MathSet(char name) : name(name) {
}

MathSet::MathSet() {
}

std::ostream &operator<<(std::ostream &os, const MathSet &set) {
    os<<set.set_container;
    return os;
}

MathSet MathSet::operator|(const MathSet &rhs) const {
    MathSet res;
    res.set_container = set_container + rhs.set_container;
    res.set_container = delRep(res.set_container);
    return (res);
}

MathSet MathSet::operator&(const MathSet &rhs) const {
    MathSet res;
    for (auto fromSet_Container:set_container) {
        for (auto fromRhsSet_Container:rhs.set_container)
            if (fromSet_Container == fromRhsSet_Container) {
                res.set_container += fromSet_Container;
                break;
            }
    }
    return (res);
}

MathSet MathSet::operator~() const {
    MathSet res;
    bool check ;
    for (auto fromUniversum:Universum) {
        check= true;
        for (auto fromSet_Container:set_container) {
            if (fromUniversum == fromSet_Container) {
                check = false;
                break;
            }
        }
        if (check)
            res.set_container += fromUniversum;
    }
    return (res);
}

MathSet::MathSet(char name, const std::string &set) : name(name), set_container(set) {}

void MathSet::setSet(const std::string &set) {
    MathSet::set_container = set;
}

char MathSet::getName() const {
    return name;
}

const std::string &MathSet::getSet_container() const {
    return set_container;
}






