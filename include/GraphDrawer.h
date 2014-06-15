#ifndef GRAPHDRAWER_H_INCLUDED
#define GRAPHDRAWER_H_INCLUDED

#include <winbgim.h>
#include "Grafo.h"

const int CELL_SIZE = 20;
const int WHITE = 15;

class GraphDrawer
{
public:
    GraphDrawer(){}
    ~GraphDrawer(){}

	void drawGraph(int dim, Grafo<int> * graph)
	{
	    int sizeOfBoard = dim*2*CELL_SIZE;
	    initwindow(sizeOfBoard,sizeOfBoard);
	    setcolor(WHITE);
	    LinkedList<Vertice<int> > * vertices = graph->getVertices();
        LinkedList<Arista<int> > * edges = graph->getAristas();
        vertices->goToStart();
        edges->goToStart();
        for(int i=0,j=-1; i<vertices->getSize(); i++)
        {
            int leftUpperCornerX = ((i+i)*CELL_SIZE)%sizeOfBoard;
            int rightDownCornerX = (((i+i)*CELL_SIZE)+CELL_SIZE)%sizeOfBoard;
            if(i%dim == 0) j++;
            int leftUpperCornerY = j*2*CELL_SIZE;
            int rightDownCornerY = (j*2*CELL_SIZE)+CELL_SIZE;
            rectangle(leftUpperCornerX,leftUpperCornerY,rightDownCornerX,rightDownCornerY);
            floodfill(leftUpperCornerX+1, leftUpperCornerY+1, 15);
        }
        getch();
        closegraph();
	}
};

#endif // GRAPHPRINTER_H_INCLUDED
