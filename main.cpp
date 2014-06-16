#include <iostream>
#include "include/Grafo.h"
#include "include/GrafoController.h"
#include "include/GraphDrawer.h"
#include "include/Player.h"

#define UP_ARROW    72
#define DOWN_ARROW  80
#define LEFT_ARROW  75
#define RIGHT_ARROW 77
#define ESC 27

using namespace std;

int main()
{
    cout << "Labyrint application" << endl;

    //prueba grafos
    int dim = 0;
    cout << "Digite la dimension que desea para el laberinto " << endl;
    cin >> dim;

    GrafoController * controller = new GrafoController();
    controller->inicializarGrafo(dim);
    /*g->agregarVertice(1);
    g->agregarVertice(2);
    g->agregarVertice(3);
    g->agregarVertice(4);
    */
    //g->llenarGrafo(dim);
    /*
    g->agregarArista(1, 2);
    g->agregarArista(2, 3);
    g->agregarArista(3, 4);
    g->agregarArista(1,3);
    g->agregarArista(2, 4);
    g->agregarArista(4, 4);
    */

    // graph
    Grafo<int> * graph = controller->getGrafoLleno();
    GraphDrawer *  printer = new GraphDrawer();
    // player
    Player * player = new Player(dim);


    Cell<int> * moveToValidate;
    // keys reader
    int KeyStroke;
    printer->init(dim*2*20);
//    printer->drawGraph(dim, controller->getGrafoLleno(), player); /* draw full graph */
    printer->drawGraph(dim, controller->getLaberinto(), player); /* draw labyrinth */
    while(KeyStroke != ESC){
        switch(KeyStroke){
        case UP_ARROW:
//            cout << "UP" << endl;
            moveToValidate = player->getNextMove(UP);
            if(graph->validatePosition(moveToValidate))
            {
                player->setPosition(moveToValidate);
            }else
            {
                cout << "NOT a valid move" << endl;
            }
            break;
        case DOWN_ARROW:
//            cout << "DOWN" << endl;
            moveToValidate = player->getNextMove(DOWN);
            if(graph->validatePosition(moveToValidate))
            {
                player->setPosition(moveToValidate);
            }else
            {
                cout << "NOT a valid move" << endl;
            }
            break;
        case LEFT_ARROW:
//            cout << "LEFT" << endl;
            moveToValidate = player->getNextMove(LEFT);
            if(graph->validatePosition(moveToValidate))
            {
                player->setPosition(moveToValidate);
            }else
            {
                cout << "NOT a valid move" << endl;
            }
            break;
        case RIGHT_ARROW:
//            cout << "RIGHT" << endl;
            moveToValidate = player->getNextMove(RIGHT);
            if(graph->validatePosition(moveToValidate))
            {
                player->setPosition(moveToValidate);
            }else
            {
                cout << "NOT a valid move" << endl;
            }
            break;
        }
    cleardevice();
    printer->drawGraph(dim, controller->getGrafoLleno(), player); /* draw full graph */
    if(player->getPosition()->getLastNodePos().getValor() == dim*dim)
    {
        cout << "YOU HAVE WON THE GAME." << endl;
        break;
    }
    KeyStroke = _getch();
//    delay(50);
    }

//    printer->drawGraph(dim, controller->getLaberinto()); /* draw labyrint */
    delete graph;
    delete printer;
    delete player;
    delete moveToValidate;
    closegraph();

    //ventana
//    initwindow (600,400);
//    rectangle(0,0,20,20);
//    getch();
    return 0;
}
