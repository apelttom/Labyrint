#ifndef ARISTA_H
#define ARISTA_H
#include <iostream>
#include "Vertice.h"

using namespace std;

template <typename E>
class Arista
{
    private:
        Vertice <E> origen;
        Vertice <E> destino;

    public:

        Arista(Vertice<E> ori, Vertice<E> dest)
        {
            origen = ori;
            destino = dest;
        }

        Arista() {}

        Vertice<E> setOrigen(Vertice<E> ori)
        {
            origen = ori;
        }

        void getOrigen()
        {
            return origen;
        }

        E setDestino(Vertice<E> vert)
        {
            destino = vert;
        }

        void getDestino()
        {
            return destino;
        }

        void imprimir()
        {
            cout << origen << " -> " << destino << endl;
        }


        ~Arista() {}
};

#endif // ARISTA_H
