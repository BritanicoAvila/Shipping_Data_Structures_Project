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
    vertex.generalBalancer();
}
void Graph::newEdge()
{
    if(vertex.vertexNumber < 2){
        cout << "Sucursales insuficientes como para establecer conexiones" << endl;
        return;
    }

    cout << "Imprimiendo lista actual de sucursales: " << endl;
    vertex.showAll();
    
    string sucursal = "";
    NodeVertex *from, *to = nullptr;

    while (from == nullptr)
    {
        cout << "Introduzca el nombre de la sucursal del origen del enlace: ";
        getline(cin, sucursal);
        from == vertex.searchingData(sucursal);

        if(from == nullptr) 
        {
            cout << "Sucursal no encontrada, revise sus datos y vuelva a intentarlo...!" << endl << endl;
        }
    }


    if (from -> edges.numEdges >= vertex.vertexNumber - 1) 
    {
        cout << "Esta sucursal ya esta conectada con todas las demas sucursales." << endl;
        return;
    }
    

    while(to == nullptr){
        cout << "Introduzca el nombre de la sucursal a la que apunta el enlace: " << endl;
        getline(cin, sucursal);
        NodeVertex* candidate = vertex.searchingData(sucursal);

        if(candidate == nullptr)
        {
            cout << "Sucursal no encontrada, revise sus datos y vuelva a intentarlo ..." << endl << endl;
        }
        else if (candidate == from)
        {
            cout <<"No puedes conectar una sucursal consigo misma." << endl << endl;
        }
        else if (from -> edges.hasEdge(candidate)){
            cout << "Esa conexion ya existe, elija otro destino." << endl << endl;
        }
        else {
            to = candidate;
        }
    }

    int weight = vertex.distanceCalculator(from, to);
    from -> edges.insert(to, weight);
    from -> edges.setHeaviest();
    cout << "Conexion agregada: " << from -> nameSucursal << "-> " << 
    to -> nameSucursal << "(Peso: )" << weight << ")" << endl;


    //from->edges.insert(to, vertex.distanceCalculator(from, to));   //Agrega la arista con los parametros necesarios
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