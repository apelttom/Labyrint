#ifndef ARISTA_H
#define ARISTA_H
#include "Vertice.h"

template <typename E>
class Arista
{
    private:
        Vertice origen;
        Vertice destino;

    public:
        Arista() {}
        Arista(Vertice ori, Vertice dest)
        {
            origen = ori;
            destino = dest;
        }

        Vertice setOrigen(Vertice ori)
        {
            origen = ori;
        }

        void getOrigen()
        {
            return destino;
        }

        Vertice setDestino(Vertice vert)
        {
            destino = vert;
        }

        void getDestino()
        {
            return destino;
        }

        void imprimir()
        {
            cout << origen << " -> " << destino endl;
        }

        ~Arista() {}
};

#endif // ARISTA_H
