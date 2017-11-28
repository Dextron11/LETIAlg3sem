#include <iostream>
#include "Virt.h"
#include "Spisok.h"
#include "printGraf.h"


int main() {
    Spisok A;
    Lref t; //Рабочий указатель для перемещения
    //по списку заголовочных звеньев.
    //Построение графа и вывод его структуры Вирта.
    A.MakeGraph();

    t = A.GetHead();
    while (t != A.GetTail()) {
        (*t).Flag = true;
        t = (*t).Next;
    }
    A.Ostov_Breadth();
    std::cout << "\n";
    printG();

}
