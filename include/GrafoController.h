#ifndef GRAFOCONTROLLER_H
#define GRAFOCONTROLLER_H
#include "Grafo.h"
#include "Vertice.h"

class GrafoController
{
    private:
        Grafo <int> * grafoLleno;
        Grafo <int> * laberinto;
        LinkedList <Vertice <int> > * vertices;
        LinkedList<Vertice<int> > * vecinos;
        LinkedList<Vertice<int> > * visitados;
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
                laberinto->agregarVertice(i);
            }
            llenarGrafo(dim);
            cout << "la lista de adyacencia es: " << endl;
            //grafoLleno->imprimirListAd();
            vertices = grafoLleno->getVertices();
            visitados = new LinkedList<Vertice<int> >();
            cout << "se lleno el grafo" << endl;
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

        void DFS(Grafo g)
        {
            int n = 0;
            Vertice <int> * vertice1;
            vertice1 = vertices->getElementInPos(n);
            vertice1->setVisit();
            visitados->insert(vertice1);
            n++;
            DFSRec(vertice1);
        }

        void DFSRec(Vertice <int> * vertice1, int n)
        {
            vecinos = obtenerListaNoVisit(vertice1);
            Vertice <int> * vertice2;
            vertice2 = obtenerAzar(vecinos);
            vertice2->setVisit();
            laberinto->agregarArista(vertice1, vertice2);
            laberinto->agregarArista(vertice2, vertice1);
            vertice1 = vertice2;
            n++;
            if (n < vertices->getSize())
            {
                DFSRec(vertice1, n)
            }
        }

        LinkedList <Vertice<int> > * obtenerListaNoVisit(Vertice<int> * ve, LinkedList <Vertice<int> > * todosVec)
        {

        }

        Vertice<int> obtenerAzar(LinkedList <Vertice<int> > * vecinos)
        {

        }

        /*
            //LinkedList<Vertice<int> >::imprimirLista(vecinos);   //Imprime lista de vecinos
            //DFS_Aux(vecinos, visitados, vertices);
            for (int i = 0; i <= g.getCantVe(); i++)
            {
                vecinos->append(vertices->getElementInPos(i));
                vecinos = grafoLleno->obtenerVecinos(vertices->getElementInPos(i));
                Vertice<int> * vert = new Vertice<int>(vertices->getElementInPos(i)));
                vert->setVisit();
                visitados->append(&vert);
                obtenerListaNoVisit(vert, vecinos);

            }void
        DFS_Aux(LinkedList<Vertice<int> > * vecinos, LinkedList<Vertice<int> > * visitados, LinkedList <Vertice <int> > * vertices )
        {

        }*/

};

#endif // GRAFOCONTROLLER_H
