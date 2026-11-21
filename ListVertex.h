#ifndef LISTVERTEX_H
#define LISTVERTEX_H

#include <vector>
#include <iostream>
using namespace std;

class NodeEdges;
#include "NodeVertex.h"
#include "ListEdges.h"
#include "Graph.h"


class ListVertex
{


private:

NodeVertex *h;
int vertexNumber;   


public:
    ListVertex();
    ~ListVertex();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Consultas                                        //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        bool IsEmpty();
        void showAll();
        // NodeVertex* searchingData(string);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Operadores                                       //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void insert();         
        void deleteAll();
        void deleteVertex(NodeVertex*);
        NodeVertex* fuller();            //Llena el nodo vertex
        int calculator (NodeVertex*);              //Calcula la hipotenusa1



        friend class ListEdges;
        friend class NodeEdges;
        friend class NodeVertex;
        friend class Graph;

};

#endif