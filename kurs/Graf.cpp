//
// Created by andresold on 28.11.17.
//

#include <iostream>
#include "Graf.h"
#include <fstream>
#include <queue>


void Graf::SearchGraph(int w, Lref *h)
//Функция возвращает указатель на заголовочный узел
//с ключом w в графе, заданном структурой Вирта с указателем Head.
{
    *h = Head;
    (*Tail).Key = w;
    while ((**h).Key != w) {
        *h = (**h).Next;
    }
    if (*h == Tail)
        //В списке заголовочных узлов нет узла с ключом w.
        //Поместим его в конец списка Head.
    {
        Tail = new (Leader);
        (**h).Count = 0;
        (**h).Trail = nullptr;
        (**h).Flag=true;
        (**h).Next = Tail;

    }
}

void Graf::MakeGraph()
//Функция возвращает указатель Head на структуру
//Вирта, соответствующую ориентированному графу.
{
    int x, y;
    Lref p, q; //Рабочие указатели.
    Tref t, r; //Рабочие указатели.
    bool Res; //Флаг наличия дуги.

    std::ifstream fin("input.txt", std::ios_base::in);
    while (!fin.eof()) {
        fin >> x;
        fin >> y;
        //Определим, существует ли в графе дуга (x,y)?
        SearchGraph(x, &p);
        SearchGraph(y, &q);
        r = (*p).Trail;
        Res = false;
        while ((r != nullptr) && (!Res))
            if ((*r).Id == q) Res = true;
            else r = (*r).Next;
        if (!Res) //Если дуга отсутствует, то поместим её в граф.
        {
            t = new (Trailer);
            (*t).Id = q;
            (*t).Next = (*p).Trail;
            (*p).Trail = t;
            (*q).Count++;
        }
    }
    fin.close();
}

void Graf::Ostov_Breadth()
//Обход графа, заданного указателем r в ширину (нерекурсивный
//обход), соединенный с построением стягивающего дерева.
{
    std::ofstream fout("output.txt", std::ios_base::app);
    std::queue<Tref> queueOne;
    std::queue<Lref> queueTwo;
    Tref s;    //Рабочий указатель.
    Tref t;    //Рабочий указатель.
    Tref Tail1;//Указатель на фиктивный элемент в очереди L,R;
    Lref v;    //Рабочий указатель.

    Tail1 = new (Trailer); //Построили фиктивный элемент.
    Head->Flag = false;
    t = Head->Trail;
    while (t != nullptr) {
        queueOne.push(t);
        t = t->Next;
    }
    queueOne.push(Tail1);
    v = Head;
    while (queueOne.size() != 0)
        //Пока очередь не пуста...
    {

        t = queueOne.front();
        queueOne.pop();
        if (t != Tail1) {
            if (t->Id->Flag) {
                fout << v->Key << " " << t->Id->Key << "\n";

                t->Id->Flag = false;
            }
            s = t->Id->Trail;

            queueTwo.push(t->Id);
            while (s != nullptr) {
                if (s->Id->Flag) {
                    queueOne.push(s);
                    t->Id->Flag = false;
                }
                s = s->Next;
            }

            queueOne.push(Tail1);
        } else {
            v = queueTwo.front();
            queueTwo.pop();
        }
    }
}

