#ifndef LISTEDGES_H
#define LISTEDGES_H

#include <iostream>
using namespace std;
/*
#include "NodeEdges.h"
#include "NodeVertex.h"
*/

class NodeVertex; // Declaración adelantada
class NodeEdges;  // Declaración adelantada

class ListEdges
{
    public:
        ListEdges();
        ~ListEdges();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Consultas                                        //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        bool IsEmpty();
        void showAll();
        NodeVertex* searchingData(string);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Operadores                                       //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void insert(NodeVertex*, int);
        void deleteAll();
        void deleteEdges(NodeVertex*);
        int setHeaviest();

    private: 

        NodeEdges *h;
        int numEdges;
        int heaviest;

        friend class NodeEdges;
        friend class NodeVertex;
        friend class Graph;
};

#endif // LISTEDGES_H