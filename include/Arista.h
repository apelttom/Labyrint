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

        void setOrigen(Vertice<E> ori)
        {
            origen = ori;
        }

        Vertice <E> getOrigen() const
        {
            return origen;
        }

        void setDestino(Vertice<E> vert)
        {
            destino = vert;
        }

        Vertice <E> getDestino() const
        {
            return destino;
        }

        void imprimir()
        {
            cout << origen << " -> " << destino << endl;
        }


        ~Arista() {}
};

template <typename E>
std::ostream& operator<<(std::ostream &strm, const Arista<E> &a) {
  return strm << "Arista(" << "Origen = " << a.getOrigen() << "Destino = " << a.getDestino() << ")";
}

#endif // ARISTA_H
