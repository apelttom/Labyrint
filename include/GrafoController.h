#ifndef GRAFOCONTROLLER_H
#define GRAFOCONTROLLER_H
#include "Grafo.h"
#include "Vertice.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

        Grafo <int> * getGrafoLleno() const
        {
            return grafoLleno;
        }

        void inicializarGrafo(int dim)
        {
            for (int i = 1; i <= (dim*dim); i++)
            {
                grafoLleno->agregarVertice(i);
                laberinto->agregarVertice(i);
            }
            llenarGrafo(dim);
            //cout << "la lista de adyacencia es: " << endl;
            //grafoLleno->imprimirListAd();
            vertices = grafoLleno->getVertices();
            visitados = new LinkedList<Vertice<int> >();
            cout << "se lleno el grafo" << endl;
            DFS();
            cout << "se lleno el segundo grafo" << endl;
            laberinto->imprimirListAd();
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

        void DFS()
        {
            int n = 0;
            Vertice <int> vertice1;
            vertice1 = vertices->getElementInPos(n);
            vertice1.setVisit();
            visitados->insert(vertice1);
            n++;
            DFSRec(vertice1, n);
            cout << "Despues de DFSREC" << endl;
        }

        void DFSRec(Vertice <int> vertice1, int n)
        {
            cout << "Entro a DFSREC" << endl;
            vecinos = obtenerListaNoVisit(vertice1);
            Vertice <int> vertice2;
            if (vecinos->getSize() > 0)
            {
                cout << "Entro a if de DFSREC" << endl;
                vertice2 = obtenerAzar(vecinos);
                vertice2.setVisit();
                laberinto->agregarArista(vertice1.getValor(), vertice2.getValor());
                laberinto->agregarArista(vertice2.getValor(), vertice1.getValor());
                vertice1 = vertice2;
                n++;
                if (n < vertices->getSize())
                {
                    DFSRec(vertice1, n);
                }
            }
        }

        LinkedList <Vertice<int> > * obtenerListaNoVisit(Vertice<int> ve /*, LinkedList <Vertice<int> > * todosVec*/)
        {
            LinkedList <Vertice <int> > * tmp;
            tmp = grafoLleno->obtenerVecinos(ve);
            LinkedList <Vertice<int> > * noVisitados = new LinkedList<Vertice<int> >();
            if (tmp->getSize() == 0)
            {
                return noVisitados;
            }
            else
            {
                for (int i = 0; i < tmp->getSize(); i++)
                {
                    Vertice<int> vertmp;
                    vertmp = tmp->getElementInPos(i);
                    if(vertmp.getEstado() == false)
                    {
                        noVisitados->append(vertmp);
                    }
                }
            }
            delete tmp;
            return noVisitados;
        }

        Vertice<int> obtenerAzar(LinkedList <Vertice<int> > * vecinos)
        {
            Vertice<int> vertice;
            if (vecinos->getSize() == 1)
            {
                return vecinos->getElementInPos(0);
            }
            else
            {
                if (vecinos->getSize() == 2)
                {
                    int prob = getRandom();
                    if (prob < 50)
                    {
                        vertice = vertices->getElementInPos(0);
                        return vertice;
                    }
                    else
                    {
                        vertice = vertices->getElementInPos(1);
                        return vertice;
                    }
                }
                else
                {
                    if (vecinos->getSize() == 3)
                    {
                        int prob = getRandom();
                        if (prob <= 33)
                        {
                            vertice = vertices->getElementInPos(0);
                            return vertice;
                        }
                        else
                        {
                            if (prob <= 66)
                            {
                                vertice = vertices->getElementInPos(1);
                                return vertice;
                            }
                            else
                            {
                                vertice = vertices->getElementInPos(2);
                                return vertice;
                            }
                        }
                    }
                }
            }
        }

        int getRandom()
        {
            int  i;
            srand(time(NULL));
            i = (1 + (rand() % 100));
            return i;
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
