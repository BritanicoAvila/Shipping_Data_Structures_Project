#include "NodeA.h"
#include <iostream>

NodeA::NodeA()
{
sig = nullptr;
direction = nullptr;
}
NodeA::~NodeA()
{
//dtor
}
NodeA::NodeA(NodeV* direction)
{
sig = nullptr;
this->direction=direction;
weight = 0;
}
NodeA::NodeA(int weight, NodeA* sig, NodeV* direction)
{
this->weight=weight;
this->sig=sig;
this->direction=direction;
}