#ifndef NODEV_H
#define NODEV_H
#include "NodeA.h"
#include <vector>
#include <iostream>
using namespace std;

class NodeV
{
    public:
        NodeV();
        ~NodeV();
        NodeV(int, NodeA*);

    private: 
        int weight;
        NodeV* sig;
        //Vector o lista de direcciones tipo NodeA*

        ListA edges;
        NodeV* sig;
        string nameSucursal;
        int x, y;
        string phone;
        string schedule;

        friend class ListA;
        friend class ListaV;
        friend class NodeA;
        friend class Graph;
};

#endif // NODEA_H