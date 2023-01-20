
#include "list.h"
#include "data.h"

template <class nodetype>
class Node
{
public:
//constructor
    Node(string command = "No input", string annswer = "No input", int points = 0)
    Node(Data newdata)
    {
        this -> data = newdata;
    }
//destructor
    ~Node();
//setters
    void setpNext(Node<nodetype>* newptr)
    {this -> pNext = newwptr}
//getter
Node<nodetype>* getpNext()
{
    return this->pNext;
}

private:
    nodetype data;
    Node<nodetype>* pNext;
};