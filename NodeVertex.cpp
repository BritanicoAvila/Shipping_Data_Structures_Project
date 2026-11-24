#include "ListEdges.h"
#include "NodeEdges.h"
#include "NodeVertex.h"

NodeVertex::NodeVertex(){
    next = nullptr;
    nameSucursal = "";
    //funcionSiEsElUnicoNodo()
    phone = "";
    schedule = "";
}

NodeVertex::NodeVertex(string nameSucursal, int x, int y, string phone, string schedule, NodeVertex* next, ListEdges){
    this -> nameSucursal = nameSucursal;
    this -> x = x;
    this -> y = y;
    this -> phone = phone;
    this -> schedule = schedule;

    this -> next = next;
}

NodeVertex::NodeVertex(string nameSucursal, int x, int y, string phone, string schedule)
{
    this -> nameSucursal = nameSucursal;
    this -> x = x;
    this -> y = y;
    this -> phone = phone;
    this -> schedule = schedule;
    next = nullptr;
    edges;
}

NodeVertex::~NodeVertex()
{
    //dtor
}