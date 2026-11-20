#ifndef LISTA_H
#define LISTA_H
#include "NodeA.h"
#include <iostream>
using namespace std;

class ListA
{
    public:
        ListA();
        ~ListA();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Consultas                                        //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    
        bool vacia();
        void mostrarTodo();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Operadores                                       //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void insertar(NodeV*);
        void eliminar_todo();
        void eliminarA(NodeV*);
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