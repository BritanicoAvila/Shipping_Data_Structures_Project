#ifndef GRAPH_H
#define GRAPH_H

#include "ListVertex.h"
#include "ListEdges.h"
#include <iostream>

class Graph
{
    private:
        
        ListVertex vertex;

    public:

        void newVertex ();               // insertar vértice 
        void newEdge ();                 // insertar arista
        void deleteVertex();             // eliminar vértice
        void deleteEdge();               // eliminar arista
        void printGraph();               // imprimir listado de vértice/arista
    // void kruskal();                  // realizar un recorrido mínimo (prim, kruskal, djistra) , e indicar los vertices que se recorren 


        Graph(/* args */);
        ~Graph();
};

#endif


