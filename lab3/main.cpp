#include <iostream>
#include "Tree.h"

int main() {
    int n;

    Tree test('a', 'z', 5);
    test.MakeTree();
    test.OutTree();
    n = test.DFS();
    std::cout << "\nПройдено узлов: " << n;
    return 0;
}