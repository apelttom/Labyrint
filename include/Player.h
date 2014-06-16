#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Cell.h"

enum direction { UP, DOWN, LEFT, RIGHT};

class Player
{
private:
    Cell<int> * position;
    bool isInFinish;
    int dimension;

public:
    Player(int pDimension)
    {
        position = new Cell<int>(1);
        isInFinish = false;
        dimension = pDimension;
    }

    ~Player(){}

    Cell<int> * getPosition() const
    {
        return position;
    }

    void setPosition(Cell<int> * dstPos)
    {
        delete position;
        position = dstPos;
    }

    Cell<int> * getNextMove(direction dst)
    {
        int lastNode = position->getLastNodePos().getValor();
        switch(dst){
        case UP:
            if(position->isNode())
            {
                return createNexMove(lastNode-dimension);
            }else
            {
                int nextNode = position->getEdgePos().getDestino().getValor();
                if(lastNode < nextNode)
                {
                    return createNexMove(lastNode);
                }else
                {
                    return createNexMove(nextNode);
                }
            }
            break;
        case DOWN:
            if(position->isNode())
            {
                return createNexMove(lastNode+dimension);
            }else
            {
                int nextNode = position->getEdgePos().getDestino().getValor();
                if(lastNode > nextNode)
                {
                    return createNexMove(lastNode);
                }else
                {
                    return createNexMove(nextNode);
                }
            }
            break;
        case LEFT:
            if(position->isNode())
            {
                return createNexMove(lastNode-1);
            }else
            {
                int nextNode = position->getEdgePos().getDestino().getValor();
                if(lastNode < nextNode)
                {
                    return createNexMove(lastNode);
                }else
                {
                    return createNexMove(nextNode);
                }
            }
            break;
        case RIGHT:
            if(position->isNode())
            {
                return createNexMove(lastNode+1);
            }else
            {
                int nextNode = position->getEdgePos().getDestino().getValor();
                if(lastNode > nextNode)
                {
                    return createNexMove(lastNode);
                }else
                {
                    return createNexMove(nextNode);
                }
            }
        }
        return position;
    }

private:
    Cell<int> * createNexMove(int newNode)
    {
        Cell<int> * nextMove = new Cell<int>(position->getLastNodePos().getValor());

        cout << "Starting position: ";
        if(position->isNode())
        {
            cout << "Node: " << position->getLastNodePos() << endl;
            nextMove->setEdgePos(newNode);
            cout << "New position: " << nextMove->getEdgePos() << endl;
            return nextMove;
        }else
        {
            cout << "Edge: " << position->getEdgePos() << endl;
            nextMove->setLastNodePos(newNode);
            cout << "New position: " << nextMove->getLastNodePos() << endl;
            return nextMove;
        }
    }
};

#endif // PLAYER_H_INCLUDED
