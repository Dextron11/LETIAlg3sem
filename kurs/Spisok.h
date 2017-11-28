//
// Created by andresold on 28.11.17.
//

#ifndef ALGANDSTR_3SEM_KURS_SPISOK_H
#define ALGANDSTR_3SEM_KURS_SPISOK_H

#include "Virt.h"

class Spisok {
private:
    Lref Head; //Указатель на голову списка заголовочных узлов.
    Lref Tail; //Указатель на фиктивный элемент
    // в конце списка заголовочных узлов.
    void Udalenie_A(svqz *, svqz *, TipElement *);

    void Udalenie_A1(svqz1 *, svqz1 *, Lref *);

    void Dobavlenie(svqz *, svqz *, TipElement);

    void Dobavlenie1(svqz1 *, svqz1 *, Lref);

    void SearchGraph(int, Lref *);

public:
    Spisok() {//Инициализация списка заголовочных узлов.
        Head = Tail = new (Leader);
    }

    Lref GetHead() { return Head; }

    Lref GetTail() { return Tail; }

    void MakeGraph();


    void Ostov_Breadth();
};


#endif //ALGANDSTR_3SEM_KURS_SPISOK_H
