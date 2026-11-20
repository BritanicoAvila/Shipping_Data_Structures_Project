#ifndef LISTA_H
#define LISTA_H

#include <iostream>

#include "ListA.h"
#include "NodeA.h"
#include "NodeV.h"

class ListA
{
    public:
        ListA();
        ~ListA();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Consultas                                        //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    
        bool IsEmpty();
        void showAll();
        NodeV* buscarDato(string);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Operadores                                       //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void insert(NodeV*, int);
        void deleteAll();
        void deleteEdges(NodeV*);
        int setHeaviest();
        //Node* buscarDato(int);

    private: 

        NodeA *h;
        int numAristas;
        int heaviest;

        friend class NodeA;
        friend class ListaV;
        friend class NodeV;
        friend class Graph;
};

#endif // LISTA_H