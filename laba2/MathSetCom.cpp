//
// Created by andresold on 12.10.17.
//

#include <iostream>
#include "MathSetCom.h"
#include "workCom.h"


MathSetCom::MathSetCom() {}

MathSetCom::MathSetCom(char name) : name(name) {}

std::ostream &operator<<(std::ostream &os, const MathSetCom &com) {
    for (int i = 0; i <= Universum.size(); ++i){
        if ((com.set_container >> i) & 1)
            os<< Universum[i];}
    os<<"\n";
    for (int i = Universum.size(); i >= 0; --i)
    {
        os<< ((com.set_container >> i) & 1);}
    os<<"\n";
    return os;
}


MathSetCom MathSetCom::operator|(const MathSetCom &rhs) const {
    MathSetCom res;
    res.set_container=set_container|rhs.set_container;
    return (res);
}

MathSetCom MathSetCom::operator&(const MathSetCom &rhs) const {
    MathSetCom res;
    res.set_container=set_container&rhs.set_container;
    return (res);

}

MathSetCom MathSetCom::operator~() const {
    MathSetCom res;
    res.set_container=(~set_container);
    return (res);
}

MathSetCom::MathSetCom(char name, int set) : name(name), set_container(set) {}

void MathSetCom::setSet(int set_container) {
    MathSetCom::set_container = set_container;
}

int MathSetCom::getSet_container() const {
    return set_container;
}


char MathSetCom::getName() const {
    return name;
}






