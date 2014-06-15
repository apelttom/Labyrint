#ifndef GRAPHPRINTER_H_INCLUDED
#define GRAPHPRINTER_H_INCLUDED

#include <winbgim.h>
#include "Grafo.h"

class GraphPrinter
{
private:
public:

    void drawGraph(Grafo<int> * graph)
    {
        initwindow(600,400);
        //setbkColor(0);  /* zero means black */
        //setfillstyle(WHITE);
        //Rectangle(20,20,80,80);
        getch();
        closegraph();
    }
};

#endif // GRAPHPRINTER_H_INCLUDED
