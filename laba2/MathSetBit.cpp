//
// Created by andresold on 12.10.17.
//

#include "MathSetBit.h"
#include "MathSetList.h"
#include "workBit.h"


MathSetBit::MathSetBit() {
    set_container = std::vector<int>(26, 0);
}

MathSetBit::MathSetBit(char name) : name(name) {
    set_container = std::vector<int>(26, 0);
}


std::ostream &operator<<(std::ostream &os, const MathSetBit &bit) {

    int i = 0;
    for (auto outLetter:Universum) {
        if (bit.set_container[i])
            os << outLetter;
        i++;
    }
    os << "\n";
    for (auto outBit:bit.set_container) {
        os << outBit;
    }
    os<<"\n";
    return os;
}

MathSetBit MathSetBit::operator|(const MathSetBit &rhs) const {
    MathSetBit res;
    for (int i = 0; i < Universum.size(); i++) {

        res.set_container[i] = ((set_container[i] | rhs.set_container[i]));

    }
    return (res);
}

MathSetBit MathSetBit::operator&(const MathSetBit &rhs) const {
    MathSetBit res;
    for (int i = 0; i < Universum.size(); i++) {
        if ((rhs.set_container[i] & set_container[i])) {
            res.set_container[i] = 1;
        }
    }
    return (res);
}

MathSetBit MathSetBit::operator~() const {
    MathSetBit res;
    int i = 0;
    for (auto x:set_container) {
        res.set_container[i] = (~x);
        i++;
    }
    return (res);
}

MathSetBit::MathSetBit(char name, const std::vector<int> &set) : name(name), set_container(set) {}

char MathSetBit::getName() const {
    return name;
}

const std::vector<int> &MathSetBit::getSet_container() const {
    return set_container;
}

void MathSetBit::setSet(const std::vector<int> &set_container) {
    MathSetBit::set_container = set_container;
}



