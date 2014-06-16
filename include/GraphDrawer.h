#ifndef GRAPHDRAWER_H_INCLUDED
#define GRAPHDRAWER_H_INCLUDED

#include <winbgim.h>
#include "Grafo.h"

const int CELL_SIZE = 20;
const int OFFSET = 9; /* Has to be < CELL_SIZE */
const int COLOR = 15;  // only white works right now
/* BLACK(0), BLUE(1), GREEN(2), CYAN(3), RED(4),
 MAGENTA(5), BROWN(6), LIGHTGRAY(7), DARKGRAY(8), LIGHTBLUE(9), LIGHTGREEN(10),
 LIGHTCYAN(11), LIGHTRED(12), LIGHTMAGENTA(13), YELLOW(14), WHITE(15),*/

class GraphDrawer
{
public:
    GraphDrawer(){}
    ~GraphDrawer(){}

	void drawGraph(int dim, Grafo<int> * graph)
	{
	    int sizeOfBoard = dim*2*CELL_SIZE;
	    initwindow(sizeOfBoard+OFFSET,sizeOfBoard+OFFSET);
	    setcolor(COLOR);
	    LinkedList<Vertice<int> > * vertices = graph->getVertices();
        LinkedList<Arista<int> > * edges = graph->getAristas();
        vertices->goToStart();
        edges->goToStart();

        /* TESTING */
//        edges->goToPos(11);
//        Arista<int> removed = edges->remove();
//        cout << "removed (" << removed.getOrigen().getValor() << ","  << removed.getDestino().getValor() << ")" << endl;
//        removed = edges->remove();
//        cout << "removed (" << removed.getOrigen().getValor() << ","  << removed.getDestino().getValor() << ")" << endl;
//        edges->goToStart();
        /*   END   */

        for(int i=0,j=-1; i<vertices->getSize(); i++)
        {
            // i starts from 0, nodes from 1
            int currVertice = i+1;
            // we want to draw nodes in j rows not in only one row
            if(i%dim == 0) j++;
            // draw node (we always draw node)
            int nodeLeftUpX = ((i+i)*CELL_SIZE+OFFSET)%sizeOfBoard;
            int nodeRightDownX = (((i+i)*CELL_SIZE)+CELL_SIZE+OFFSET)%sizeOfBoard;
            int nodeLeftUpY = j*2*CELL_SIZE+OFFSET;
            int nodeRightDownY = (j*2*CELL_SIZE)+CELL_SIZE+OFFSET;
            rectangle(nodeLeftUpX,nodeLeftUpY,nodeRightDownX,nodeRightDownY);
            floodfill(nodeLeftUpX+1, nodeLeftUpY+1, COLOR);

            // have we already drawed all edges?
            if(edges->getPos() != (edges->getSize()))
            {
                Arista<int> currEdge = edges->getElement();
                Vertice<int> edgeSrc = currEdge.getOrigen();
                Vertice<int> edgeDst = currEdge.getDestino();

                //cout << "This should be the right edge: (" << edgeSrc.getValor() << "," << edgeDst.getValor() << ")" << endl;
                // draw the edge on the right from the node
                if((edgeSrc.getValor()==currVertice)
                    && (edgeDst.getValor()==currVertice+1))
                {
                    int edgeLeftUpX = nodeLeftUpX+CELL_SIZE;
                    int edgeRightDownX = nodeRightDownX+CELL_SIZE;
                    int edgeLeftUpY = nodeLeftUpY;
                    int edgeRightDownY = nodeRightDownY;

                    // draw the rectangle and fill it with white
                    rectangle(edgeLeftUpX,edgeLeftUpY,edgeRightDownX,edgeRightDownY);
                    floodfill(edgeLeftUpX+1, edgeLeftUpY+1, COLOR);

                    // move to the next edge. Edges are duplicated, so we move twice
                    edges->next();
                    edges->next();
                }

                /* it is possible that the last edge was right and now there are
                 * no more edges
                 */
                if(edges->getPos() != (edges->getSize()))
                {
                    currEdge = edges->getElement();
                    edgeSrc = currEdge.getOrigen();
                    edgeDst = currEdge.getDestino();

                    //cout << "This should be the down edge: (" << edgeSrc.getValor() << "," << edgeDst.getValor() << ")" << endl;
                    // Draw the edge down from the node
                    if((edgeSrc.getValor()==currVertice)
                        && (edgeDst.getValor()==(currVertice+dim)))
                    {
                        int edgeLeftUpX = nodeLeftUpX;
                        int edgeRightDownX = nodeRightDownX;
                        int edgeLeftUpY = nodeLeftUpY+CELL_SIZE;
                        int edgeRightDownY = nodeRightDownY+CELL_SIZE;

                        //Draw the rectangle and fill it with white
                        rectangle(edgeLeftUpX,edgeLeftUpY,edgeRightDownX,edgeRightDownY);
                        floodfill(edgeLeftUpX+1, edgeLeftUpY+1, COLOR);

                        // move to the next edge. Edges are duplicated, so we move twice
                        edges->next();
                        edges->next();
                    }
                }
            }
            vertices->next();
        }
        getch();
        closegraph();
	}

    void drawPlayer(float pos)
    {
        //TODO implement player draw
    }

};

#endif // GRAPHPRINTER_H_INCLUDED
