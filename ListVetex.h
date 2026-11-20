#ifndef NODEVERTEX_H
#define NODEVERTEX_H

#include <vector>
#include <iostream>

#include "NodeVertex.h"
#include "ListEdges.h"

using namespace std;

class ListVetex
{


private:

NodeVertex *h;
int vertexNumber;   


public:
    ListVetex();
    ~ListVetex();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Consultas                                        //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        bool IsEmpty();
        void showAll();
        // NodeVertex* searchingData(string);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Operadores                                       //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void insert(NodeVertex);         //
        void deleteAll();
        void deleteVertex(NodeVertex*);
        NodeVertex fuller();            //Llena el nodo vertex
        int calculator (NodeVertex*);              //Calcula la hipotenusa1



        friend class ListEdges;
        friend class NodeEdges;
        friend class NodeVertex;
        friend class Graph;

};

#endif