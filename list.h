
//list.h is the main header used

//gaurd code
#ifndef list_h
#define list_h

//include libraries
#include <iostream>
#include <string>

//using statements
using std::string;

template <typename nodetype>
class List
{
public:
//constructor
    List(Node<nodeype>* pHead)
    {
        this -> pHead = nullptr;
    }
//destructor
    ~List();
//insert
    void insert(nodetype newdata);
//delete
    nodetype depopulate();
//find node
    nodetype find(string command);

private:
//pointer to next in data
    Node<nodetype>* pHead;

};

#endif