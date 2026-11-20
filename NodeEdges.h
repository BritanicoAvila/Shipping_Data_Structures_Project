#ifndef NODEEDGES_H
#define NODEEDGES_H

#include "NodeVertex.h"
#include <iostream>
using namespace std;

class NodeEdges
{
    public:
        NodeEdges();
        ~NodeEdges();
        NodeEdges(NodeVertex*);
        NodeEdges(NodeVertex*, int);
        NodeEdges(int, NodeEdges*, NodeVertex*);

    private: 
        int weight;
        NodeEdges* next;
        NodeVertex* direction;

        friend class ListEdges;
        friend class NodeVertex;
        friend class Graph;
};

#endif // NodeEdges_H
