//
// Created by andresold on 28.11.17.
//

#include <iostream>
#include "Spisok.h"
#include <fstream>
void Spisok::SearchGraph(int w, Lref *h)
//Функция возвращает указатель на заголовочный узел
//с ключом w в графе, заданном структурой Вирта с указателем Head.
{
    *h = Head;
    (*Tail).Key = w;
    while ((**h).Key != w) *h = (**h).Next;
    if (*h == Tail)
        //В списке заголовочных узлов нет узла с ключом w.
        //Поместим его в конец списка Head.
    {
        Tail = new (Leader);
        (**h).Count = 0;
        (**h).Trail = nullptr;
        (**h).Next = Tail;
    }
}

void Spisok::MakeGraph()
//Функция возвращает указатель Head на структуру
//Вирта, соответствующую ориентированному графу.
{
    int x,y;
    Lref p,q; //Рабочие указатели.
    Tref t,r; //Рабочие указатели.
    bool Res; //Флаг наличия дуги.

    FILE *file;
    file = fopen("input.txt", "r");
    while (feof(file)==0)
    {
        fscanf(file,"%d",&x);
        fgetc(file);
        fscanf(file,"%d",&y);
        //Определим, существует ли в графе дуга (x,y)?
        SearchGraph (x, &p); SearchGraph (y,&q);
        r = (*p).Trail; Res = false;
        while ((r!=NULL)&&(!Res))
            if ((*r).Id==q) Res = true;
            else r = (*r).Next;
        if (!Res) //Если дуга отсутствует, то поместим её в граф.
        { t = new (Trailer); (*t).Id = q;
            (*t).Next = (*p).Trail; (*p).Trail = t; (*q).Count++; }
    }
}

void Spisok::Dobavlenie(svqz *L, svqz *R, TipElement elem)
//Добавление элемента elem в очередь, заданную указателями L и R.
{
    svqz K = new (Zveno);

    K->Element = elem;
    K->Sled = nullptr;
    if (*L == nullptr) {
        (*L) = K;
        (*R) = K;
    }
    else {
        (*R)->Sled = K;
        (*R) = K;
    }
}

void Spisok::Dobavlenie1(svqz1 *L, svqz1 *R, Lref elem)
//Добавление элемента elem в очередь, заданную указателями L и R.
{
    svqz1 K = new (Zveno1);

    K->Element = elem;
    K->Sled = nullptr;
    if (*L == nullptr) {
        (*L) = K;
        (*R) = K;
    }
    else {
        (*R)->Sled = K;
        (*R) = K;
    }
}

void Spisok::Udalenie_A(svqz *L, svqz *R, TipElement *A)
//Удаление элемента из очереди, заданной указателями L и R и
//помещение удаленного элемента в переменную A.
{
    svqz q;

    if ((*L) != nullptr)
        if ((*L)->Sled != nullptr) {
            (*A) = (*L)->Element;
            q = (*L);
            (*L) = (*L)->Sled;
            delete q;
        } else {
            (*A) = (*L)->Element;
            delete *L;
            (*L) = (*R) = nullptr;
        }
}

void Spisok::Udalenie_A1(svqz1 *L, svqz1 *R, Lref *A)
//Удаление элемента из очереди, заданной указателями L и R и
//помещение удаленного элемента в переменную A.
{
    svqz1 q;

    if ((*L) != nullptr)
        if ((*L)->Sled != nullptr) {
            (*A) = (*L)->Element;
            q = (*L);
            (*L) = (*L)->Sled;
            delete q;
        } else {
            (*A) = (*L)->Element;
            delete *L;
            (*L) = (*R) = nullptr;
        }
}

void Spisok::Ostov_Breadth()
//Обход графа, заданного указателем r в ширину (нерекурсивный
//обход), соединенный с построением стягивающего дерева.
{
    std::ofstream fout("output.txt",std::ios_base::app);
    svqz L;    //Указатель на начало очереди.
    svqz R;    //Указатель на конец  очереди.
    svqz1 L1;  //Указатель на начало очереди заглавных узлов.
    svqz1 R1;  //Указатель на конец  очереди заглавных узлов.
    Tref s;    //Рабочий указатель.
    Tref t;    //Рабочий указатель.
    Tref Tail1;//Указатель на фиктивный элемент в очереди L,R;
    Lref v;    //Рабочий указатель.

    Tail1 = new (Trailer); //Построили фиктивный элемент.
    //Создали пустые очеpеди.
    L = R = nullptr;
    L1 = R1 = nullptr;
    //Посетим первую непосещенную вершину графа.
    Head->Flag = false;
    t = Head->Trail;
    while (t != nullptr) {
        Dobavlenie(&L, &R, t);
        t = t->Next;
    }
    Dobavlenie(&L, &R, Tail1);
    v = Head;
    while (L != nullptr)
        //Пока очередь не пуста...
    {
        Udalenie_A(&L, &R, &t);
        if (t != Tail1) {
            if (t->Id->Flag) {
                fout << v->Key << " " << t->Id->Key<<"\n";
                t->Id->Flag = false;
            }
            s = t->Id->Trail;
            Dobavlenie1(&L1, &R1, t->Id);
            while (s != nullptr) {
                if (s->Id->Flag) {
                    Dobavlenie(&L, &R, s);
                    t->Id->Flag = false;
                }
                s = s->Next;
            }
            Dobavlenie(&L, &R, Tail1);
        } else Udalenie_A1(&L1, &R1, &v);
    }
}