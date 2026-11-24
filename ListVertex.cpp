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
    //srand(time(0)) HAY QUE MOVER ESTO A MAIN;
    string nameSucursal, phone, schedule;
    cout << endl << "Introduzca el nombre de la sucursal: "; 
    getline(cin, nameSucursal);    
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
    double distance=0, catx=0, caty=0;                        //Catetos
    if (actN != nullptr and newN != nullptr){
        
        double deltaX, deltaY;

        deltaX = newN -> x - actN -> x;
        deltaY = newN -> y - actN -> y;

        distance = sqrt((deltaX * deltaX) + (deltaY * deltaY));   
    }
    return distance;
    
    // bool difSignx = (actN->x*newN->x < 0) ? true : false;  //Para saber si son de signos diferentes o iguales 
    // bool difSigny = (actN->y*newN->y < 0) ? true : false;  //Para saber si son de signos diferentes o iguales


    // catx = (difSignx) ? actN->x + actN->x : actN->x + actN->x*-1;   //Para restar y encontrar la diferencia
    // caty = (difSigny) ? actN->y + actN->y : actN->y + actN->y*-1;   //Para restar y encontrar la diferencia

    // catx = (catx < 0) ? catx*-1 : catx;    //Para que la raiz nunca sea negativa
    // caty = (caty < 0) ? caty*-1 : caty;    //Para que la raiz nunca sea negativa

    // if (actN->x != newN->x && actN->y != newN->y)    //Si no son paralelos tenemos que usar pitagoras
    // {
    // distance = static_cast<int>(std::sqrt((catx*catx)+(caty*caty)));
    // }
    // else   //Si son paralelos solo usamos una suma (pq uno de los dos catetos = 0)
    // {
    // distance = catx + caty;
    // }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ListVertex::balancerSetter(NodeVertex* node)     //Balancea los nuevos nodos (les pone aristas)
{
    if (node == nullptr || h == nullptr)
    {
        return;
    }

    NodeVertex* aux = h;
    while (aux != nullptr)
    {
        if (aux != node && !node->edges.hasEdge(aux))   //Evita auto-aristas y aristas duplicadas
        {
            int dist = distanceCalculator(node, aux);
            if (node->edges.numEdges < 4)
            {
                node->edges.insert(aux, dist);          //Agregamos a la lista de aristas
                node->edges.setHeaviest();              //Actualizamos la arista con mayor peso
            }
            else if (dist < node->edges.heaviest)       //Si es mas cercana que la arista mas pesada actual
            {
                if (distanceCalculator(node, aux) < aux->edges.heaviest)  //Para actualizar las sucursales si se necesita tambien
                {
                    aux->edges.insert(aux, distanceCalculator(node, aux));  //Agregamos a la lista de aristas
                    aux->edges.deleteEdges(aux);                            //Eliminamos arista con mayor peso
                }
                node->edges.insert(aux, distanceCalculator(node, aux));  //Agregamos a la lista de aristas
                node->edges.deleteEdges(node);      //Actualizamos la arista con mayor peso
            }
        }
        aux = aux->next;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

NodeVertex* ListVertex::getLighter(NodeVertex* sucursal)  //Devuelve la sucursal 
{
    NodeVertex *actN = h;             //DEVUELVE LA SUCURSAL MAS CERCANA A LA PASADA POR REFERENCIA
    NodeVertex *ref = nullptr;
    bool found = true;
    
        while (actN)
        {
            if (!sucursal->edges.hasEdge(actN) && found && actN != sucursal)    //Si no es una arista ya
            {
            ref = actN;
            found = false;
            }
            else if (ref->edges.heaviest > actN->edges.heaviest && !sucursal->edges.hasEdge(actN) && !found && actN != sucursal) //Si ya tenemos un valor de referenca y encontramos un nodo mas cercano lo cambiamos
            {
            ref = actN;
            }
        actN = actN->next;
        }
    return ref;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ListVertex::generalBalancer()
{
    NodeVertex *actN = h;
    if (h && vertexNumber > 4)   //Tiene el enfoque de balancear tras una eliminacion ¿como balanceamos si no hay suficientes vetices?
    {
        while (actN)    //AVANZA TODA LA LISTA DE VERTICES, Y SI UNO NO TIENE 4 ARISTAS LE ASIGNA UNA
        {
            if (actN->edges.numEdges < 4)   //Si este nodo tiene menos de 4 aristas
            {
            actN->edges.insert(getLighter(actN), distanceCalculator(actN, getLighter(actN)));  //NI PREGUNTE ... asigna una nueva arista, que se enlaza automaticamente al nodo mas cercano
            }
        actN = actN->next;
        }
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