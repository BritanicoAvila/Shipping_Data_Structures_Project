#ifndef NODEVERTEX_H
#define NODEVERTEX_H

#include <vector>
#include <iostream>

#include "NodeEdges.h"
#include "ListEdges.h"

using namespace std;

class NodeVertex
{
    public:
        NodeVertex();
        ~NodeVertex();
        NodeVertex(int, NodeEdges*);

    private: 
        int weight;
        NodeVertex* next;
        std::vector<NodeEdges*> edgesDirections; 
        //Vector o lista de direcciones tipo NodeEdges*

        ListEdges edges;
        string nameSucursal;
        int x, y;
        string phone;
        string schedule;

        int getNumEdges();
        int getHeaviestA();


        friend class ListEdges;
        friend class NodeEdges;
        friend class ListVertex;
        friend class Graph;
};

#endif