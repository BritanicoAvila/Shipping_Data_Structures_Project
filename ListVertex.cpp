#include "NodeEdges.h"
#include "NodeVertex.h"
#include "ListEdges.h"
#include "ListVertex.h"
#include "Graph.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

ListVertex::ListVertex ()
{
NodeVertex *h = nullptr;
int vertexNumber = 0;
}

NodeVertex* ListVertex::fuller()
{
    int x, y;
    string nameSucursal, phone, schedule;
    cout << endl << "Introduzca el nombre de la sucursal: "; 
    cin >> nameSucursal;
    cout << endl << "Introduzca el numero telefonico de la sucursal: "; 
    cin >> phone;
    cout << endl << "Introduzca el horario de la sucursal: "; 
    cin >> schedule;
    srand(time(0));
    x = rand();
    srand(time(0));
    y = rand();
    NodeVertex *ref = new NodeVertex();
    return ref;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Consultas                                        //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool ListVertex::IsEmpty()
{
    bool flag = true;
    if (h){
        flag = false;
    }
    return flag;
}
void ListVertex::showAll()
{
    NodeVertex *jumper = h;
    int cont = 0;
    while (!jumper)
    {   //Apuntamos a la parte direccion (al nodoV) y extraemos los datos que necesitemos
         cout << "Sucursal: " << cont << " -> " << jumper->nameSucursal << endl;
        cont++;
        jumper = jumper -> next;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Operadores                                       //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ListVertex::insert() // Direction ADD a la que apuntamos
{
    NodeVertex *tmp = fuller();
    if (h)
    {
        tmp->next = h;
        h = tmp;
    }
    else 
    {
        h = tmp;
        h->x = 0;
        h->y = 0;
    }
    vertexNumber++;
}

void ListVertex::deleteAll()
{
    NodeVertex *tmp = h;
    if (h)
    {
        while (h)
        {
            h=h->next;
            delete tmp;
            tmp=h;
        }
        cout << "La lista de sucursales ha sido eliminada" << endl;
    }
    else
    {
        cout << "La lista de sucursales ya estaba vacia" << endl;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////