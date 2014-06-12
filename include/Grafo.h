#ifndef GRAFO_H
#define GRAFO_H
#include "Vertice.h"
#include "Arista.h"

template <typename E>
class Grafo
{
    private:
        int cantVertices;
        LinkedList <Vertice> * vertices;
        LinkedList <Arista> * aristas;
        int tamano;
        int cantAristas;

    public:
        Grafo() {}
        Grafo (int tam)
        {
            vertices = new LinkedList();
            aristas = new LinkedList();
            tamano = tam;
            cantVertices = 0;
            cantAristas = 0;
        }

        Grafo ()
        {
            vertices = new LinkedList();
            aristas = new LinkedList();
            tamano = 0;
            cantVertices = 0;
            cantAristas = 0;
        }

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

        Vertice insertarVertice(Vertice vert)
        {
            vertices.insert(vert);
            tamano ++;
        }

        Vertice agregarVertice (E dato)
        {
            Vertice vert = new Vertice(dato);
            vertices.insert(vert);
        }

        Vertice eliminarVertice(Vertice vert)
        {
            vertices.remove(vert);
            tamano--;
        }

        Arista agregarArista(Vertice origen, Vertice dest)
        {
            if (vertices.buscar(origen) =! true)
            {
                if (vertices.buscar(dest) =! true)
                {
                    Arista ar = new Arista(origen, dest);
                    aristas.insert(ar);
                    cantAristas++;
                }
                else
                    return "No hay destino valido";
            }
            else
                return "No hay origen valido";
        }

        Arista eliminarArista(Arista ar)
        {
            Vertice origen = ar.getOrigen();
            Vertice dest = ar.getDestino();
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

        void imprimirListAd()
        {
            for (int i = 0; i < cantVertices; i++)
            {

            }
        }

    private:
};

#endif // GRAFO_H
