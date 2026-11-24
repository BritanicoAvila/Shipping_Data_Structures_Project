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

    void newVertex ();               // insertar vértice 
    void newEdge ();                 // insertar arista
    void deleteVertex();             // eliminar vértice
    void deleteEdge();               // eliminar arista
    void printGraph();               // imprimir listado de vértice/arista
   // void kruskal();                  // realizar un recorrido mínimo (prim, kruskal, djistra) , e indicar los vertices que se recorren 


    Graph(/* args */);
    ~Graph();
};




