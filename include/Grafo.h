#ifndef GRAFO_H
#define GRAFO_H
#include "Vertice.h"
#include "Arista.h"
#include "LinkedList.h"
#include <iostream>

template <typename E>
class Grafo
{
    private:
        int cantVertices;
        LinkedList<Vertice<E> > * vertices;
        LinkedList<Arista<E> > * aristas;
        int tamano;
        int cantAristas;

    public:
        Grafo()
        {

        }
        Grafo (int tam)
        {
            vertices = new LinkedList<Vertice<E> >();
            aristas = new LinkedList<Arista<E> >();
            tamano = tam;
            cantVertices = 0;
            cantAristas = 0;
        }
        /*
        Grafo ()
        {
            vertices = new LinkedList<E>();
            aristas = new LinkedList<E>();
            tamano = 0;
            cantVertices = 0;
            cantAristas = 0;
        }*/

        ~Grafo() {}

        void getTamano()
        {
            return tamano;
        }

        void setTamano(int tam)
        {
            tamano = tam;
        }

        int getCantVe()
        {
            return cantVertices;
        }

        LinkedList<Vertice<E> > * getVertices() const
        {
            return vertices;
        }

        E insertarVertice(Vertice<E> vert)
        {
            vertices.insert(vert);
            tamano ++;
            cantVertices++;
        }

        void agregarVertice (E dato)
        {
            Vertice<E> * vert = new Vertice<E>();
            vert->setValor(dato);
            vertices->append(*vert);
            cantVertices++;
            tamano++;
        }

        E eliminarVertice(Vertice<E> vert)
        {
            vertices.remove(vert);
            tamano--;
            cantVertices--;
        }

        void agregarArista(E origen, E dest)
        {
            Vertice<E> * origenP = new Vertice<E>();
            origenP->setValor(origen);
            //TESTING
            //cout << vertices->getElementInPos(0) << endl;

            Vertice<E> * destP = new Vertice<E>();
            destP->setValor(dest);
            //if (vertices->buscar(*origenP) == true)
            //{
                //cout << vertices->getElementInPos(0) << endl;
               // if (vertices->buscar(*destP) == true)
              //  {
                    Arista<E> * ar = new Arista<E>(*origenP, *destP);
                    aristas->append(*ar);
                    cantAristas++;
                    cout << "Se agrego en la lista" << endl;
             //   }
           //     else
          //          cout << "No hay destino valido" << endl;
         //   }
         //   else

        }

        E eliminarArista(Arista<E> ar)
        {
            Vertice<E> origen = ar.getOrigen();
            Vertice<E> dest = ar.getDestino();
            if (vertices.buscar(origen) =! true)
            {
                if (vertices.buscar(dest) =! true)
                {
                    aristas.remove(ar);
                    cantAristas--;
                }
                else
                    return "No hay destino valido";
            }
            else
                return "No hay origen valido";
        }

        LinkedList<Vertice<E> > * obtenerVecinos(Vertice <E> origen)
        {
            Vertice<E> tmpVerD;
            Vertice<E> tmpVerO;
            LinkedList <Vertice<E> > * vecinos = new LinkedList<Vertice<E> >();
            for (int i = 0; i < cantAristas; i++)
            {
                Arista<E> tmpAr = aristas->getElementInPos(i);
                tmpVerD = tmpAr.getDestino();
                tmpVerO = tmpAr.getOrigen();
                if (origen == tmpVerO)
                {
                    vecinos->insert(tmpVerD);
                }
            }
            return vecinos;
        }

        void imprimirListAd()
        {
            //LinkedList<Arista<E> >::imprimirLista(aristas);
            //LinkedList<Vertice<E> >::imprimirLista(vertices);
            for (int i = 0; i < vertices->getSize(); i++)
            {
                //LinkedList<Vertice<E> >::imprimirLista(vertices);
                cout << vertices->getElementInPos(i) << " vecinos: ";
                LinkedList<Vertice<E> > * vecinos = obtenerVecinos(vertices->getElementInPos(i));
                LinkedList<Vertice<E> >::imprimirLista(vecinos);
                cout << endl;
            }
        }

        void llenarGrafo(int dim)
        {
            for (int i = 0; i < vertices->getSize(); i++)
            {
                Vertice <E> tmp = vertices->getElementInPos(i);
                int x = tmp.getValor();
                if (x % dim != 0)
                {
                    agregarArista(x, (x+1));
                    agregarArista((x+1), x);
                }
                if ((x+dim) <= (dim*dim))
                {
                    agregarArista(x, (x+dim));
                    agregarArista((x+dim), x);
                }
            }
        }

    private:
};

#endif // GRAFO_H
