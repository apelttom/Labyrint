#ifndef GRAFOCONTROLLER_H
#define GRAFOCONTROLLER_H
#include "Grafo.h"
#include "Vertice.h"

class GrafoController
{
    private:
        Grafo <int> * grafoLleno;
        Grafo <int> * laberinto;
    public:
        GrafoController()
        {
            grafoLleno = new Grafo<int>();
            laberinto = new Grafo<int>();
        }
        ~GrafoController() {}

        void inicializarGrafo(int dim)
        {
            for (int i = 1; i <= (dim*dim); i++)
            {
                grafoLleno->agregarVertice(i);
            }
            llenarGrafo(dim);
            cout << "la lista de adyacencia es: " << endl;
            grafoLleno->imprimirListAd();
        }

        void llenarGrafo(int dim)
        {
            for (int i = 0; i < dim * dim; i++)
            {
                Vertice <int> tmp = grafoLleno->getVertices()->getElementInPos(i);
                int x = tmp.getValor();
                if (x % dim != 0)
                {
                    grafoLleno->agregarArista(x, (x+1));
                    grafoLleno->agregarArista((x+1), x);
                }
                if ((x+dim) <= (dim*dim))
                {
                    grafoLleno->agregarArista(x, (x+dim));
                    grafoLleno->agregarArista((x+dim), x);
                }
            }
        }

};

#endif // GRAFOCONTROLLER_H
