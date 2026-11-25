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
        ListEdges(const ListEdges&);
        ListEdges& operator=(const ListEdges&);
        ~ListEdges();

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////                                             Consultas                                        //////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        bool IsEmpty();
        void showAll();
        NodeVertex* searchingData(string);
        bool hasEdge(NodeVertex*);

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //////////                                             Operadores                                       //////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void insert(NodeVertex*, int);
        void deleteAll();
        void deleteEdges(NodeVertex*);
        int setHeaviest();
        void deleteHeaviest();

    private: 

        NodeEdges *h;
        int numEdges;
        int heaviest;

        friend class NodeEdges;
        friend class ListVertex;
        friend class NodeVertex;
        friend class Graph;
};

#endif // LISTEDGES_H