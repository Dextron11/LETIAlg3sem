//
// Created by andresold on 19.10.17.
//

#ifndef ALGLAB3TREE_TREE_H
#define ALGLAB3TREE_TREE_H


#include "NodeTree.h"

class Tree {
    NodeTree *root;//корень дерева
    char num, maxnum;//текущий тег и максимальный тег
    int maxrow, offset;//максимальная глубиа,смещение корня
    char **SCREEN;//для выдачи на экран
    void clrscr();
    NodeTree *MakeNode(int depht);//создание поддеерева
    void OutNodes(NodeTree *v, int r, int c);//вывод поддерева
    Tree(const Tree &);//фиксмрованый конструктор копии
    Tree operator=(const Tree &) const;//Фиктивное присваевание
public:
    Tree(char num, char maxnum, int maxrow);

    ~Tree();

    void MakeTree() {
        root = MakeNode(0);
    }

    bool exist() {
        return root != nullptr;
    }

    int DFS();
    void OutTree();
};


#endif //ALGLAB3TREE_TREE_H
