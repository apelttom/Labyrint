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

        E getValor() const
        {
            return valor;
        }

        void setValor(E v)
        {
            valor = v;
        }

        bool getEstado() const
        {
            return visitado;
        }

        void setVisit()
        {
            visitado = true;
        }

        void resetVisit()
        {
            visitado = false;
        }
        virtual ~Vertice() {}

bool operator != (const Vertice& v) const {
    if(valor != v.getValor()){
        return true;
    }else{
        return false;
    }
}

bool operator == (const Vertice& v) const {
    if(valor == v.getValor()){
        return true;
    }else{
        return false;
    }
}

bool operator < (const Vertice& v) const {
  if(valor < v.getValor()){
        return true;
    }else{
        return false;
    }
}

};

template <typename E>
std::ostream& operator<<(std::ostream &strm, const Vertice<E> &v) {
  return strm << "Vertice(" << "Valor = " << v.getValor() << ")";
}


#endif // VERTICE_H
