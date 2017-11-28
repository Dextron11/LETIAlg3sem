#ifndef ALGANDSTR_3SEM_KURS_Virt_H
#define ALGANDSTR_3SEM_KURS_Virt_H

typedef struct Leader *Lref; // Тип: указатель на заголовочный узел.
typedef struct Trailer *Tref; // Тип: указатель на дуговой узел.

//Описание типа заголовочного узла.
typedef struct Leader {
    int Key; //Имя заголовочного узла.
    int Count; //Количество предшественников.
    bool Flag; //Флаг посещения узла при обходе.
    Tref Trail; //Указатель на список смежности.
    Lref Next; //Указатель на следующий узел в списке заголовочных узлов.
};

//Описание типа дугового узла.
typedef struct Trailer {
    Lref Id;
    Tref Next;
};

//Описание типа узла очереди.
typedef Tref TipElement; //Указатель на звено заголовочного списка.
typedef struct Zveno *svqz;
typedef struct Zveno {
    TipElement Element; //Указатель на список смежности.
    svqz Sled;
};

//Описание типа узла очереди указателей на
//узлы списков смежности.
typedef Lref TipElement1;
typedef struct Zveno1 *svqz1;
typedef struct Zveno1 {
    TipElement1 Element; //Указатель на заголовочный узел.
    svqz1 Sled;
};
#endif //ALGANDSTR_3SEM_KURS_Virt_H