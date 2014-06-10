#ifndef NODE_H
#define NODE_H

template <typename E>
class Node
{
    public:
        E element;
        Node* next;
        // tiene que haber un constructor vacio en el tipo de nodo q vaya a ccrear
        Node(E pElement, Node* pNext = NULL) {
            element = pElement;
            next = pNext;
        }
        Node(Node* pNext = NULL) {
            next = pNext;
        }

        E getElement()
        {
            return element;
        }
};

#endif // NODE_H
