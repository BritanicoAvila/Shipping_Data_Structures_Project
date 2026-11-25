#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Graph.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    srand(time(0));

    Graph graph;
    int option = 0;

    do {
        cout << endl;
        cout << "1) Insertar vertice" << endl;
        cout << "2) Insertar arista" << endl;
        cout << "3) Eliminar vertice" << endl;
        cout << "4) Eliminar arista" << endl;
        cout << "5) Imprimir listado de vertice/arista" << endl;
        cout << "6) Realizar un recorrido minimo (Dijkstra)" << endl;
        cout << "7) Salir" << endl;
        cout << "Ingrese una opcion: ";

        if (!(cin >> option)) {
            if (cin.eof()) {
                break;
            }
            cin.clear();
            option = 0;
        }
        cin.ignore(10000, '\n');

        switch (option) {
            case 1:
                graph.newVertex();
                break;
            case 2:
                graph.newEdge();
                break;
            case 3:
                graph.deleteVertex();
                break;
            case 4:
                graph.deleteEdge();
                break;
            case 5:
                graph.printGraph();
                break;
            case 6:
                graph.runDijkstra();
                break;
            case 7:
                cout << "¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    } while (option != 7);

    return 0;
}
