#include "ListEdges.h"

using std::cout;
using std::endl;

ListEdges::ListEdges() {
    h = nullptr;
    numEdges = 0;               //Numero de aristas :D
    heaviest = 0;                 //Arista mas pesada
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Consultas                                        //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool ListEdges::IsEmpty()
{
    bool flag = true;
    if (h){
        flag = false;
    }
    return flag;
}
void ListEdges::showAll()
{
    NodeEdges *jumper = h;
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

void ListEdges::insert(NodeVertex* directionA, int weight) // Direction ADD a la que apuntamos
{
    NodeEdges *tmp = new NodeEdges(directionA, weight);
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
void ListEdges::deleteAll()
{
    NodeEdges *tmp = h;
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

void ListEdges::deleteEdges(NodeVertex* directionD)  //Direction to Delete
{
    NodeEdges *tmp = new NodeEdges(directionD);
    NodeEdges *jumper = h, *jumperBefore=nullptr;
    bool flag = true;
    if (h)
    {
        while (jumper && flag)
        {
            if (tmp->direction == jumper->direction)
            {
                tmp=jumper;   //Debido a que jumper saltara la nextuiente posicion
                flag = false;
            }
            if (flag) //jumper1 = jumper->ant ... asi solo se actualiza si no se ha encontrado el nodo buscado
            {
                jumperBefore = jumper;
            }
            
            jumper = jumper -> next;  //Jumper salta +1 aunque flag = false
        }


        if (tmp = h) //0x
        {
            h = tmp->next;
            delete tmp;
        }
        else if (flag)  // Si flag = true, entonces la direccion no existe
        {
            cout << "Conexion no encontrada..." << endl;
        }
        else 
        {
            jumperBefore->next = tmp->next;
            delete tmp;
        }
    }
    else 
    {
        cout << "La sucursar analizada no tiene conexiones" << endl;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

NodeVertex* ListEdges::searchingData(string name)            //Retorna puntero de NodeV buscandolo con el nombre de la Sucursal
{
    NodeEdges *aux = h;
    NodeVertex *ref = nullptr;
    bool flag = true;
    if (h)
        {
            while (aux && flag)
            {
                if (aux->direction->nameSucursal == name)
                {
                ref = aux->direction;
                flag = false;
                }

            aux=aux->next;
            }
        }
    else 
        {
        cout << "La sucursal no tiene ninguna conexion" << endl;
        }

    return ref;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ListEdges::setHeaviest()        //Acctualiza la arista mas pesada
{
    int heaviest=0;
    if (h)
        {  
        NodeEdges *aux = h;
        heaviest = h->weight;
            while (aux)                   //Recorremos todas las aristas
            {
            if (heaviest < aux->weight)   //Para actualizar heaviest si se ocupa
            {
            heaviest = aux->weight;
            }
            aux = aux->next;
            }
        }
        else 
        {
        cout << "La sucursal no tiene conexiones" << endl;
        }
    return heaviest; 
}


ListEdges::~ListEdges()
{
    //dtor
}