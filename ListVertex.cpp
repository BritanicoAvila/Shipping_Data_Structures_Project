#include "ListEdges.h"
#include "NodeEdges.h"
#include "NodeVertex.h"
#include "ListVertex.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

ListVertex::ListVertex()
{
    h = nullptr;
    vertexNumber = 0;
}

NodeVertex* ListVertex::fuller()  //Llena la informacion de una nueva sucursal y le da coordenadas random
{   
    int x=0, y=0;
    string nameSucursal, phone, schedule;
    //srand(time(0)) HAY QUE MOVER ESTO A MAIN;
    do
    {
        cout << endl << "Introduzca el nombre de la sucursal: "; 
        getline(cin, nameSucursal); 
        
        if (nameSucursal.empty())
        {
            cout << "El nombre no puede estar vacio." << endl;
        } 
        else if (h != nullptr && searchingData(nameSucursal) != nullptr)
        {
            cout << "Ya existe una sucursal con ese nombre, intente otro." << endl;
        }
        
    } while (nameSucursal.empty() || (h != nullptr && searchingData(nameSucursal) != nullptr));
    
    
    cout << endl << "Introduzca el numero telefonico de la sucursal: "; 
    getline(cin, phone);
    cout << endl << "Introduzca el horario de la sucursal: "; 
    getline(cin, schedule);
    

    while (x + y == 0)  //Para asegurar que las coordenadas (0,0) no se repitan
    {
        
        x = rand() % 500;
        y = rand() % 500;
    }
    
    NodeVertex *ref = new NodeVertex(nameSucursal, x, y, phone, schedule);
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
    if (IsEmpty()){
        cout << "No hay sucursales disponibles!";
        return;
    }

    NodeVertex *aux = h;
    int cont = 0;
    while (aux != nullptr)
    {   
        /*       
        string nameSucursal = "";
        int x, y;
        string phone = "";
        string schedule = "";
        */
        cout << "Sucursal No. " << cont << " : " << " -> " << aux -> nameSucursal << endl;
        cout << "Latitud: "  << aux -> y << endl;
        cout << "Longitud: "  << aux -> x << endl;
        cout << "Telefono de la sucursal: " << aux -> phone << endl;
        cout << "Horario de la sucursal: " << aux -> schedule << endl;
        
        cont++;
        aux = aux -> next;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                             Operadores                                       //////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ListVertex::insert() // Direction ADD a la que apuntamos
{
    NodeVertex *tmp = fuller();   //Llamamos a "llenador" para crear el nuevo objeto
    if (h)
    {
        tmp->next = h;
        h = tmp;
    }
    else 
    {
        h = tmp;   //Es el primer vertice y sus coordenadas deben de ser = 0
        h->x = 0;
        h->y = 0;
    }
    vertexNumber++;
}

void ListVertex::deleteVertex(NodeVertex* vertex){  //HEY, ESTA COSA DEBE ELIMINAR LAS ARISTAS QUE LO APUNTAN USANDO EL VECTOR DE DIRECCIONES
    if (IsEmpty() or vertex == nullptr){
        cout << "No se encontro sucursal";
        return;
    }

    NodeVertex* aux = h;

    if (vertex == h)
    {
        h = h -> next;
        delete aux;
        vertexNumber--;
    }
    else
    {
        NodeVertex* tmp = nullptr;
        while (aux != nullptr and aux != vertex)
        {
            tmp = aux;
            aux = aux -> next;
        }

        if (aux == vertex)
        {
            tmp -> next = aux -> next;

            delete aux;
            vertexNumber--;
        }
    }
}

void ListVertex::deleteAll()
{
    if (IsEmpty()){
        cout << "No hay sucursales disponibles!";
        return;
    }

    NodeVertex *tmp = h;
        while (h)
        {
            h = h -> next;
            delete tmp;
            tmp = h;
        }
        vertexNumber = 0;
        cout << "La lista de sucursales ha sido eliminada" << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ListVertex::distanceCalculator (NodeVertex* actN, NodeVertex* newN)              //Calcula la distancia
{   
    double distance=0;                        //Catetos
    if (actN != nullptr and newN != nullptr){
        
        double deltaX, deltaY;

        deltaX = newN -> x - actN -> x;
        deltaY = newN -> y - actN -> y;

        distance = sqrt((deltaX * deltaX) + (deltaY * deltaY));   
    }
    return distance;
}

void ListVertex::balancerSetter(NodeVertex* node)                                                                            
    {                                                                                                                            
        if (node == nullptr || h == nullptr)                                                                                     
        {                                                                                                                        
            return;                                                                                                              
        }                                                                                                                        
                                                                                                                                 
        NodeVertex* aux = h;                                                                                                     
        while (aux != nullptr)                                                                                                   
        {                                                                                                                        
            if (aux != node)                                                                                                     
            {                                                                                                                    
                int dist = distanceCalculator(node, aux);                                                                        
                                                                                                                                 
                // 1) Ajustar aristas salientes de 'node' hacia 'aux'                                                            
                if (!node->edges.hasEdge(aux))                                                                                   
                {                                                                                                                
                    if (node->edges.numEdges < 4)                                                                                
                    {                                                                                                            
                        node->edges.insert(aux, dist);                                                                           
                        node->edges.setHeaviest();                                                                               
                    }                                                                                                            
                    else if (dist < node->edges.heaviest)                                                                        
                    {                                                                                                            
                        node->edges.deleteHeaviest();                                                                            
                        node->edges.insert(aux, dist);                                                                           
                        node->edges.setHeaviest();                                                                               
                    }                                                                                                            
                }                                                                                                                
                                                                                                                                 
                // 2) Ajustar aristas salientes de 'aux' hacia 'node'                                                            
                if (!aux->edges.hasEdge(node))                                                                                   
                {                                                                                                                
                    if (aux->edges.numEdges < 4)                                                                                 
                    {                                                                                                            
                        aux->edges.insert(node, dist);                                                                           
                        aux->edges.setHeaviest();                                                                                
                    }                                                                                                            
                    else if (dist < aux->edges.heaviest)                                                                         
                    {                                                                                                            
                        aux->edges.deleteHeaviest();                                                                             
                        aux->edges.insert(node, dist);                                                                           
                        aux->edges.setHeaviest();                                                                                
                    }                                                                                                            
                }                                                                                                                
            }                                                                                                                    
            aux = aux->next;                                                                                                     
        }                                                                                                                        
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

NodeVertex* ListVertex::getLighter(NodeVertex* sucursal)  //Devuelve la sucursal 
{
    if(sucursal == nullptr || h == nullptr)
    {
        return nullptr;
    }

    NodeVertex *actN = h;             //DEVUELVE LA SUCURSAL MAS CERCANA A LA PASADA POR REFERENCIA
    NodeVertex *ref = nullptr;
    int minDist = 0;
    // bool found = true;
    
        while (actN != nullptr)
        {
            if (actN != sucursal && !sucursal -> edges.hasEdge(actN))
            {
                int dist = distanceCalculator(sucursal, actN);
                if (ref == nullptr || dist < minDist)
                {
                    ref = actN;
                    minDist = dist;
                }
                
                // ref = actN;
                // found = false;
            }
            actN = actN -> next;
        }
        //     else if (ref->edges.heaviest > actN->edges.heaviest && !sucursal->edges.hasEdge(actN) && !found && actN != sucursal) //Si ya tenemos un valor de referenca y encontramos un nodo mas cercano lo cambiamos
        //     {
        //     ref = actN;
        //     }
        // actN = actN->next;
        // }
    return ref;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ListVertex::generalBalancer()
{
    if (h == nullptr || vertexNumber <= 4) return;

    NodeVertex* actN = h;

    while (actN != nullptr)
    {
        while (actN -> edges.numEdges < 4)
        {
            NodeVertex* target = getLighter(actN);
            if(target == nullptr) break;

            actN -> edges.insert(target, distanceCalculator(actN, target));
            actN -> edges.setHeaviest();
        }
        actN = actN -> next;
    }
    
} 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

NodeVertex* ListVertex::searchingData(string name)            //Retorna puntero de NodeV buscandolo con el nombre de la Sucursal
{
    NodeVertex *ref = h;
    bool flag = true;
    if (h)
        {
            while (ref && flag)
            {
                if (ref->nameSucursal == name)
                {
                    flag = false;
                }
                else
                {
                    ref=ref->next;
                }
            }
        }
    else 
    {
        cout << "La lista de sucursales esta vacia" << endl;
    }

    return ref;
}

ListVertex::~ListVertex(){
    if(!IsEmpty()){
        deleteAll();
    }
}