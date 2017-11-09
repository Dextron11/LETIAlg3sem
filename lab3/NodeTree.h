//
// Created by andresold on 19.10.17.
//

#ifndef ALGLAB3TREE_NODETREE_H
#define ALGLAB3TREE_NODETREE_H


class NodeTree {
    NodeTree *lft;//левый
    NodeTree *mdl;//средний
    NodeTree *rgt;//правый
    char d;
public:
    NodeTree():lft(nullptr),mdl(nullptr),rgt(nullptr){};//конструктор узла
    ~NodeTree(){if(lft)delete lft;if(mdl)delete (mdl);if(rgt)delete (rgt);}//деструктор узла
    friend class Tree;
};


#endif //ALGLAB3TREE_NODETREE_H
