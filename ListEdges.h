#ifndef LISTEDGES_H
#define LISTEDGES_H

#include <iostream>

#include "NodeEdges.h"
#include "NodeVertex.h"

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
        //Node* buscarDato(int);

    private: 

        NodeEdges *h;
        int numEdges;
        int heaviest;

        friend class NodeEdges;
        friend class NodeVertex;
        friend class Graph;
};

#endif // LISTEDGES_H