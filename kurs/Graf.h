//
// Created by andresold on 28.11.17.
//

#ifndef ALGANDSTR_3SEM_KURS_SPISOK_H
#define ALGANDSTR_3SEM_KURS_SPISOK_H

#include "Virt.h"

class Graf {
private:
    Lref Head; //Указатель на голову списка заголовочных узлов.
    Lref Tail; //Указатель на фиктивный элемент
    // в конце списка заголовочных узлов.

    void SearchGraph(int, Lref *);

public:
    Graf() {//Инициализация списка заголовочных узлов.
        Head = Tail = new (Leader);
    }

    Lref GetHead() { return Head; }

    Lref GetTail() { return Tail; }

    void MakeGraph();

    void Ostov_Breadth();

};


#endif //ALGANDSTR_3SEM_KURS_SPISOK_H
