#ifndef NODEVERTEX_H
#define NODEVERTEX_H

#include <vector>
#include <iostream>

#include "NodeEdges.h"
#include "ListEdges.h"

class NodeVertex
{
    public:
        NodeVertex();
        NodeVertex(string, int, int, string, string, NodeVertex*, ListEdges);
        
        ~NodeVertex();
    private: 
        NodeVertex* next = nullptr;
        ListEdges edges;
        //Vector o lista de direcciones tipo NodeEdges*

        string nameSucursal = "";
        int x, y;
        string phone = "";
        string schedule = "";

        int getNumEdges();
        //getHeaviestA()


        friend class ListEdges;
        friend class NodeEdges;
        friend class Graph;
};

#endif