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

    Cell<int> * getNextMove(direction dst)
    {
        int lastNode = position->getLastNodePos().getValor();
        switch(dst){
        case UP:
            return createNexMove(lastNode-dimension);
        case DOWN:
            return createNexMove(lastNode+dimension);
        case LEFT:
            return createNexMove(lastNode-1);
        case RIGHT:
            return createNexMove(lastNode+1);
        }
//        if(dst == UP) return createNexMove(lastNode-dimension);
//        if(dst == DOWN) return createNexMove(lastNode+dimension);
//        if(dst == LEFT) return createNexMove(lastNode-1);
//        if(dst == RIGHT) return createNexMove(lastNode+1);
        //TODO change for position
        cout << "NO CASE STATEMENT WAS CAUGHT!" << endl;
        return NULL;
    }

private:
    Cell<int> * createNexMove(int newNode)
    {
        Cell<int> * result = new Cell<int>(3);

        cout << "Starting position: ";
        if(position->isNode())
        {
            cout << "Node: " << position->getLastNodePos() << endl;
//            position->setEdgePos(newNode);
            cout << "New position: " << position->getEdgePos() << endl;
            cout << "Next move: " << result->getLastNodePos() << endl;
            //result->setEdgePos(newNode);
            return result;
        }else
        {
            cout << "Edge: " << position->getEdgePos() << endl;
//            position->setLastNodePos(newNode);
            cout << "New position: " << position->getLastNodePos() << endl;
            result->setLastNodePos(newNode);
            return result;
        }
    }
};

#endif // PLAYER_H_INCLUDED
