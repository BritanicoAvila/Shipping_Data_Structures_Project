#ifndef GRAPH_H
#define GRAPH_H

/*
#include "NodeEdges.h"
#include "NodeVertex.h"
#include "ListEdges.h"
#include "ListVertex.h"
*/
using namespace std;
#include <iostream>

#include "ListVertex.h"
#include "ListEdges.h"

class Graph
{
private:
    
    ListVertex vertex;

public:

    ListEdges Dijkstra (NodeVertex*, NodeVertex*);
    void newVertex ();               // insertar vértice 
    void newEdge ();                 // insertar arista
    void deleteVertex();             // eliminar vértice
    void deleteEdge();               // eliminar arista
    void printGraph();               // imprimir listado de vértice/arista


    Graph(/* args */);
    ~Graph();
};

#endif // GRAPH_H




