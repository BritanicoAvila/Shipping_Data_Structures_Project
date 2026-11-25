#include "Graph.h"
#include "NodeEdges.h"
#include "NodeVertex.h"
#include "ListVertex.h"
#include "ListEdges.h"
#include <iostream>
#include <climits>

using namespace std;

Graph::Graph(){}

ListEdges Graph::Dijkstra (NodeVertex* from, NodeVertex* to)
{
    ListEdges path;
    if (from == nullptr || to == nullptr || vertex.IsEmpty())
    {
        return path;
    }

    // Inicializamos todos los vertices para empezar Dijkstra desde cero
    bool foundFrom = false;
    bool foundTo = false;
    NodeVertex* aux = vertex.h;
    while (aux != nullptr)
    {
        aux->Dijk = INT_MAX;
        aux->dijState = false;
        aux->predecessor = nullptr;

        if (aux == from)
        {
            foundFrom = true;
        }
        if (aux == to)
        {
            foundTo = true;
        }
        aux = aux->next;
    }

    if (!foundFrom || !foundTo)
    {
        return path;
    }

    from->Dijk = 0;
    if (from == to)
    {
        from->dijState = true;
        return path;
    }

    // Ciclo principal: buscar el nodo no visitado con menor distancia acumulada
    bool flag = true;
    while (flag)
    {
        NodeVertex* current = nullptr;
        aux = vertex.h;
        while (aux != nullptr)
        {
            if (aux->dijState == false && aux->Dijk < INT_MAX)
            {
                if (current == nullptr || aux->Dijk < current->Dijk)
                {
                    current = aux;
                }
            }
            aux = aux->next;
        }

        if (current == nullptr || current == to)
        {
            if (current != nullptr)
            {
                current->dijState = true;
            }
            flag = false;
        }
        else
        {
            current->dijState = true;

            // Revisamos todas las aristas del nodo actual
            NodeEdges* auxEdge = current->edges.h;
            while (auxEdge != nullptr)
            {
                NodeVertex* neighbor = auxEdge->direction;
                if (neighbor != nullptr && neighbor->dijState == false && auxEdge->weight >= 0)
                {
                    if (current->Dijk <= INT_MAX - auxEdge->weight)
                    {
                        int newDist = current->Dijk + auxEdge->weight;
                        // Solo se cambia si es estrictamente menor (un solo salto de predecesor)
                        if (newDist < neighbor->Dijk)
                        {
                            neighbor->Dijk = newDist;
                            neighbor->predecessor = current;
                        }
                    }
                }
                auxEdge = auxEdge->next;
            }
        }
    }

    // Reconstruimos los saltos minimos regresando desde 'to' hasta 'from'
    if (to->predecessor != nullptr)
    {
        NodeVertex* node = to;
        while (node != nullptr && node != from)
        {
            NodeVertex* prev = node->predecessor;
            if (prev == nullptr)
            {
                path.deleteAll();
                break;
            }

            // Buscamos el peso de la arista que va de prev a node
            int edgeWeight = 0;
            bool found = false;
            NodeEdges* auxEdge = prev->edges.h;
            while (auxEdge != nullptr)
            {
                if (auxEdge->direction == node)
                {
                    if (!found || auxEdge->weight < edgeWeight)
                    {
                        edgeWeight = auxEdge->weight;
                        found = true;
                    }
                }
                auxEdge = auxEdge->next;
            }

            // Como insert mete al inicio de la lista, queda ordenada de from -> to
            path.insert(node, edgeWeight);
            node = prev;
        }

        if (!path.IsEmpty())
        {
            path.setHeaviest();
        }
    }

    // Limpiamos los predecesores para no dejar punteros colgando si luego borran un vertice
    aux = vertex.h;
    while (aux != nullptr)
    {
        aux->predecessor = nullptr;
        aux = aux->next;
    }

    return path;
}

void Graph::runDijkstra()
{
    if (vertex.vertexNumber < 2)
    {
        cout << "Sucursales insuficientes para calcular un recorrido." << endl;
        return;
    }

    cout << "Imprimiendo lista actual de sucursales: " << endl;
    vertex.showAll();

    string name = "";
    NodeVertex* from = nullptr;
    NodeVertex* to = nullptr;

    while (from == nullptr)
    {
        cout << "Introduzca el nombre de la sucursal origen: ";
        getline(cin, name);
        from = vertex.searchingData(name);
        if (from == nullptr)
        {
            cout << "Sucursal no encontrada, intente de nuevo." << endl;
        }
    }

    while (to == nullptr)
    {
        cout << "Introduzca el nombre de la sucursal destino: ";
        getline(cin, name);
        to = vertex.searchingData(name);
        if (to == nullptr)
        {
            cout << "Sucursal no encontrada, intente de nuevo." << endl;
        }
    }

    if (from == to)
    {
        cout << "El origen y destino son la misma sucursal (" << from->nameSucursal
             << "). Distancia total: 0" << endl;
        return;
    }

    ListEdges path = Dijkstra(from, to);

    if (path.IsEmpty())
    {
        cout << "No existe una ruta dirigida desde " << from->nameSucursal
             << " hasta " << to->nameSucursal << "." << endl;
        return;
    }

    cout << endl << "Recorrido minimo:" << endl;
    cout << from->nameSucursal;
    NodeEdges* aux = path.h;
    while (aux != nullptr)
    {
        cout << " --(" << aux->weight << ")--> " << aux->direction->nameSucursal;
        aux = aux->next;
    }
    cout << endl << "Distancia total recorrida: " << to->Dijk << endl;
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
    cout << "Conexion agregada: " << from -> nameSucursal << " -> " << 
    to -> nameSucursal << " (Peso: " << weight << ")" << endl;
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
    NodeVertex* target = nullptr;
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

    cout << "Conexion eliminada correctamente" << endl;
} 


void Graph::printGraph()
{
    if(vertex.IsEmpty()){
        cout << "El grafo esta vacio, no hay sucursales registradas." << endl;
        return;
    }

    NodeVertex* aux = vertex.h;
    int cont = 0;

    while (aux != nullptr){
        cout << endl << "Sucursal No. " << cont <<": " << aux->nameSucursal << endl;
        cout << "Coordenadas: " << "X: " << aux -> x << " Y: " << aux -> y << endl;
        cout << "Telefono: " << aux->phone << endl;
        cout << "Horario: " << aux->schedule << endl;
        cout << "Conexiones salientes " << aux->edges.numEdges <<":"<<endl;


        if(aux -> edges.IsEmpty()){
            cout<< " -> Sin conexiones salientes. " << endl;
        } else {
            aux -> edges.showAll();
        }

        cout << endl << endl << endl;
        cont++;
        aux = aux -> next;
    }
    
}



Graph::~Graph()
{
    
}