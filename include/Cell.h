#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

template <typename E>
class Cell
{
private:
    Vertice<E> * lastNodePos;
    Arista<E> * edgePos;
    bool node;
public:
    Cell(E initPos)
    {
        lastNodePos = new Vertice<E>(initPos);
        node = true;
    }

    // deep copy NOW UNUSED
    Cell(Cell<E> * pCell)
    {
        lastNodePos = pCell->getLastNodePos();
        Vertice<E> * srcNode = new Vertice<E>(pCell->getEdgePos().getOrigen().getValor());
        Vertice<E> * dstNode = new Vertice<E>(pCell->getEdgePos().getDestino().getValor());
        edgePos = new Arista<E>(*srcNode,*dstNode);
        node = pCell->isNode();
    }

    ~Cell(){}

    Vertice<E> getLastNodePos() const
    {
        return *lastNodePos;
    }

    void setLastNodePos(E dstNode)
    {
        delete lastNodePos;
        lastNodePos = new Vertice<E>(dstNode);
        node = true;
    }

    Arista<E> getEdgePos() const
    {
        return *edgePos;
    }

    void setEdgePos(E dstNode)
    {
        delete edgePos;
        Vertice<int> * dstNodePtr = new Vertice<int>(dstNode);
        edgePos = new Arista<E>(*lastNodePos, *dstNodePtr);
        node = false;
    }

    bool isNode()
    {
        return node;
    }
};

#endif // CELL_H_INCLUDED
