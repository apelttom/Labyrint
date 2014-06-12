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
        LinkedList <E> * vertices;
        LinkedList <E> * aristas;
        int tamano;
        int cantAristas;

    public:
        Grafo()
        {

        }
        Grafo (int tam)
        {
            vertices = new LinkedList<E>();
            aristas = new LinkedList<E>();
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

        int setTamano(int tam)
        {
            tamano = tam;
        }

        void getCantVe()
        {
            return cantVertices;
        }

        E insertarVertice(Vertice<E> vert)
        {
            vertices.insert(vert);
            tamano ++;
            cantVertices++;
        }

        void agregarVertice (E dato)
        {
            Vertice<int> * vert = new Vertice<E>(dato);
            vertices.append(vert);
            cantVertices++;
            tamano++;
        }

        E eliminarVertice(Vertice<E> vert)
        {
            vertices.remove(vert);
            tamano--;
            cantVertices--;
        }

        void agregarArista(Vertice<E> origen, Vertice<E> dest)
        {
            if (vertices.buscar(origen) =! true)
            {
                if (vertices.buscar(dest) =! true)
                {
                    Arista<E> ar = new Arista<E>(origen, dest);
                    aristas.insert(ar);
                    cantAristas++;
                }
                else
                    cout << "No hay destino valido" << endl;
            }
            else
                cout << "No hay origen valido" << endl;
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

        void obtenerVecinos(Vertice <E> origen)
        {
            Vertice<E> * tmpVerD;
            Vertice<E> * tmpVerO;
            LinkedList <E> * vecinos = new LinkedList<E>();
            for (int i = 0; i < cantAristas; i++)
            {
                Arista<E> * tmpAr = aristas.getElementInPos(i);
                tmpVerD = tmpAr.getDestino();
                tmpVerO = tmpAr.getOrigen();
                if (origen == tmpVerO)
                {
                    vecinos.insert(tmpVerD);
                }
            }
            return imprimirLista(vecinos);
        }

        void imprimirListAd()
        {
            for (int i = 0; i < cantVertices; i++)
            {
                cout << vertices.getElementInPos(i) << obtenerVecinos(vertices.getElementInPos(i));
            }
        }

    private:
};

#endif // GRAFO_H
