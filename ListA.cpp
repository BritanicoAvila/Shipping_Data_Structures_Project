#include "ListA.h"

using std::cout;
using std::endl;

ListA::ListA() {
    h = nullptr;
    numAristas = 0;               //Numero de aristas :D
    heaviest = 0;                 //Arista mas pesada
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Consultas                                        //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool ListA::IsEmpty()
{
    bool flag = true;
    if (h){
        flag = false;
    }
    return flag;
}
void ListA::showAll()
{
    NodeA *jumper = h;
    int cont = 0;
    while (!jumper)
    {   //Apuntamos a la parte direccion (al nodoV) y extraemos los datos que necesitemos
        cout << "Sucursal: " << cont << " -> " << jumper->direction->nameSucursal << endl;
        cont++;
        jumper = jumper->sig;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Operadores                                       //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ListA::insert(NodeV* directionA, int weight) // Direction ADD a la que apuntamos
{
    NodeA *tmp = new NodeA(directionA, weight);
    if (h)
    {
        tmp->sig = h;
        h = tmp;
    }
    else 
    {
        h = tmp;
    }
    numAristas++;
}
void ListA::deleteAll()
{
    NodeA *tmp = h;
    if (h)
    {
        while (h)
        {
            h=h->sig;
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

void ListA::deleteEdges(NodeV* directionD)  //Direction to Delete
{
    NodeA *tmp = new NodeA(directionD);
    NodeA *jumper = h, *jumperBefore=nullptr;
    bool flag = true;
    if (h)
    {
        while (jumper && flag)
        {
            if (tmp->direction == jumper->direction)
            {
                tmp=jumper;   //Debido a que jumper saltara la siguiente posicion
                flag = false;
            }
            if (flag) //jumper1 = jumper->ant ... asi solo se actualiza si no se ha encontrado el nodo buscado
            {
                jumperBefore = jumper;
            }
            
            jumper = jumper -> sig;  //Jumper salta +1 aunque flag = false
        }


        if (tmp = h) //0x
        {
            h = tmp->sig;
            delete tmp;
        }
        else if (flag)  // Si flag = true, entonces la direccion no existe
        {
            cout << "Conexion no encontrada..." << endl;
        }
        else 
        {
            jumperBefore->sig = tmp->sig;
            delete tmp;
        }
    }
    else 
    {
        cout << "La sucursar analizada no tiene conexiones" << endl;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

NodeV* ListA::buscarDato(string name)            //Retorna puntero de NodeV buscandolo con el nombre de la Sucursal
{
    NodeA *aux = h;
    NodeV *ref = nullptr;
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

            aux=aux->sig;
            }
        }
    else 
        {
        cout << "La sucursal no tiene ninguna conexion" << endl;
        }

    return ref;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ListA::setHeaviest()        //Acctualiza la arista mas pesada
{
    int heaviest=0;
    if (h)
        {  
        NodeA *aux = h;
        heaviest = h->weight;
            while (aux)                   //Recorremos todas las aristas
            {
            if (heaviest < aux->weight)   //Para actualizar heaviest si se ocupa
            {
            heaviest = aux->weight;
            }
            aux = aux->sig;
            }
        }
        else 
        {
        cout << "La sucursal no tiene conexiones" << endl;
        }
    return heaviest; 
}


ListA::~ListA()
{
//dtor
}