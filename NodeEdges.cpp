#include "ListEdges.h"
#include "NodeEdges.h"
#include "NodeVertex.h"
#include <iostream>

NodeEdges::NodeEdges()
{
    next = nullptr;
    direction = nullptr;
}

NodeEdges::NodeEdges(NodeVertex* direction)
{
    next = nullptr;
    this->direction=direction;
    weight = 0;
}
NodeEdges::NodeEdges(NodeVertex* direction, int weight)
{
    next = nullptr;
    this->direction=direction;
    this->weight = weight;
}
NodeEdges::NodeEdges(int weight, NodeEdges* next, NodeVertex* direction)
{
    this->weight=weight;
    this->next=next;
    this->direction=direction;
}

NodeEdges::~NodeEdges()
{
//dtor
}