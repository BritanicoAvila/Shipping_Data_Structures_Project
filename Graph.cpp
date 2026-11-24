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
    if (vertex.vertexNumber >= 2)    //Hay minimo 2 vertices
    {
    cout << "Imprimiendo lista actual de sucursales: " << endl;
    vertex.showAll();
    string sucursal = "";
    NodeVertex *from, *to = nullptr;
    bool flag = true;

        while (flag)       //Si esta cosa devuelve un puntero valido
        {
        cout << "Introduzca el nombre de la sucursal del origen del enlace: ";
        cin >> sucursal;

            if (vertex.searchingData(sucursal))        //Si esta cosa devuelve un puntero valido
            {
            flag = false;
            from = vertex.searchingData(sucursal);
            }
            else
            {
            cout << "Sucursal no encontrada, revise sus datos y vuelva a intentarlo..." << endl << endl;
            }
        }
        ////////////////////////////////////////////////////////////////////////
        flag = true;
                while (flag)       //Si esta cosa devuelve un puntero valido
        {
        cout << "Introduzca el nombre de la sucursal al que apunta el enlace: ";
        cin >> sucursal;

            if (vertex.searchingData(sucursal))        //Si esta cosa devuelve un puntero valido
            {
            flag = false;
            to = vertex.searchingData(sucursal);
            }
            else
            {
            cout << "Sucursal no encontrada, revise sus datos y vuelva a intentarlo..." << endl << endl;
            }
        }
    from->edges.insert(to, vertex.distanceCalculator(from, to));   //Agrega la arista con los parametros necesarios
    //FALTA EL VECTOR DE DIRECCIONES PARA ACTUALIZARSE
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
    //FALTA LA LISTA DE DIRECCIONES PARA BORRAR LAS ARISTAS QUE LO APUNTAN

    }

}
void Graph::deleteEdge()
{

}     
void Graph::printGraph()
{

}