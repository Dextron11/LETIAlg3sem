//
// Created by andresold on 12.10.17.
//

#ifndef LABALGK2_MATHSETCOM_H
#define LABALGK2_MATHSETCOM_H


#include <ostream>

class MathSetCom {
    char name;//имя множества;
    int set_container;//множество
    MathSetCom();
public:

    MathSetCom(char name);

    MathSetCom(char name, int set);

    friend std::ostream &operator<<(std::ostream &os, const MathSetCom &com);

    MathSetCom operator|(const MathSetCom &rhs) const;//Логическое "Или"

    MathSetCom operator&(const MathSetCom &rhs) const;//Логическое "И"

    MathSetCom operator~() const;//Логическое отрицание

    int getSet_container() const;

    void setSet(int set_container);

    char getName() const;

};


#endif //LABALGK2_MATHSETCOM_H
