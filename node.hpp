//gaurd code
#ifndef node_h
#define node_h


template <typename nodetype>
class Node
{
public:
//constructor
    Node(nodetype Data)
    {
        this -> data = Data;
        this -> pNext = nullptr;
    }

//destructor
    ~Node()
    {
        //inside of Node Destructor
    }

//setter
    void setdata(nodetype Data)
    {
        this -> data = Data;
    }

    void setpNext(Node<nodetype>* newnode)
    {
        this -> pNext = newnode;
    }

//getter
    Node<nodetype>* getpnext()
    {
        return this -> pNext;
    }
    nodetype getdata()
    {
        return this -> data;
    }

private:
    nodetype data;
    Node<nodetype>* pNext;
};

#endif