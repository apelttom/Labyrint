#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"
#include <stdexcept>
using namespace std;

template <typename E>
class LinkedList
{
    private:
        Node<E>* head;
        Node<E>* tail;
        Node<E>* current;
        int size;

        // Método auxiliar que recibe un puntero a un nodo
        // y retorna el elemento anterior en la lista
        Node<E>* searchPrevious(Node<E>* pNode) {
            if (current == head) {
                return NULL;
            }
            Node<E> *res = head;
            while (res->next != current) {
                res = res->next;
            }
            return res;
        }
    public:
        // Inicializa la estructura
        // Inicializa la estructura vacia
        LinkedList()
        {
            head = tail = current = new Node<E>;
            size = 0;
        }

        // Libera la memoria solicitada por la estructura
        ~LinkedList()
        {
            clear();
            delete head;
            delete current;
            delete tail;
        }
        // Inserta un elemento en la posición actual
        void insert(E pElement)
        {
            current -> next = new Node<E>(pElement, current->next);
            if (current == tail)
            {
                tail = current->next;
            }
            size++;
        }
        // Inserta un elemento en el final de la lista
        void append(E pElement)
        {
            tail->next = new Node<E>(pElement, NULL);
            tail = tail->next;
            size++;
        }

        //Busca un elemento en la lista
        bool buscar(E ele)
        {
            Node <E> * tmp;
            for (tmp = head; tmp->next != tail; tmp = tmp->next)
            {
                //cout<< tmp->next->element << endl;
                if (tmp->next->element == ele)
                {
                    return true;
                }
            }
            return false;
        }
        // Elimina el elemento actual, si no hay elemento levanta una excepción
        E remove() throw(runtime_error)
        {
            if (current->next == NULL)
            {
                throw runtime_error("No element to remove");
            }
            Node<E> * tmp = current->next;
            E result = tmp->element;
//            cout << "Removing " << result << endl << "On position: " << getPos() << endl;
            if(tmp == tail) tail = current;
            current->next = tmp->next;
            delete tmp;
            size --;
            return result;
        }
        // Elimina todos los elementos de la lista e inicializa el nodo especial
        void clear()
        {
            current = head;
            while (head != NULL)
            {
                head = head->next;
                delete current;
                current = head;
            }
            head = tail = current = new Node<E>();
            size = 0;
        }
        // Obtiene el valor del elemento actual
        E getElement() throw(runtime_error)
        {
            if (current->next == NULL) {
                throw runtime_error("No element to get.");
            }
            Node <E> * tmp = current -> next;
            return tmp->element;
        }

        E getElementInPos (int pos) throw(runtime_error)
        {
            //CHeck if pos is in range of list
            if ( (pos < 0) ||  (pos > size) )
            {
                throw runtime_error("No element to get.");
            }

            Node <E> * tmp = head;
            for (int i = 0; i < size; i++)
            {
                if (i == pos)
                {
                    return tmp->next->element;
                }
                tmp = tmp->next;
            }
        }

        // Mueve la posición actual al inicio de la lista
        void goToStart()
        {
            current = head;
        }
        // Mueve la posición actual al final de la lista
        void goToEnd()
        {
            current = tail -> previous();
        }
        // Mueve la posición actual al índice indicado en el parámetro
        void goToPos(int nPos) throw(range_error)
        {
            current = head;
            if ((nPos < 0) || (nPos > size))
            {
                throw range_error("Index out of bounds");
            }
            goToStart();
            for (int i = nPos; i > 0; i--)
            {
                current = current -> next;
            }
        }
        // Mueve la posición actual al elemento anterior,
        // no se mueve si ya se encuentra al inicio de la lista
        void previous()
        {
            if (current == head)
            {
                cout << "Ya se encuentra al inicio de la lista" << endl;
            }
            Node <E> * tmp = head;
            while (tmp ->next != current)
            {
                tmp ->next;
            }
            current = tmp;
        }
        // Mueve la posición actual al elemento siguiente,
        // no se mueve si ya se encuentra al final de la lista
        void next()
        {
//            if (current -> next == tail)
//            {
//                cout << "Ya se encuentra al final de la lista" << endl;
//            }
            current = current->next;
        }
        // Obtiene el índice de la posición actual
        int getPos()
        {
            int pos = 0;
            Node <E> * tmp = head;
            while (tmp != current)
            {
                tmp = tmp->next;
                pos++;
            }
            return pos;
        }
        // Obtiene la cantidad de elementos en la lista
        int getSize()
        {
            return size;
        }

        static void imprimirLista(LinkedList* lista)
        {
            lista->goToStart();
            for (int i = 0; lista->getPos() < lista->getSize(); lista->next())
            {
                cout << lista->getElement() << ", ";
            }
        }
};

#endif // LINKEDLIST_H
