#include "NodeEdges.h"
#include "NodeVertex.h"
#include "ListEdges.h"
#include "ListVertex.h"
#include "Graph.h"

using namespace std;
#include <iostream>

Graph::Graph(/* args */)
{
    vertex;
}

Graph::~Graph()
{
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Inserciones                                      //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Graph::newVertex ()
{
    vertex.insert();
    vertex.balancerSetter(vertex.h);
}
void Graph::newEdge ()
{
    if (vertex.vertexNumber >= 2)
    {
    cout << "Imprimiendo lista actual de sucursales: " << endl;
    vertex.showAll();
    string sucursal = "";
    bool flag = true;

        while (flag)       //Si esta cosa devuelve un puntero valido
        {
        cout << "Introduzca el nombre de la sucursal del origen del enlace: ";
        cin >> sucursal;

            if (vertex.searchingData(sucursal))        //Si esta cosa devuelve un puntero valido
            {
            flag = false;
            }
            else
            {
            cout << "Sucursal no encontrada, revise sus datos y vuelva a intentarlo..." << endl << endl;
            }
        }
        ////////////////////////////////////////////////////////////////////////
    }
    else
    {
        cout << "Sucursales insuficientes como para establecer conexiones" << endl;
    }
//verifica si hay vertices
//imprime todos o pide nombre?
//inserta y conecta...
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Eliminaciones                                    //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Graph::deleteVertex()
{
    if (vertex.h)
    {
    string sucursal = "";
    bool flag = true;

        while (flag)       //Si esta cosa devuelve un puntero valido
        {
        cout << "Introduzca el nombre de la sucursal a eliminar: ";
        cin >> sucursal;

            if (vertex.searchingData(sucursal))        //Si esta cosa devuelve un puntero valido
            {
            flag = false;
            }
            else
            {
            cout << "Sucursal no encontrada, revise sus datos y vuelva a intentarlo..." << endl << endl;
            }
        }

    vertex.deleteVertex(vertex.searchingData(sucursal));
    vertex.generalBalancer();

    }

}
void Graph::deleteEdge()
{

}     
void Graph::printGraph()
{

}