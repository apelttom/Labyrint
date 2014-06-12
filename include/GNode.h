#ifndef GNODE_H
#define GNODE_H

template <typename E>
template <typename K>
class Gnode
{
    public:
        E element;
        K key;

        Gnode() {}
        virtual ~Gnode() {}


    protected:
    private:
};

#endif // GNODE_H
