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
    NodeVertex *from = nullptr, *to = nullptr;

    while (from == nullptr)
    {
        cout << "Introduzca el nombre de la sucursal del origen del enlace: ";
        getline(cin, sucursal);
        from = vertex.searchingData(sucursal);

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
    to -> nameSucursal << "(Peso: " << weight << ")" << endl;


    //from->edges.insert(to, vertex.distanceCalculator(from, to));   //Agrega la arista con los parametros necesariosz
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Eliminaciones                                    //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Graph::deleteVertex()
{
    if(vertex.IsEmpty()){
        cout << "No hay sucursales registradas" << endl;
        return;
    }

    string sucursal = "";
    NodeVertex* target;
    bool flag = true;

    while (flag)       //Si esta cosa devuelve un puntero valido
    {
        vertex.showAll();
        cout << "Introduzca el nombre de la sucursal a eliminar: ";
        getline(cin, sucursal);
        target = vertex.searchingData(sucursal);

        if (target)        //Si esta cosa devuelve un puntero valido
        {
            flag = false;
        }
        else
        {
            cout << "Sucursal no encontrada, revise sus datos y vuelva a intentarlo..." << endl << endl;
        }
    }

    NodeVertex* aux = vertex.h;
    while (aux != nullptr)
    {
        if(aux != target and aux -> edges.hasEdge(target)){
            aux -> edges.deleteEdges(target);
            
            if(!aux -> edges.IsEmpty()){
                aux -> edges.setHeaviest();
            }
            else {
                aux -> edges.heaviest = 0;
            }
        }
        aux = aux -> next;
    }
    vertex.deleteVertex(target);
    vertex.generalBalancer();

    cout << "Sucursal eliminada correctamente." << endl;
}

void Graph::deleteEdge()
{
    if(vertex.IsEmpty()){
        cout << "No hay sucursales registradas" << endl;
        return;
    }

    cout << "Imprimiendo lista actual de sucursales: " << endl;
    vertex.showAll();

    string sucursal = "";
    NodeVertex* from = nullptr;
    NodeVertex* to = nullptr;


    while (from == nullptr)
    {
        cout << "Introduzca el nombre de la sucursal origen de la conexion a eliminar: ";
        getline(cin, sucursal);
        from = vertex.searchingData(sucursal);

        if(from == nullptr){
            cout << "Sucursal no encontrada, intente de nuevo." << endl;
        }
    }

    if(from -> edges.IsEmpty())
    {
        cout << "Esta sucursal no tiene conexiones para eliminar" << endl;
        return;
    }

    cout << "Conexiones actuales de " << from -> nameSucursal <<":" << endl;
    from -> edges.showAll();
    
    while (to == nullptr){
        cout << "Introduzca el nombre de la sucursal destino a desconectar: ";
        getline(cin, sucursal);

        NodeVertex* candidate = vertex.searchingData(sucursal);

        if(candidate == nullptr || !(from -> edges.hasEdge(candidate))){
            cout << "No existe una conexion hacia esa sucursal, intente de nuevo" << endl;
        } else {
            to = candidate;
        }
    }

    from -> edges.deleteEdges(to);
    if(!from -> edges.IsEmpty()){
        from->edges.setHeaviest();
    } else {
        from -> edges.heaviest = 0;
    }

    cout << "Conexion eliminada correctamente" << endl;
} 


void Graph::printGraph()
{

}