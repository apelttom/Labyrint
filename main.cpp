
#include <iostream>
#include "include/Grafo.h"
#include "include/GrafoController.h"
#include "include/GraphDrawer.h"

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

    GraphDrawer *  printer = new GraphDrawer();
    printer->drawGraph(dim, controller->getGrafoLleno());
    delete printer;

    //ventana
//    initwindow (600,400);
//    rectangle(0,0,20,20);
//    getch();
//    closegraph();
    return 0;
}
