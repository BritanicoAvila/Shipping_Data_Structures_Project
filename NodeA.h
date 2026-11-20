#ifndef NODEA_H
#define NODEA_H
#include "NodeV.h"
#include <iostream>
using namespace std;

class NodeA
{
    public:
        NodeA();
        ~NodeA();
        NodeA::NodeA(NodeV*);
        NodeA(int, NodeA*, NodeV*);

    private: 
        int weight;
        NodeA* sig;
        NodeV* direction;

        friend class ListA;
        friend class ListaV;
        friend class NodeV;
        friend class Graph;
};

#endif // NODEA_H
