#include <iostream>
#include "GrafoController.h"
#include "GraphPrinter.h"


using namespace std;

int main()
{
    cout << "Labyrint application" << endl;

    //prueba grafos
    int dim = 0;
    cout << "Digite la dimension que desea para el laberinto " << endl;
    cin >> dim;

    GrafoController * controller = new GrafoController();
    controller->inicializarGrafo(dim);
    /*g->agregarVertice(1);
    g->agregarVertice(2);
    g->agregarVertice(3);
    g->agregarVertice(4);
    */
    //g->llenarGrafo(dim);
    /*
    g->agregarArista(1, 2);
    g->agregarArista(2, 3);
    g->agregarArista(3, 4);
    g->agregarArista(1,3);
    g->agregarArista(2, 4);
    g->agregarArista(4, 4);
    */

    GraphPrinter *  printer = new GraphPrinter();
    printer->drawGraph(NULL);
    delete printer;

    //ventana
    //initwindow (600,400);
    //getch();
    //closegraph();
    return 0;
}
