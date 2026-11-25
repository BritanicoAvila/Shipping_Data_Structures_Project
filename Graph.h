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

        ListEdges Dijkstra (NodeVertex*, NodeVertex*);
        void runDijkstra();              // recorrido mínimo (Dijkstra) indicando vértices recorridos
        void newVertex ();               // insertar vértice 
        void newEdge ();                 // insertar arista
        void deleteVertex();             // eliminar vértice
        void deleteEdge();               // eliminar arista
        void printGraph();               // imprimir listado de vértice/arista


        Graph(/* args */);
        ~Graph();
};

#endif // GRAPH_H


