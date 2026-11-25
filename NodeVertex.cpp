#include "ListEdges.h"
#include "NodeEdges.h"
#include "NodeVertex.h"

NodeVertex::NodeVertex(){
    next = nullptr;
    nameSucursal = "";
    //funcionSiEsElUnicoNodo()
    phone = "";
    schedule = "";
    x = 0;
    y = 0;
    Dijk=0;
    dijState=false;
    predecessor = nullptr;
}

NodeVertex::NodeVertex(string nameSucursal, int x, int y, string phone, string schedule)
{
    this -> nameSucursal = nameSucursal;
    this -> x = x;
    this -> y = y;
    this -> phone = phone;
    this -> schedule = schedule;
    next = nullptr;
    Dijk=0;
    dijState=false;
    predecessor = nullptr;
}

NodeVertex::~NodeVertex()
{
    //dtor
}