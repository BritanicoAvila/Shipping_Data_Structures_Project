#ifndef LISTVERTEX_H
#define LISTVERTEX_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

// #include "NodeVertex.h"
class NodeVertex; //Declaración Adelantada

class ListVertex
{

        private:
                NodeVertex *h;
                int vertexNumber;   
        public:
                ListVertex();
                ~ListVertex();

                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //////////                                             Consultas                                        //////////
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                bool IsEmpty();
                void  showAll();
                NodeVertex* searchingData(std::string);

                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //////////                                             Operadores                                       //////////
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void insert();         
        void deleteAll();
        void deleteVertex(NodeVertex*);
        NodeVertex* fuller();            //Llena el nodo vertex
        int distanceCalculator (NodeVertex*, NodeVertex*);              //Calcula la distancia entre 2 nodos
        void balancerSetter(NodeVertex*);



                friend class ListEdges;
                friend class NodeEdges;
                friend class NodeVertex;
                friend class Graph;

};

#endif