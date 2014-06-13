#include <iostream>
#include <winbgim.h>
#include "Grafo.h"
#include "LinkedList.h"


using namespace std;

int main()
{
    cout << "Labyrint application" << endl;

    //prueba grafos
    Grafo <int> * g = new Grafo<int>(0);
    int dim = 3;
    for (int i = 1; i <= (dim*dim); i++)
    {
        g->agregarVertice(i);
    }
    /*g->agregarVertice(1);
    g->agregarVertice(2);
    g->agregarVertice(3);
    g->agregarVertice(4);
    */
    g->llenarGrafo(dim);
    /*
    g->agregarArista(1, 2);
    g->agregarArista(2, 3);
    g->agregarArista(3, 4);
    g->agregarArista(1,3);
    g->agregarArista(2, 4);
    g->agregarArista(4, 4);
    */
    //cout << "el tamano es " << g->getTamano() << endl;
    cout << "la lista de adyacencia es: " << endl;
    g->imprimirListAd();

    //ventana
    initwindow (600,400);
    getch();
    closegraph();
    return 0;
}
