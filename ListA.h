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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Operadores                                       //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void insert(NodeV*);
        void deleteAll();
        void deleteEdges(NodeV*);
        void setHeaviest();
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