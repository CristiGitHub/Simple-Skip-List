//
// Created by Cristi on 5/19/2021.
//

#ifndef SKIPLISTPROJECT_NODE_H
#define SKIPLISTPROJECT_NODE_H
#include <cstdlib>

class Node {
private:
    int val;
public:
    Node **next;
    Node(int valoare, int nivel){
        val=valoare;
        next = new Node*[nivel+1];
        memset(next,0,sizeof(Node*)*(nivel+1));
    }

    int getVal() const {
        return val;
    }

    void setVal(int val) {
        Node::val = val;
    }

};


#endif //SKIPLISTPROJECT_NODE_H
