#ifndef VERTICE_H
#define VERTICE_H
#include <iostream>

template <typename E>
class Vertice
{
    private:
        E valor;
        bool visitado;

    public:
        Vertice() {}
        Vertice(E v)
        {
            valor = v;
            visitado = false;
        }

        E getValor()
        {
            return valor;
        }

        void setValor(E v)
        {
            valor = v;
        }

        bool getEstado()
        {
            return visitado;
        }
        virtual ~Vertice() {}

};

#endif // VERTICE_H
