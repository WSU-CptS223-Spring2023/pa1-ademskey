
#include "list.h"

template <class nodetype>
class Node
{
public:
//constructor
    //Node(std::string command = "No input", std::string annswer = "No input", int points = 0);
    Node(const nodetype newdata)
    {
        this -> data = newdata;
        pNext = nullptr;
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