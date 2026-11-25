#ifndef NODEVERTEX_H
#define NODEVERTEX_H

#include <iostream>
using namespace std;
/*
#include "NodeEdges.h"
#include "ListEdges.h"
#include "ListVertex.h"
*/
#include "ListEdges.h" // Seguro incluirlo porque ListEdges.h ya no incluye nada tuyo
class NodeEdges;

class NodeVertex
{
    public:
        NodeVertex();
        NodeVertex(string, int, int, string, string);
        
        ~NodeVertex();
    private:
        NodeVertex* next = nullptr;
        ListEdges edges;

        int Dijk;            //PARA Dijkstra
        bool dijState;
        NodeVertex* predecessor;
        // std::vector<NodeEdges*> edgesDirections; =
        //Vector o lista de direcciones tipo NodeEdges*

        string nameSucursal = "";
        int x, y;
        string phone = "";
        string schedule = "";

        // int getNumEdges();
        // int getHeaviestA();
        
        friend class ListEdges;
        friend class NodeEdges;
        friend class ListVertex;
        friend class Graph;
};

#endif