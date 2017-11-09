//
// Created by andresold on 19.10.17.
//

#include <cstdlib>
#include <cstring>
#include <iostream>
#include "Tree.h"

const int lenght = 65;


Tree::Tree(char num, char maxnum, int maxrow) :
        num(num), maxnum(maxnum), maxrow(maxrow), offset(lenght), root(nullptr), SCREEN(new char *[maxrow]) {
    for (int i = 0; i < maxrow; i++) SCREEN[i] = new char[lenght * 2];
}

Tree::~Tree() {
    for (int i = 0; i < maxrow; i++)delete[]SCREEN[i];
    delete[]SCREEN;
    delete root;
}

NodeTree *Tree::MakeNode(int depht) {
    NodeTree *v = nullptr;
    int Y = (depht < rand() % 4 + 1) && (num <= 'z');
    if (Y) {
        v = new NodeTree;
        v->lft = MakeNode(depht + 1);
        v->d = num++;
        v->mdl = MakeNode(depht + 1);
        v->rgt = MakeNode(depht + 1);

    }
    return (v);
}

void Tree::OutTree() {
    clrscr();
    OutNodes(root, 1, offset);

    for (int i = 0; i < maxrow; i++) {
     SCREEN[i][lenght * 2 - 1] = '\0';

        std::cout << '\n' << SCREEN[i];
    }
    std::cout << '\n';
}

void Tree::clrscr() {
    for (int i = 0; i < maxrow; i++) {
        memset(SCREEN[i], '.', lenght * 2 - 1);
    }

}

void Tree::OutNodes(NodeTree *v, int r, int c) {
    if (r && c && (c < lenght * 2)) {
        SCREEN[r - 1][c - 1] = v->d;
    }
    if (r < maxrow) {
        if (v->lft)OutNodes(v->lft, r + 1, c - (offset >> r)-5);
        if (v->mdl)OutNodes(v->mdl, r + 1, c);
        if (v->rgt)OutNodes(v->rgt, r + 1, c + (offset >> r)+5);
    }
}

template<class item>
class STACK {
    item *S;
    int t;
public:
    STACK(int maxt) : S(new item[maxt]), t(0) {}

    int empty() const { return t == 0; }

    void push(item item1) { S[t++] = item1; }

    item pop() { return (t ? S[--t] : 0); }
};


int Tree::DFS() {
    const int MaxS = 20;
    std::cout << '\n';
    int count = 0;
    STACK<NodeTree *> S(MaxS);
    S.push(root);
    int n=0;
    while (!S.empty()) {
        NodeTree *v = S.pop();

        std::cout << v->d << '_';
        count++;
        if((v!=root)&&(((v->lft)!= nullptr)||((v->mdl)!= nullptr)||((v->mdl)!= nullptr)))
            n++;
        if (v->rgt)S.push(v->rgt);
        if (v->mdl)S.push(v->mdl);
        if (v->lft)S.push(v->lft);

    }
    std::cout << "\nКоличество листьев не на самом нижнем уровне,имеющие листья: "<<n;
    return (count);
}
