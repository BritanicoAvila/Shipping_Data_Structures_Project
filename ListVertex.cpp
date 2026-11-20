#include "ListVertex.h"
#include <cstdlib>
#include <ctime>

ListVertex::ListVertex ()
{

}
        ListEdges edges;
        string nameSucursal;
        int x, y;
        string phone;
        string schedule;

NodeVertex ListVertex::fuller()
{
    Nodevertex ref;
    cout << endl << "Introduzca el nombre de la sucursal: "; 
    cin >> ref.nameSucursal;
    cout << endl << "Introduzca el numero telefonico de la sucursal: "; 
    cin >> ref.phone;
    cout << endl << "Introduzca el horario de la sucursal: "; 
    cin >> ref.schedule;
    srand(time(0));
    ref.x = rand();
    srand(time(0));
    ref.y = rand();
    
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
        cout << "Sucursal: " << cont << " -> " << jumper->direction->nameSucursal << endl;
        cont++;
        jumper = jumper -> next;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Operadores                                       //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ListVertex::insert(NodeVertex* directionA, int weight) // Direction ADD a la que apuntamos
{
    NodeVertex *tmp = new NodeVertex(directionA, weight);
    if (h)
    {
        tmp->next = h;
        h = tmp;
    }
    else 
    {
        h = tmp;
    }
    numEdges++;
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
        cout << "La sucursal ya no tiene conexiones" << endl;
    }
    else
    {
        cout << "No hay conexiones en la sucursal" << endl;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////