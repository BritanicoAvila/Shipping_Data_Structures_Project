#include "ListEdges.h"
#include "NodeEdges.h"
#include "NodeVertex.h"

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
    if (IsEmpty()){
        cout << "No hay sucursales disponibles!";
        return;
    }

    NodeEdges* aux = h;
    int cont = 0;
    while (aux != nullptr)
    {   //Apuntamos a la parte direccion (al nodoV) y extraemos los datos que necesitemos
        cout << "Sucursal No." << cont << " : -> " << aux->direction->nameSucursal << endl;
        cout << "Peso: " << aux -> weight << endl;
        cont++;
        aux = aux -> next;
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


    if(numEdges == 1 || weight > heaviest){
        heaviest = weight;
    }

}
void ListEdges::deleteAll()
{
    if (IsEmpty()){
        return;
    }

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
        numEdges = 0;
        heaviest = 0;
    }
    else
    {
        cout << "No hay conexiones en la sucursal" << endl;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ListEdges::deleteEdges(NodeVertex* directionD)  //Direction to Delete
{
    if (IsEmpty() or directionD == nullptr){
        cout << "No se encontro sucursal";
        return;
    }
    NodeEdges* aux = h;
    bool deleted = false;

    if (directionD == h -> direction)
    {
        h = h -> next;
        delete aux;
        numEdges--;
        deleted = true;
    }
    else
    {
        NodeEdges* tmp = nullptr;
        while (aux != nullptr and aux -> direction != directionD)
        {
            tmp = aux;
            aux = aux -> next;
        }

        if (aux != nullptr and aux -> direction == directionD)
        {
            tmp -> next = aux -> next;

            delete aux;
            numEdges--;
            deleted = true;
        }
    }

    if (deleted)
    {
        if(!IsEmpty()){
            setHeaviest();
        }else{
            heaviest = 0;
        }
    }
    else {
        cout << "Conexion no encontrada..." << endl;
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

bool ListEdges::hasEdge(NodeVertex* target)
{
    if (target == nullptr)
    {
        return false;
    }

    NodeEdges* aux = h;
    while (aux != nullptr)
    {
        if (aux->direction == target)
        {
            return true;
        }
        aux = aux->next;
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ListEdges::setHeaviest()        //Acctualiza la arista mas pesada
{
    heaviest = 0;
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

void ListEdges::deleteHeaviest()
{
    if (IsEmpty())
    {
        return;
    }

    NodeEdges* aux = h;
    NodeEdges* heaviestEdge = h;
    while (aux != nullptr)
    {
        if (aux->weight > heaviestEdge->weight)
        {
            heaviestEdge = aux;
        }
        aux = aux->next;
    }

    deleteEdges(heaviestEdge->direction);
    if (!IsEmpty())
    {
        setHeaviest();
    }
    else
    {
        heaviest = 0;
    }
}


ListEdges::~ListEdges()
{
    deleteAll();
}